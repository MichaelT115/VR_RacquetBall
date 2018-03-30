// Fill out your copyright notice in the Description page of Project Settings.

#include "RBVRGameState.h"

void ARBVRGameState::SetGameState(EGameState GameState)
{
	if (this->GameState == GameState)
		return;

	this->GameState = GameState;
	OnGameStateChange.Broadcast(this->GameState);
}

void ARBVRGameState::UpdateTime()
{
	GameCountDownTime -= 1.0f;

	if (GameCountDownTime <= 0) {
		GameCountDownTime = 0;

		this->EndGame();
	}

	OnGameTimeUpdate.Broadcast(GameCountDownTime);
}

void ARBVRGameState::PrepareGame()
{
	SetGameState(EGameState::RBVR_InPrep);

	UWorld* World = GetWorld();
	TArray<AActor*> FoundActors;

	UGameplayStatics::GetAllActorsOfClass(World, AVRPlayer::StaticClass(), FoundActors);
	PlayerOne = FoundActors.Num() != 0 ? Cast<AVRPlayer>(FoundActors[0]) : nullptr;

	UGameplayStatics::GetAllActorsOfClass(World, AAIPlayer::StaticClass(), FoundActors);
	PlayerTwo = FoundActors.Num() != 0 ? Cast<AAIPlayer>(FoundActors[0]) : nullptr;

	UGameplayStatics::GetAllActorsOfClass(World, ABall::StaticClass(), FoundActors);
	Ball = FoundActors.Num() != 0 ? Cast<ABall>(FoundActors[0]) : nullptr;

	UGameplayStatics::GetAllActorsOfClass(World, ABallLauncher::StaticClass(), FoundActors);
	BallLauncher = FoundActors.Num() != 0 ? Cast<ABallLauncher>(FoundActors[0]) : nullptr;

	PlayerTwo->TargetBall = Ball;
}

void ARBVRGameState::StartGame()
{
	this->SetGameState(EGameState::RBVR_InGame);

	GameCountDownTime = 120;

	PlayerOneScore = 0;
	PlayerTwoScore = 0;

	ResetBall();

	GetWorldTimerManager().SetTimer(GameTimerHandle, this, &ARBVRGameState::UpdateTime, 1.0f, true);
}

void ARBVRGameState::EndGame()
{
	SetGameState(EGameState::RBVR_PostGame);

	GetWorldTimerManager().ClearTimer(GameTimerHandle);
}

void ARBVRGameState::AddPlayerOneScore(int DeltaScore)
{
	if (GameState != EGameState::RBVR_InGame)
		return;

	PlayerOneScore += DeltaScore;

	OnScoreUpdate.Broadcast(PlayerOneScore, PlayerTwoScore);
}

void ARBVRGameState::AddPlayerTwoScore(int DeltaScore)
{
	if (GameState != EGameState::RBVR_InGame)
		return;

	PlayerTwoScore += DeltaScore;

	OnScoreUpdate.Broadcast(PlayerOneScore, PlayerTwoScore);
}

void ARBVRGameState::ResetBall()
{
	BallLauncher->LaunchBall(Ball);
	Ball->RegisterPlayer(nullptr);
}