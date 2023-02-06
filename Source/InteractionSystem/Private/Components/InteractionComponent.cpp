// Copyright shenkns Interaction System Developed With Unreal Engine. All Rights Reserved 2023.

#include "Components/InteractionComponent.h"

#include "Interfaces/InteractionInterface.h"

UInteractionComponent::UInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	SetIsReplicatedByDefault(true);
}

bool UInteractionComponent::Interact(AActor* Target)
{
	if(!CanInteractWithActor(Target)) return false;

	return IInteractionInterface::Execute_Interact(Target);
}

bool UInteractionComponent::CanInteractWithActor(AActor* Target) const
{
	return CanInteractWithClass(Target->GetClass());
}

bool UInteractionComponent::CanInteractWithClass(TSubclassOf<AActor> Class) const
{
	if(!Class->ImplementsInterface(UInteractionInterface::StaticClass())) return false;

	for(TSubclassOf<AActor> InteractableClass : InteractableClasses)
	{
		if(Class == InteractableClass || Class->IsChildOf(InteractableClass)) return true;
	}

	return false;
}


void UInteractionComponent::AddInteractableClass(TSubclassOf<AActor> Class)
{
	if(!CanInteractWithClass(Class))
	{
		InteractableClasses.AddUnique(Class);
	}
}

void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UInteractionComponent::ServerInteract_Implementation(AActor* Target)
{
	Interact(Target);
}
