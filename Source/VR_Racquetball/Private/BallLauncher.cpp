// Fill out your copyright notice in the Description page of Project Settings.

#include "BallLauncher.h"

ABallLauncher::ABallLauncher()
{
	PrimaryActorTick.bCanEverTick = false;

	USceneComponent* Root = this->CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	// Creates mesh that indicates where the launcher is.
	ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
	if (MeshAsset.Succeeded())
	{
		Mesh = this->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

		Mesh->SetStaticMesh(MeshAsset.Object);

		Mesh->SetupAttachment(GetRootComponent());
		Mesh->SetRelativeTransform(FTransform(FRotator(90.0f, 0.0f, 0.0f), FVector::ZeroVector, FVector(0.25f, 0.25f, 0.25f)));
		Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

void ABallLauncher::LaunchBall(ABall* Ball)
{
	Ball->SetActorLocation(this->GetActorLocation(), false, nullptr, ETeleportType::TeleportPhysics);
	Ball->SetBallVelocity(LaunchVelocity);
}