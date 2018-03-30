// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPlayer.h"

AVRPlayer::AVRPlayer()
{
	RacquetChild = this->CreateDefaultSubobject<UChildActorComponent>("RacquetChild", true);


	static ConstructorHelpers::FObjectFinder<UBlueprint> ItemBlueprint(TEXT("Blueprint'/Game/BP_VRPlayerRacquet.BP_VRPlayerRacquet'"));

}