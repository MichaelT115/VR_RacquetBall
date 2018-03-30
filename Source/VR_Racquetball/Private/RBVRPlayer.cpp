// Fill out your copyright notice in the Description page of Project Settings.

#include "RBVRPlayer.h"

ARBVRPlayer::ARBVRPlayer()
{
	PrimaryActorTick.bCanEverTick = false;

	PlayerColor = FColor::Black;
}

void ARBVRPlayer::RegisterRacquet(ARacquet* Racquet)
{
	this->Racquet = Racquet;
	Racquet->SetPlayerOwner(this);
}
