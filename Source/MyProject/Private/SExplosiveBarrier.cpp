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

void ASExplosiveBarrier::OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	RadialComp->FireImpulse();

	UE_LOG(LogTemp, Log, TEXT("OnActorHit in Explosive Barrel"));

	UE_LOG(LogTemp, Warning, TEXT("OtherActor: %s, at game time: %f"), *GetNameSafe(OtherActor), GetWorld()->TimeSeconds);

	FString CombinedString = FString::Printf(TEXT("Hit at location: %s"), *Hit.ImpactPoint.ToString());
	DrawDebugString(GetWorld(), Hit.ImpactPoint, CombinedString, nullptr, FColor::Green, 2.0f, true);
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

