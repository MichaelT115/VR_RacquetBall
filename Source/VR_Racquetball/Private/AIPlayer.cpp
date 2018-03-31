// Fill out your copyright notice in the Description page of Project Settings.

#include "AIPlayer.h"

AAIPlayer::AAIPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	DesiredPosition - this->GetActorLocation();

	USceneComponent* Root = this->CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	RacquetHolder = this->CreateDefaultSubobject<USceneComponent>(TEXT("Racquet Holder"));
	RacquetHolder->SetupAttachment(GetRootComponent());
}

void AAIPlayer::RegisterRacquet(ARacquet* Racquet)
{
	Super::RegisterRacquet(Racquet);

	// Attach the Racquet to the Racquet Holder Component.
	Racquet->AttachToComponent(RacquetHolder, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}

void AAIPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Update te desired positions of the AI.
	UpdateDesiredPosition();

	// Update the actual position to move towards the desired positions.
	UpdatePosition(DeltaTime);
}

void AAIPlayer::UpdateDesiredPosition()
{
	// Do nothing if there is no ball.
	if (TargetBall == nullptr)
	{
		return;
	}

	// Find the Balls position relative player
	const FVector SelfLocation = this->GetActorLocation();
	const FVector BallLocation = TargetBall->GetActorLocation();

	// Left = -1. Right = 1.
	const float LeftRight = FMath::Sign(BallLocation.Y - SelfLocation.Y);
	// True of the ball is behind the player.
	const bool IsBallBehindPlayer = BallLocation.X < SelfLocation.X;

	// Set Desired Racquet Height
	DesiredRacquetHeight = BallLocation.Z;	// The height is equal to the current height of the ball.

	// Set Desired Racquet Rotation
	DesiredRacquetRotation = IsBallBehindPlayer
		? DesiredRacquetRotation = 0.0f	// If the ball is behing the player, rotate so the paddle is pointing towards the far wall.
		: 90.0f * LeftRight;	// Rotate to the left or right depend on if the ball is left or right.

	// Set Desired Racquet Location
	DesiredPosition.X = XPosition;
	DesiredPosition.Y = BallLocation.Y - RacquetDistance * LeftRight;
}

void AAIPlayer::UpdatePosition(float DeltaTime)
{
	//
	// Update Racquet Height
	//
	FVector RacquetHolderLocation = RacquetHolder->GetComponentLocation();
	FVector TargetRacquetLocation = FVector(RacquetHolderLocation.X, RacquetHolderLocation.Y, DesiredRacquetHeight);

	// Lerp the Racquet Holder towards the target position while staying with in the height bounds.
	FVector NewRacquetHolderLocation = FMath::VInterpConstantTo(RacquetHolderLocation, TargetRacquetLocation, DeltaTime, RacquetHeightInterpSpeed);
	NewRacquetHolderLocation.Z = FMath::Clamp<float>(NewRacquetHolderLocation.Z, MinRacquetHeight, MaxRacquetHeight);

	RacquetHolder->SetWorldLocation(NewRacquetHolderLocation, true);

	//
	// Update Rotation
	//
	FRotator CurrentRotation = this->GetActorRotation();
	FRotator TargetRotation = CurrentRotation;

	// Lerp the rotation of the player towards the desired rotation.
	TargetRotation.Yaw = FMath::FInterpTo(CurrentRotation.Yaw, DesiredRacquetRotation, DeltaTime, RotationInterpSpeed);

	this->SetActorRotation(TargetRotation);

	//
	// Update Position
	//

	// Move towards desired positon.
	FVector VectorToTarget = DesiredPosition - this->GetActorLocation();
	FVector MovementVector = (VectorToTarget.GetSafeNormal() * MovementSpeed * DeltaTime).GetClampedToSize(0, VectorToTarget.Size());
	FVector NewPosition = this->GetActorLocation() + MovementVector;
	NewPosition.X = FMath::Clamp<float>(NewPosition.X, MinPosition.X, MaxPosition.X);
	NewPosition.Y = FMath::Clamp<float>(NewPosition.Y, MinPosition.Y, MaxPosition.Y);
	NewPosition.Z = 0;

	this->SetActorLocation(NewPosition, true);
}