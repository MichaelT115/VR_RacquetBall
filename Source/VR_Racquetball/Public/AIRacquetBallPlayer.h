// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ball.h"
#include "RacquetBallPlayer.h"
#include "AIRacquetBallPlayer.generated.h"

/**
 * 
 */
UCLASS()
class VR_RACQUETBALL_API AAIRacquetBallPlayer : public ARacquetBallPlayer
{
	GENERATED_BODY()
	
	
public:
	AAIRacquetBallPlayer();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	ABall* TargetBall = nullptr;
	UPROPERTY(VisibleAnywhere)
	USceneComponent* RacquetHolder = nullptr;

	// Where the AI wants to be.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Desired Position")
	float DesiredRacquetHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Desired Position")
	float DesiredRacquetRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Desired Position")
	FVector DesiredPosition;

	UPROPERTY(EditAnywhere)
	float XPosition;

	UPROPERTY(EditAnywhere)
	float RacquetDistance;

	UPROPERTY(EditAnywhere)
	// How fast the player moves around in game.
	float MovementSpeed = 25;

	UPROPERTY(EditAnywhere)
	/* Determines how fast the player can raise the Racquet Ball. */
	float RacquetHeightInterpSpeed = 1000;

	UPROPERTY(EditAnywhere)
	// Determines how fast the player can pivot in place.
	float RotationInterpSpeed = 5;

	UPROPERTY(EditAnywhere)
	float MinRacquetHeight;

	UPROPERTY(EditAnywhere)
	float MaxRacquetHeight;

	UPROPERTY(EditAnywhere)
	FVector MinPosition;

	UPROPERTY(EditAnywhere)
	FVector MaxPosition;

private:
	void UpdateDesiredPosition();
	void UpdatePosition(float DeltaTime);
};
