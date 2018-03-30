// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MotionControllerComponent.h"
#include "SteamVRChaperoneComponent.h"
#include "Racquet.h"
#include "VRRacquet.generated.h"

/**
 * 
 */
UCLASS()
class VR_RACQUETBALL_API AVRRacquet : public ARacquet
{
	GENERATED_BODY()
	
protected:
	AVRRacquet();
};