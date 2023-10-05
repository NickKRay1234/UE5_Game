// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SAttributeComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnHealthChanged, AActor*, instigatorActor, USAttributeComponent*, OwningComp, float, NewHealth, float, Delta);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API USAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	USAttributeComponent();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
	float Health;
	
	
	virtual void BeginPlay() override;

public:

	UFUNCTION(BlueprintCallable)
	bool IsAlive() const;

	
	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;
	
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	bool ApplyHealthChange(float Delta);
};
