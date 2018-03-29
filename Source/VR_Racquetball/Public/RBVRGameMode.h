// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "GameFramework/GameModeBase.h"
#include "RBVRGameMode.generated.h"

class ABall;

/**
 * 
 */
UCLASS()
class VR_RACQUETBALL_API ARBVRGameMode : public AGameModeBase
{
	GENERATED_BODY()

	virtual void StartPlay() override;
	
public:
	void StartGame();

	ABall* GameBall;
};
