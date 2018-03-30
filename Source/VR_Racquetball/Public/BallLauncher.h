// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ball.h"
#include "ConstructorHelpers.h"
#include "GameFramework/Actor.h"
#include "BallLauncher.generated.h"

UCLASS()
class VR_RACQUETBALL_API ABallLauncher : public AActor
{
	GENERATED_BODY()
	
public:	
	ABallLauncher();

	void LaunchBall(ABall* Ball);
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh = nullptr;

	UPROPERTY(EditAnywhere)
	FVector LaunchVelocity;
};
