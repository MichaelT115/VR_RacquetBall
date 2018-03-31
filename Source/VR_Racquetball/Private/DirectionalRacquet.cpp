// Fill out your copyright notice in the Description page of Project Settings.

#include "DirectionalRacquet.h"

void ADirectionalRacquet::HandleBallCollision(ABall* Ball, const FHitResult & Hit)
{
	// Creates a random vector between the Min and Max Velocities.
	// All components are determined individually.
	FVector ReboundVelocity = FVector();
	ReboundVelocity.X = FMath::RandRange(MinVelocity.X, MaxVelocity.X);
	ReboundVelocity.Y = FMath::RandRange(MinVelocity.Y, MaxVelocity.Y);
	ReboundVelocity.Z = FMath::RandRange(MinVelocity.Z, MaxVelocity.Z);

	Ball->SetBallVelocity(ReboundVelocity);
}