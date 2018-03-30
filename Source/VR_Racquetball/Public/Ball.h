// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMesh.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

class ARBVRPlayer;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerRegisteredDelegate, ARBVRPlayer*, Player);

UCLASS()
class VR_RACQUETBALL_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();

	UFUNCTION(BlueprintCallable)
	void RegisterPlayer(ARBVRPlayer* Player);

	UPROPERTY(BlueprintAssignable)
	FOnPlayerRegisteredDelegate OnPlayerRegistered;

	UFUNCTION(BlueprintCallable)
	void SetBallVelocity(FVector Velocity);

	UFUNCTION(BlueprintCallable)
	FVector GetBallVelocity();

	UPROPERTY(BlueprintReadWrite)
	ARBVRPlayer* PreviousPlayer;

	UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent* Mesh = nullptr;
};
