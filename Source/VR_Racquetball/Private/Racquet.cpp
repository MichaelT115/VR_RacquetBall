// Fill out your copyright notice in the Description page of Project Settings.

#include "Racquet.h"


// Sets default values
ARacquet::ARacquet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Set what happens when the racquet is hit.
	OnActorHit.AddDynamic(this, &ARacquet::OnHit);
}

void ARacquet::SetPlayerOwner(ARBVRPlayer* PlayerOwner)
{
	this->PlayerOwner = PlayerOwner;
}

void ARacquet::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	ABall* Ball = Cast<ABall>(OtherActor);

	if (Ball != nullptr)
	{
		// Tells the ball what player hit it.
		Ball->RegisterPlayer(this->PlayerOwner);
		// Handle the collision with ball.
		HandleBallCollision(Ball, Hit);
	}
}

void ARacquet::HandleBallCollision(ABall* Ball, const FHitResult& Hit)
{
}