// Fill out your copyright notice in the Description page of Project Settings.

#include "Ball.h"


// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = this->CreateDefaultSubobject<UStaticMeshComponent>("Ball Mesh");
	Mesh->SetAllUseCCD(true);
	Mesh->SetSimulatePhysics(true);
}

void ABall::RegisterPlayer(ARBVRPlayer* Player)
{
	PreviousPlayer = Player;

	OnPlayerRegistered.Broadcast(Player);
}

FVector ABall::GetBallVelocity()
{
	return Mesh->GetPhysicsLinearVelocity(NAME_None);
}

void ABall::SetBallVelocity(FVector Velocity)
{
	Mesh->SetPhysicsLinearVelocity(Velocity, false, NAME_None);
}