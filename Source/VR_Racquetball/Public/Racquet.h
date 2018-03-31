// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ball.h"
#include "GameFramework/Actor.h"
#include "Racquet.generated.h"
// Forward Declaration of Player
class ARBVRPlayer;

/**
 * Class for the racquet that hits the ball.
 */
UCLASS()
class VR_RACQUETBALL_API ARacquet : public AActor
{
	GENERATED_BODY()
	
public:	
	ARacquet();

	// Set the owner of the racquet.
	UFUNCTION(BlueprintCallable)
	void SetPlayerOwner(ARBVRPlayer* PlayerOwner);

private:
	// Handle hit events.
	UFUNCTION()
	void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

protected:
	// Handle collisions with a ball.
	virtual void HandleBallCollision(ABall* Ball, const FHitResult& Hit);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ARBVRPlayer* PlayerOwner = nullptr;
};