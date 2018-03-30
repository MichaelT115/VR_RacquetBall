// Fill out your copyright notice in the Description page of Project Settings.

#include "RBVRGameState.h"

void ARBVRGameState::SetGameState(EGameState GameState)
{
	// Do nothing if the game is already in this state.
	if (this->GameState == GameState)
		return;

	this->GameState = GameState;

	// Broadcast new game state.
	OnGameStateChange.Broadcast(this->GameState);
}

void ARBVRGameState::UpdateTime()
{
	// Decrease time by one second.
	GameCountDownTime -= 1.0f;

	// If time is up, end the game.
	if (GameCountDownTime <= 0) {
		GameCountDownTime = 0;

		this->EndGame();
	}

	// Broadcast new game time.
	OnGameTimeUpdate.Broadcast(GameCountDownTime);
}

void ARBVRGameState::PrepareGame()
{
	UWorld* World = GetWorld();
	TArray<AActor*> FoundActors;

	UGameplayStatics::GetAllActorsOfClass(World, ARBVRSettings::StaticClass(), FoundActors);
	SettingsActor = FoundActors.Num() != 0 ? Cast<ARBVRSettings>(FoundActors[0]) : nullptr;

	if (SettingsActor == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Settings Actor Not Found."));
		return;
	}

	// Register Racquets to players.
	SettingsActor->PlayerOne->RegisterRacquet(SettingsActor->PlayerOneRacquet);
	SettingsActor->PlayerTwo->RegisterRacquet(SettingsActor->PlayerTwoRacquet);

	SetGameState(EGameState::RBVR_InPrep);
}

void ARBVRGameState::StartGame()
{
	this->SetGameState(EGameState::RBVR_InGame);

	GameCountDownTime = SettingsActor->TotalGameTime;

	PlayerOneScore = 0;
	PlayerTwoScore = 0;
	OnScoreUpdate.Broadcast(PlayerOneScore, PlayerTwoScore);

	// Reset the ball.
	ResetBall();

	// Start new game timer. Updates Every Second.
	GetWorldTimerManager().SetTimer(GameTimerHandle, this, &ARBVRGameState::UpdateTime, 1.0f, true);
}

void ARBVRGameState::EndGame()
{
	SetGameState(EGameState::RBVR_PostGame);

	// Clear the game timer
	GetWorldTimerManager().ClearTimer(GameTimerHandle);
}

void ARBVRGameState::AddPlayerOneScore(int DeltaScore)
{
	// Make sure we're in game.
	if (GameState != EGameState::RBVR_InGame)
		return;

	// Update Player One's Score
	PlayerOneScore += DeltaScore;

	// Dispatch On Score Updated
	OnScoreUpdate.Broadcast(PlayerOneScore, PlayerTwoScore);
}

void ARBVRGameState::AddPlayerTwoScore(int DeltaScore)
{
	// Make sure we're in game.
	if (GameState != EGameState::RBVR_InGame)
		return;

	// Update Player Two's Score
	PlayerTwoScore += DeltaScore;

	// Dispatch On Score Updated
	OnScoreUpdate.Broadcast(PlayerOneScore, PlayerTwoScore);
}

void ARBVRGameState::ResetBall()
{
	// Get the Ball and Ball Launcher from the settings actor
	ABall* Ball = SettingsActor->Ball;
	ABallLauncher* BallLauncher = SettingsActor->BallLauncher;

	// Set the player associated with the ball to null.
	Ball->RegisterPlayer(nullptr);

	// Launch the ball.
	BallLauncher->LaunchBall(Ball);
}