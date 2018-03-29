// Fill out your copyright notice in the Description page of Project Settings.

#include "Ball.h"


// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = this->CreateDefaultSubobject<UStaticMeshComponent>("Ball Mesh");
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABall::RegisterPlayer(ARacquetBallPlayer* Player)
{
	PreviousPlayer = Player;

	OnPlayerRegistered.Broadcast(Player);
}

void ABall::SetVelocity(FVector Velocity)
{
	Mesh->SetPhysicsLinearVelocity(Velocity, false, NAME_None);
}

