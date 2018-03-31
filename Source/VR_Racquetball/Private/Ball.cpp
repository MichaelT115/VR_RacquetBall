// Fill out your copyright notice in the Description page of Project Settings.

#include "Ball.h"


// Sets default values
ABall::ABall()
{
	PrimaryActorTick.bCanEverTick = false;

	// Add mesh component. The Mesh itself will be chosen in Blueprint.
	Mesh = this->CreateDefaultSubobject<UStaticMeshComponent>("Ball Mesh");
	Mesh->SetAllUseCCD(true);	// Enables Continuous Collision Detection.
	Mesh->SetSimulatePhysics(true);
}

void ABall::RegisterPlayer(ARBVRPlayer* Player)
{
	PreviousPlayer = Player;

	// Broadcast that a new player has been assigned to the ball.
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