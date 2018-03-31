// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RBVRPlayer.h"
#include "RBVRGameState.h"
#include "VRPlayer.generated.h"

/**
 * The Player typed used by a VR user.
 */
UCLASS()
class VR_RACQUETBALL_API AVRPlayer : public ARBVRPlayer
{
	GENERATED_BODY()

public:
	AVRPlayer();

	// Overrides Register Racquet to make the Racquet properly attach to the Racquet Holder.
	void RegisterRacquet(ARacquet* Racquet) override;

	// Sets up the player input.
	void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	// Starts the game.
	void StartGame();

	UPROPERTY(VisibleAnywhere)
	// Holds the racquet
	USceneComponent* RacquetHolder = nullptr;
};