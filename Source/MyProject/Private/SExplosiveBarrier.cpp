// Fill out your copyright notice in the Description page of Project Settings.


#include "SExplosiveBarrier.h"

ASExplosiveBarrier::ASExplosiveBarrier()
{
	PrimaryActorTick.bCanEverTick = true;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	MeshComponent->SetCollisionProfileName("Barrel");
	RootComponent = MeshComponent;
	RadialComp = CreateDefaultSubobject<URadialForceComponent>("RadialComp");
	RadialComp->Radius = 400.0f;
	RadialComp->SetupAttachment(MeshComponent);
	
}

// Called when the game starts or when spawned
void ASExplosiveBarrier::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASExplosiveBarrier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

