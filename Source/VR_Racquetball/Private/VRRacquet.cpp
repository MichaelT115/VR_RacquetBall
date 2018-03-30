// Fill out your copyright notice in the Description page of Project Settings.

#include "VRRacquet.h"

AVRRacquet::AVRRacquet()
{
	USteamVRChaperoneComponent* Chaperone = this->CreateDefaultSubobject<USteamVRChaperoneComponent>(TEXT("Chaperone"));
	UMotionControllerComponent* MotionController = this->CreateDefaultSubobject<UMotionControllerComponent>(TEXT("Motion Controller"));

	MotionController->SetTrackingSource(EControllerHand::Left);
}