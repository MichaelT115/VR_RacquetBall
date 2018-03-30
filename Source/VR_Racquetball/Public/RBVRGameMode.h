// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "RBVRGameState.h"
#include "VRRacquetBallPlayer.h"
#include "GameFramework/GameModeBase.h"
#include "RBVRGameMode.generated.h"

/**
 * 
 */
UCLASS()
class VR_RACQUETBALL_API ARBVRGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	ARBVRGameMode();

	void BeginPlay() override;

	ARBVRGameState* GameState;
};
