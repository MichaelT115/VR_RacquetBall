// Fill out your copyright notice in the Description page of Project Settings.

#include "BallLauncher.h"

// Sets default values
ABallLauncher::ABallLauncher()
{
	PrimaryActorTick.bCanEverTick = false;

	USceneComponent* Root = this->CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	UStaticMeshComponent* Mesh = this->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));

	if (MeshAsset.Succeeded())
		Mesh->SetStaticMesh(MeshAsset.Object);

	Mesh->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
	Mesh->SetRelativeTransform(FTransform(FRotator(90.0f, 0.0f, 0.0f), FVector::ZeroVector, FVector(0.25f, 0.25f, 0.25f)));
}

void ABallLauncher::LaunchBall(ABall* Ball)
{
	Ball->SetActorLocation(this->GetActorLocation(), false, nullptr, ETeleportType::TeleportPhysics);
	Ball->SetBallVelocity(LaunchVelocity);
}