// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMesh.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"
class ARBVRPlayer;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerRegisteredDelegate, ARBVRPlayer*, Player);

/**
* The class for the ball.
*/
UCLASS()
class VR_RACQUETBALL_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();

	// Registers a player with the ball. Is called when the ball is hit by a player.
	UFUNCTION(BlueprintCallable)
	void RegisterPlayer(ARBVRPlayer* Player);

	// Called when a player is registered with the ball. Used in blueprint.
	UPROPERTY(BlueprintAssignable)
	FOnPlayerRegisteredDelegate OnPlayerRegistered;

	// Sets the current velocity of the ball
	UFUNCTION(BlueprintCallable)
	void SetBallVelocity(FVector Velocity);
	
	// Gets the velocity of the ball.
	UFUNCTION(BlueprintCallable)
	FVector GetBallVelocity();

	// The player that has previous hit the ball. Set by Register Player.
	UPROPERTY(BlueprintReadWrite)
	ARBVRPlayer* PreviousPlayer = nullptr;

	// The mesh of the ball. The actual mesh is chosen in the blueprint.
	UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent* Mesh = nullptr;
};
