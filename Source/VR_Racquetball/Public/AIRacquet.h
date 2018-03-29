// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Racquet.h"
#include "AIRacquet.generated.h"

/**
 * 
 */
UCLASS()
class VR_RACQUETBALL_API AAIRacquet : public ARacquet
{
	GENERATED_BODY()
	
protected:
	void HandleBallCollision(ABall* Ball, const FHitResult& Hit) override;
};
