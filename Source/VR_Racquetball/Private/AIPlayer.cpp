// Fill out your copyright notice in the Description page of Project Settings.

#include "AIPlayer.h"

AAIPlayer::AAIPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	DesiredPosition - this->GetActorLocation();

	USceneComponent* Root = this->CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	RacquetHolder = this->CreateDefaultSubobject<USceneComponent>(TEXT("Racquet Holder"));
	RacquetHolder->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
}

void AAIPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateDesiredPosition();

	UpdatePosition(DeltaTime);
}

void AAIPlayer::UpdateDesiredPosition()
{
	if (TargetBall == nullptr)
	{
		DesiredRacquetHeight = 0;
		DesiredRacquetRotation = 0;
		DesiredPosition = FVector::ZeroVector;

		return;
	}

	// Find the Balls position relative player
	const FVector SelfLocation = this->GetActorLocation();
	const FVector BallLocation = TargetBall->GetActorLocation();

	const float LeftRight = FMath::Sign(BallLocation.Y - SelfLocation.Y);
	const bool IsBallBehindPlayer = BallLocation.X < SelfLocation.X;

	// Set Desired Racquet Height
	DesiredRacquetHeight = BallLocation.Z;

	// Set Desired Racquet Rotation
	DesiredRacquetRotation = IsBallBehindPlayer
		? DesiredRacquetRotation = 0.0f
		: 90.0f * LeftRight;

	// Set Desired Racquet Location
	DesiredPosition.X = XPosition;
	DesiredPosition.Y = BallLocation.Y - RacquetDistance * LeftRight;
}

void AAIPlayer::UpdatePosition(float DeltaTime)
{
	// Update Racquet Height
	FVector RacquetHolderLocation = RacquetHolder->GetComponentLocation();
	FVector TargetRacquetLocation = FVector(RacquetHolderLocation.X, RacquetHolderLocation.Y, DesiredRacquetHeight);

	FVector NewRacquetHolderLocation = FMath::VInterpConstantTo(RacquetHolderLocation, TargetRacquetLocation, DeltaTime, RacquetHeightInterpSpeed);
	NewRacquetHolderLocation.Z = FMath::Clamp<float>(NewRacquetHolderLocation.Z, MinRacquetHeight, MaxRacquetHeight);

	RacquetHolder->SetWorldLocation(NewRacquetHolderLocation, true);

	// Update Rotation
	FRotator CurrentRotation = this->GetActorRotation();
	FRotator TargetRotation = CurrentRotation;
	TargetRotation.Yaw = FMath::FInterpTo(CurrentRotation.Yaw, DesiredRacquetRotation, DeltaTime, RotationInterpSpeed);

	this->SetActorRotation(TargetRotation);

	// Update Position
	FVector VectorToTarget = DesiredPosition - this->GetActorLocation();
	FVector MovementVector = (VectorToTarget.GetSafeNormal() * MovementSpeed * DeltaTime).GetClampedToSize(0, VectorToTarget.Size());
	FVector NewPosition = this->GetActorLocation() + MovementVector;
	NewPosition.X = FMath::Clamp<float>(NewPosition.X, MinPosition.X, MaxPosition.X);
	NewPosition.Y = FMath::Clamp<float>(NewPosition.Y, MinPosition.Y, MaxPosition.Y);
	NewPosition.Z = 0;


	this->SetActorLocation(NewPosition, true);
}