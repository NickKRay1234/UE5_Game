// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SPowerupActor.h"
#include "SPowerup_HealthPotion.generated.h"

class UStaticMeshComponent;

UCLASS()
class MYPROJECT_API ASPowerup_HealthPotion : public ASPowerupActor
{
	GENERATED_BODY()
protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComp;

public:
	void Interact_Implementation(APawn* Instigator) override;
	ASPowerup_HealthPotion();
};