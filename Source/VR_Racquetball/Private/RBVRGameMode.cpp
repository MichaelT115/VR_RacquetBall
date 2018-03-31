// Fill out your copyright notice in the Description page of Project Settings.

#include "RBVRGameMode.h"


ARBVRGameMode::ARBVRGameMode()
	: Super()
{
	GameStateClass = ARBVRGameState::StaticClass();
	DefaultPawnClass = AVRPlayer::StaticClass();
}

void ARBVRGameMode::BeginPlay()
{
	// Put the game in prepare game mode.
	GameState = GetGameState<ARBVRGameState>();
	GameState->PrepareGame();
}