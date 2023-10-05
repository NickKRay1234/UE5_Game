// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "SExplosiveBarrier.generated.h"

UCLASS()
class MYPROJECT_API ASExplosiveBarrier : public AActor
{
	GENERATED_BODY()
	
public:	
	ASExplosiveBarrier();
	virtual void PostInitializeComponents() override;

	UFUNCTION()
	void OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherAtor, UPrimitiveComponent* OtherComp,
	                FVector NormalImpulse, const FHitResult& Hit);

protected:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	URadialForceComponent* RadialComp;
	
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
