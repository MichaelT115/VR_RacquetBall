// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RBVRPlayer.h"
#include "RBVRGameState.h"
#include "VRPlayer.generated.h"

/**
 * 
 */
UCLASS()
class VR_RACQUETBALL_API AVRPlayer : public ARBVRPlayer
{
	GENERATED_BODY()

public:
	AVRPlayer();

	void RegisterRacquet(ARacquet* Racquet) override;

	void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	void StartGame();

	UPROPERTY(VisibleAnywhere)
	USceneComponent* RacquetHolder = nullptr;
};