// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RBVRPlayer.h"
#include "Ball.h"
#include "Racquet.h"
#include "BallLauncher.h"
#include "GameFramework/Actor.h"
#include "RBVRSettings.generated.h"

/**
* Actor in the scene that holds settings for the game.
*/
UCLASS()
class VR_RACQUETBALL_API ARBVRSettings : public AActor
{
	GENERATED_BODY()
	
public:	
	ARBVRSettings();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// How long the game lasts.
	float TotalGameTime = 120.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// The player that is Player One.
	ARBVRPlayer* PlayerOne = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// The player that is Player Two
	ARBVRPlayer* PlayerTwo = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// The Ball used in the game.
	ABall* Ball = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// The racquet held by Player One.
	ARacquet* PlayerOneRacquet = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// The racquet held by Player Two.
	ARacquet* PlayerTwoRacquet = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// The launcher used to launch the Ball.
	ABallLauncher* BallLauncher = nullptr;
};
