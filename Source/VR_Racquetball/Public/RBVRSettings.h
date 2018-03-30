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
* Holds settings for the game.
*/
UCLASS()
class VR_RACQUETBALL_API ARBVRSettings : public AActor
{
	GENERATED_BODY()
	
public:	
	ARBVRSettings();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TotalGameTime = 120.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ARBVRPlayer* PlayerOne = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ARBVRPlayer* PlayerTwo = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ABall* Ball = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ARacquet* PlayerOneRacquet = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ARacquet* PlayerTwoRacquet = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ABallLauncher* BallLauncher = nullptr;
};
