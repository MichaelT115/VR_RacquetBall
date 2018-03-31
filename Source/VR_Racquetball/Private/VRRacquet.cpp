// Fill out your copyright notice in the Description page of Project Settings.

#include "VRRacquet.h"

AVRRacquet::AVRRacquet()
{
	// Adds Steam VR Chaperone
	USteamVRChaperoneComponent* Chaperone = this->CreateDefaultSubobject<USteamVRChaperoneComponent>(TEXT("Chaperone"));
	// Add Motion Contoller Component.
	UMotionControllerComponent* MotionController = this->CreateDefaultSubobject<UMotionControllerComponent>(TEXT("Motion Controller"));

	// We only need one motion contoller for the game.
	MotionController->SetTrackingSource(EControllerHand::Left);
}