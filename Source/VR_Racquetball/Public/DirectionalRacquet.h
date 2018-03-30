// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Racquet.h"
#include "DirectionalRacquet.generated.h"

/**
 * A version of the racquet the hits the ball in a specified direction.
 * The ball is set a velocity between the MaxVelocity and MinVelocity
 */
UCLASS()
class VR_RACQUETBALL_API ADirectionalRacquet : public ARacquet
{
	GENERATED_BODY()
	
protected:
	void HandleBallCollision(ABall* Ball, const FHitResult& Hit) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector MaxVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector MinVelocity;
};
