#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "SAction.generated.h"

class UWorld;

UCLASS(Blueprintable)
class MYPROJECT_API USAction : public UObject
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, Category = "Action")
	bool IsRunning() const;
	
	UFUNCTION(BlueprintNativeEvent, Category = "Action")
	bool CanStart(AActor* Instigator);
	
	/* Instigator - who's responsible for starting\stopping this */
	UFUNCTION(BlueprintNativeEvent, Category="Action")
	void StartAction(AActor* Instigator);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Action")
	void StopAction(AActor* Instigator);

	
	/* Action nickname to start/stop without a reference to the object */
	UPROPERTY(EditDefaultsOnly, Category="Action")
	FName ActionName;

	virtual UWorld* GetWorld() const override;

protected:
	
	UFUNCTION(BlueprintCallable, Category = "Action")
	USActionComponent* GetOwningComponent() const;
	
	/* Tags added to owning actor when activated, removed when action stops */
	UPROPERTY(EditDefaultsOnly, Category = "Tags")
	FGameplayTagContainer GrantsTags;

	/* Action can only start if OwningActor has none of these Tags applied */
	UPROPERTY(EditDefaultsOnly, Category = "Tags")
	FGameplayTagContainer BlockedTags;

	bool bIsRunning;
	
};
