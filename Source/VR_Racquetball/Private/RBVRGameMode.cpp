// Fill out your copyright notice in the Description page of Project Settings.

#include "RBVRGameMode.h"


ARBVRGameMode::ARBVRGameMode()
	: Super()
{
	GameStateClass = ARBVRGameState::StaticClass();
	DefaultPawnClass = AVRRacquetBallPlayer::StaticClass();
}

void ARBVRGameMode::BeginPlay()
{
	GameState = GetGameState<ARBVRGameState>();
	GameState->PrepareGame();
}