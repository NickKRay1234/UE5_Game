#include "SAction.h"

void USAction::StopAction_Implementation(AActor* Instigator)
{
	UE_LOG(LogTemp, Log, TEXT("Stopped: %s"), *GetNameSafe(this));
}

void USAction::StartAction_Implementation(AActor* Instigator)
{
	UE_LOG(LogTemp, Log, TEXT("Running: %s"), *GetNameSafe(this));
}

UWorld* USAction::GetWorld() const
{
	// Outer is set when creating action via NewObject<T>
	if(const UActorComponent* Comp = Cast<UActorComponent>(GetOuter()))
		return Comp->GetWorld();
	return nullptr;
}
