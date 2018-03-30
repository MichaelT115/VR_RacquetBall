// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "EngineGlobals.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "TimerManager.h"
#include "RBVRSettings.h"
#include "GameFramework/GameStateBase.h"
#include "RBVRGameState.generated.h"

/* Enum for each game state. */
UENUM(BlueprintType)
enum class EGameState : uint8
{
	RBVR_InPrep,
	RBVR_InGame,
	RBVR_PostGame
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStateChange, EGameState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameTimeUpdateDelegate, float, GameCountDownTime);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnScoreUpdateDelegate, int, PlayerOneScore, int, PlayerTwoScore);

/**
* Holds the game state
*/
UCLASS()
class VR_RACQUETBALL_API ARBVRGameState : public AGameStateBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void SetGameState(EGameState GameState);

	UFUNCTION()
	void UpdateTime();
	
public:
	// Prepares the game to be played. Finds all the actors needed.
	UFUNCTION(BlueprintCallable)
	void PrepareGame();

	// Start the game.
	UFUNCTION(BlueprintCallable)
	void StartGame();

	// Ends the game.
	UFUNCTION(BlueprintCallable)
	void EndGame();

	// Add to player one's score.
	UFUNCTION(BlueprintCallable)
	void AddPlayerOneScore(int DeltaScore);

	// Add to player two's score.
	UFUNCTION(BlueprintCallable)
	void AddPlayerTwoScore(int DeltaScore);

	// Reset the ball's location.
	UFUNCTION(BlueprintCallable)
	void ResetBall();

	// Holds the the current game state
	UPROPERTY(VisibleAnywhere)
	EGameState GameState = EGameState::RBVR_InPrep;

protected:
	// The actor that holds properties for the game.
	UPROPERTY(VisibleAnywhere)
	ARBVRSettings* SettingsActor = nullptr;

	// Player one's score.
	UPROPERTY(VisibleAnywhere)
	int PlayerOneScore;

	// Player two's score.
	UPROPERTY(VisibleAnywhere)
	int PlayerTwoScore;

	// Handle of the game's timer.
	FTimerHandle GameTimerHandle;

	// The game timer's counter.
	UPROPERTY(VisibleAnywhere)
	float GameCountDownTime;

	// Called when the time is updated.
	UPROPERTY(BlueprintAssignable)
	FOnGameTimeUpdateDelegate OnGameTimeUpdate;

	// Called when the score is updated.
	UPROPERTY(BlueprintAssignable)
	FOnScoreUpdateDelegate OnScoreUpdate;

	// Called when the game state changes.
	UPROPERTY(BlueprintAssignable)
	FOnStateChange OnGameStateChange;
};
