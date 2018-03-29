// Fill out your copyright notice in the Description page of Project Settings.

#include "RBVRGameMode.h"

void ARBVRGameMode::StartPlay()
{
	this->StartGame();
}

void ARBVRGameMode::StartGame()
{
	// Find the ball.
	for (TActorIterator<ABall> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		GameBall = *ActorItr;
		break;
	}
}
