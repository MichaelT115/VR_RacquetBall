// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RBVRPlayer.h"
#include "ConstructorHelpers.h"
#include "VRPlayer.generated.h"

/**
 * 
 */
UCLASS()
class VR_RACQUETBALL_API AVRPlayer : public ARBVRPlayer
{
	GENERATED_BODY()

public:
	AVRPlayer();

	UChildActorComponent* RacquetChild;
};