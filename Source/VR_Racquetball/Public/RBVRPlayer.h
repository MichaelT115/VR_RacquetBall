// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ball.h"
#include "Racquet.h"
#include "GameFramework/Pawn.h"
#include "RBVRPlayer.generated.h"

UCLASS()
class VR_RACQUETBALL_API ARBVRPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARBVRPlayer();

	UFUNCTION(BlueprintCallable)
	// Registers a Racquet with the player.
	virtual void RegisterRacquet(ARacquet* Racquet);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// The Racquet owned by the player.
	ARacquet* Racquet = nullptr;

	UPROPERTY(EditAnywhere)
	// The ball the player is targetting
	ABall* TargetBall = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// Color of the Player
	FColor PlayerColor;
};
