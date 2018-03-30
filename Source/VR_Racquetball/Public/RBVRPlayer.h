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
	virtual void RegisterRacquet(ARacquet* Racquet);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ARacquet* Racquet = nullptr;

	UPROPERTY(EditAnywhere)
	ABall* TargetBall = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FColor PlayerColor;
};
