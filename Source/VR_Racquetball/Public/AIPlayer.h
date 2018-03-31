// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RBVRPlayer.h"
#include "AIPlayer.generated.h"

/**
 * A player with a simple AI.
 */
UCLASS()
class VR_RACQUETBALL_API AAIPlayer : public ARBVRPlayer
{
	GENERATED_BODY()

public:
	AAIPlayer();


private:
	void UpdateDesiredPosition();
	void UpdatePosition(float DeltaTime);

public:
	void RegisterRacquet(ARacquet* Racquet) override;

	virtual void Tick(float DeltaTime) override;

	// Holds the Racquet
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
	// The X-plane this player is locked to.
	float XPosition;

	UPROPERTY(EditAnywhere)
	// The distance to place the racquet from the player 
	float RacquetDistance;

	UPROPERTY(EditAnywhere)
	// How fast the player moves around in game.
	float MovementSpeed;

	UPROPERTY(EditAnywhere)
	/* Determines how fast the player can raise the Racquet Ball. */
	float RacquetHeightInterpSpeed;

	UPROPERTY(EditAnywhere)
	// Determines how fast the player can pivot in place.
	float RotationInterpSpeed;

	UPROPERTY(EditAnywhere)
	float MinRacquetHeight;

	UPROPERTY(EditAnywhere)
	float MaxRacquetHeight;

	UPROPERTY(EditAnywhere)
	FVector MinPosition;

	UPROPERTY(EditAnywhere)
	FVector MaxPosition;
};
