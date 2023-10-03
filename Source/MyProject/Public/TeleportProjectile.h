// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Particles/ParticleEmitter.h"
#include "TeleportProjectile.generated.h"

UCLASS()
class MYPROJECT_API ATeleportProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATeleportProjectile();
	void MakeAfterSpawn();
	void ExecuteAfterDelay();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category= "Movement")
	TSubclassOf<UPawnMovementComponent> ProjectileMovement;

	UPROPERTY(EditAnywhere, Category= "Movement")
	FVector ProjectileLocation;

	UPROPERTY(EditAnywhere, Category= "Movement")
	FRotator ProjectileRotation;
	

	UPROPERTY(EditAnywhere, Category= "Effects")
	TSubclassOf<UParticleEmitter> TeleportStart;

	UPROPERTY(EditAnywhere, Category= "Effects")
	TSubclassOf<UParticleEmitter> TeleportEnd;

	

private:
	FTimerHandle DelayTimerHandle;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
