// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ball.h"
#include "ConstructorHelpers.h"
#include "GameFramework/Actor.h"
#include "BallLauncher.generated.h"

/**
* Launches a ball when called.
*/
UCLASS()
class VR_RACQUETBALL_API ABallLauncher : public AActor
{
	GENERATED_BODY()
	
public:	
	ABallLauncher();

	// Launches the ball with the LaunchVelocity from the position of this actor.
	void LaunchBall(ABall* Ball);

	// A mesh representing the position of the launcher.
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh = nullptr;

	// The velocity to launch the ball on launch ball.
	UPROPERTY(EditAnywhere)
	FVector LaunchVelocity;
};
