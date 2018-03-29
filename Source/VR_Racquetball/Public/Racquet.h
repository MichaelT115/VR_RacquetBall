// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ball.h"
#include "GameFramework/Actor.h"
#include "Racquet.generated.h"

UCLASS(abstract)
class VR_RACQUETBALL_API ARacquet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARacquet();

private:
	UFUNCTION()
	void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector MaxVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector MinVelocity;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ARacquetBallPlayer* OwningPlayer = nullptr;

	virtual void HandleBallCollision(ABall* Ball, const FHitResult& Hit);
};
