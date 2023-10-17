#include "SActionComponent.h"

USActionComponent::USActionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void USActionComponent::BeginPlay()
{
	Super::BeginPlay();
	for (TSubclassOf<USAction> ActionClass : DefaultActions)
	{
		AddAction(ActionClass);
	}
}

void USActionComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                      FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FString DebugMsg = GetNameSafe(GetOwner()) + " : " + ActiveGameplayTags.ToStringSimple();
	GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::White, DebugMsg);
}

bool USActionComponent::StartActionByName(AActor* Instigator, FName ActionName)
// Function to start an action based on its name.
{
	for (USAction* Action : Actions) // Iterate through all actions in the component's list of actions.
	{
		if (Action && Action->ActionName == ActionName)
		// Check if the current action is valid and matches the provided action name.
		{
			if (!Action->CanStart(Instigator))
			{
				FString FailedMsg = FString::Printf(TEXT("Failed to run: %s"), *ActionName.ToString());
				GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, FailedMsg);
				continue;
			}
			Action->StartAction(Instigator); // Start the matched action with the provided instigator.
			return true; // Return true since the action was successfully started.
		}
	}
	return false;
}

bool USActionComponent::StopActionByName(AActor* Instigator, FName ActionName)
// Function to stop an action based on its name.
{
	for (USAction* Action : Actions) // Iterate through all actions in the component's list of actions.
	{
		if (Action && Action->ActionName == ActionName)
		// Check if the current action is valid and matches the provided action name.
		{
			if (Action->IsRunning())
			{
				Action->StopAction(Instigator); // Stop the matched action with the provided instigator.
				return true; // Return true since the action was successfully started.	
			}
		}
	}
	return false;
}

// Function to add an action to the component's list of actions.
void USActionComponent::AddAction(TSubclassOf<USAction> ActionClass)
{
	if (!ensure(ActionClass)) return; // Ensure that the provided ActionClass is valid.
	if (USAction* NewAction = NewObject<USAction>(this, ActionClass))
		// Create a new action object of the provided class.
		Actions.Add(NewAction); // Add the newly created action to the component's list of actions.
}
