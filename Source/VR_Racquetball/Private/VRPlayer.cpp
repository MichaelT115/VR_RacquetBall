// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPlayer.h"

AVRPlayer::AVRPlayer()
{
	USceneComponent* Root = this->CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	RacquetHolder = this->CreateDefaultSubobject<USceneComponent>(TEXT("Racquet Holder"));
	RacquetHolder->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
}

void AVRPlayer::RegisterRacquet(ARacquet* Racquet)
{
	Super::RegisterRacquet(Racquet);

	Racquet->AttachToComponent(RacquetHolder, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}

void AVRPlayer::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
	ARBVRGameState* GameState = GetWorld()->GetGameState<ARBVRGameState>();

	InputComponent->BindAction("StartGame", IE_Pressed, this, &AVRPlayer::StartGame);
}

void AVRPlayer::StartGame()
{
	ARBVRGameState* GameState = GetWorld()->GetGameState<ARBVRGameState>();

	if (GameState != nullptr)
	{
		GameState->StartGame();
	}
}
