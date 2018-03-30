// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Ball.h"
#include "RacquetBallPlayer.h"
#include "AIRacquetBallPlayer.h"
#include "VRRacquetBallPlayer.h"
#include "GameFramework/GameStateBase.h"
#include "RBVRGameState.generated.h"

UENUM(BlueprintType)
enum class EGameState : uint8
{
	GS_InPrep,
	GS_InGame,
	GS_PostGame
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameTimeUpdateDelegate, float, GameCountDownTime);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnScoreUpdateDelegate, int, PlayerOneScore, int, PlayerTwoScore);

UCLASS()
class VR_RACQUETBALL_API ARBVRGameState : public AGameStateBase
{
	GENERATED_BODY()

protected:

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
	UPROPERTY(VisibleAnywhere)
	EGameState GameState = EGameState::GS_InPrep;

	UFUNCTION(BlueprintCallable)
	void PrepareGame();

	UFUNCTION(BlueprintCallable)
	void StartGame();

	UFUNCTION(BlueprintCallable)
	void EndGame();
	
	UFUNCTION(BlueprintCallable)
	void AddPlayerOneScore(int DeltaScore);
	UFUNCTION(BlueprintCallable)
	void AddPlayerTwoScore(int DeltaScore);

	UPROPERTY(BlueprintAssignable)
	FOnGameTimeUpdateDelegate OnGameTimeUpdate;

	UPROPERTY(BlueprintAssignable)
	FOnScoreUpdateDelegate OnScoreUpdate;

	UPROPERTY(VisibleAnywhere)
	AVRRacquetBallPlayer* PlayerOne = nullptr;

	UPROPERTY(VisibleAnywhere)
	AAIRacquetBallPlayer* PlayerTwo = nullptr;

	UPROPERTY(VisibleAnywhere)
	ABall* Ball;
};
