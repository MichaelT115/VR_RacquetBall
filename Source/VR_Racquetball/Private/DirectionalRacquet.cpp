// Fill out your copyright notice in the Description page of Project Settings.

#include "DirectionalRacquet.h"

void ADirectionalRacquet::HandleBallCollision(ABall* Ball, const FHitResult & Hit)
{
	FVector ImpactVelocity = FVector();

	ImpactVelocity.X = FMath::RandRange(MinVelocity.X, MaxVelocity.X);
	ImpactVelocity.Y = FMath::RandRange(MinVelocity.Y, MaxVelocity.Y);
	ImpactVelocity.Z = FMath::RandRange(MinVelocity.Z, MaxVelocity.Z);

	Ball->SetBallVelocity(ImpactVelocity);
}