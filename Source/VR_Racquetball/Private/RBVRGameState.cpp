// Fill out your copyright notice in the Description page of Project Settings.

#include "RBVRGameState.h"

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
	GameState = EGameState::GS_InPrep;

	UWorld* World = GetWorld();
	TArray<AActor*> FoundActors;

	UGameplayStatics::GetAllActorsOfClass(World, AVRRacquetBallPlayer::StaticClass(), FoundActors);
	PlayerOne = FoundActors.Num() != 0 ? Cast<AVRRacquetBallPlayer>(FoundActors[0]) : nullptr;

	UGameplayStatics::GetAllActorsOfClass(World, AAIRacquetBallPlayer::StaticClass(), FoundActors);
	PlayerTwo = FoundActors.Num() != 0 ? Cast<AAIRacquetBallPlayer>(FoundActors[0]) : nullptr;

	UGameplayStatics::GetAllActorsOfClass(World, ABall::StaticClass(), FoundActors);
	Ball = FoundActors.Num() != 0 ? Cast<ABall>(FoundActors[0]) : nullptr;

	PlayerTwo->TargetBall = Ball;
}

void ARBVRGameState::StartGame()
{
	GameCountDownTime = 120;

	GetWorldTimerManager().SetTimer(GameTimerHandle, this, &ARBVRGameState::UpdateTime, 1.0f, true);
}

void ARBVRGameState::EndGame()
{
	GetWorldTimerManager().ClearTimer(GameTimerHandle);
}

void ARBVRGameState::AddPlayerOneScore(int DeltaScore)
{
	PlayerOneScore += DeltaScore;

	OnScoreUpdate.Broadcast(PlayerOneScore, PlayerTwoScore);
}

void ARBVRGameState::AddPlayerTwoScore(int DeltaScore)
{
	PlayerTwoScore += DeltaScore;

	OnScoreUpdate.Broadcast(PlayerOneScore, PlayerTwoScore);
}
