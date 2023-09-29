// Fill out your copyright notice in the Description page of Project Settings.


#include "SExplosiveBarrier.h"

ASExplosiveBarrier::ASExplosiveBarrier()
{
	PrimaryActorTick.bCanEverTick = true;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	MeshComponent->SetSimulatePhysics(true);
	RootComponent = MeshComponent;

	RadialComp = CreateDefaultSubobject<URadialForceComponent>("RadialComp");
	RadialComp->SetupAttachment(MeshComponent);
	RadialComp->SetAutoActivate(false);
	RadialComp->Radius = 750.0f;
	RadialComp->bImpulseVelChange = true;

	RadialComp->AddCollisionChannelToAffect(ECC_WorldDynamic);
}

void ASExplosiveBarrier::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	MeshComponent->OnComponentHit.AddDynamic(this, &ASExplosiveBarrier::OnActorHit);
}

void ASExplosiveBarrier::OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherAtor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	RadialComp->FireImpulse();
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

