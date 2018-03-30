// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ball.h"
#include "GameFramework/Actor.h"
#include "Racquet.generated.h"

// Forward Declaration of Player
class ARBVRPlayer;

UCLASS()
class VR_RACQUETBALL_API ARacquet : public AActor
{
	GENERATED_BODY()
	
public:	
	ARacquet();

	UFUNCTION(BlueprintCallable)
	void SetPlayerOwner(ARBVRPlayer* PlayerOwner);

private:
	UFUNCTION()
	void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

protected:
	virtual void HandleBallCollision(ABall* Ball, const FHitResult& Hit);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ARBVRPlayer* PlayerOwner = nullptr;
};