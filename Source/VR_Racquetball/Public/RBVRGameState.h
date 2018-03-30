// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Ball.h"
#include "VRPlayer.h"
#include "AIPlayer.h"
#include "BallLauncher.h"
#include "GameFramework/GameStateBase.h"
#include "RBVRGameState.generated.h"

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

UCLASS()
class VR_RACQUETBALL_API ARBVRGameState : public AGameStateBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void SetGameState(EGameState GameState);

	UFUNCTION()
	void UpdateTime();

	UPROPERTY(VisibleAnywhere)
	int PlayerOneScore;
	UPROPERTY(VisibleAnywhere)
	int PlayerTwoScore;	

	FTimerHandle GameTimerHandle;
	UPROPERTY(VisibleAnywhere)
	float GameCountDownTime;
	
public:
	UFUNCTION(BlueprintCallable)
	void AddPlayerOneScore(int DeltaScore);
	UFUNCTION(BlueprintCallable)
	void AddPlayerTwoScore(int DeltaScore);
	UFUNCTION(BlueprintCallable)
	void ResetBall();


	UPROPERTY(VisibleAnywhere)
	EGameState GameState = EGameState::RBVR_InPrep;

	UFUNCTION(BlueprintCallable)
	void PrepareGame();

	UFUNCTION(BlueprintCallable)
	void StartGame();

	UFUNCTION(BlueprintCallable)
	void EndGame();

	UPROPERTY(BlueprintAssignable)
	FOnGameTimeUpdateDelegate OnGameTimeUpdate;

	UPROPERTY(BlueprintAssignable)
	FOnScoreUpdateDelegate OnScoreUpdate;

	UPROPERTY(BlueprintAssignable)
	FOnStateChange OnGameStateChange;

	UPROPERTY(VisibleAnywhere)
	AVRPlayer* PlayerOne = nullptr;

	UPROPERTY(VisibleAnywhere)
	AAIPlayer* PlayerTwo = nullptr;

	UPROPERTY(VisibleAnywhere)
	ABall* Ball;

	UPROPERTY(VisibleAnywhere)
	ABallLauncher* BallLauncher;
};
