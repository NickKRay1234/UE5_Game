// Fill out your copyright notice in the Description page of Project Settings.


#include "TeleportProjectile.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"


ATeleportProjectile::ATeleportProjectile()
{

}

// Called when the game starts or when spawned
void ATeleportProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void ATeleportProjectile::MakeAfterSpawn()
{
	// Задержка в 5 секунд перед выполнением функции ExecuteAfterDelay
	//GetWorldTimerManager().SetTimer(DelayTimerHandle, this, &ATeleportProjectile::ExecuteAfterDelay, 0.2f, false);
}

// void ATeleportProjectile::ExecuteAfterDelay()
// {
// 	if (ProjectileMovement) // Проверяем на nullptr перед использованием
// 	{
// 		ProjectileMovement->StopMovementImmediately();
// 	}
//
// 	ProjectileLocation = GetActorLocation();
// 	ProjectileRotation = GetActorRotation();
//
// 	if (TeleportStart) // Проверяем на nullptr перед использованием
// 	{
// 		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), TeleportStart, ProjectileLocation, ProjectileRotation);
// 	}
// }


// Called every frame
void ATeleportProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

