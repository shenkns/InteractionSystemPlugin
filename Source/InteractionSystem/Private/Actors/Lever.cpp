// Copyright shenkns Interaction System Developed With Unreal Engine. All Rights Reserved 2023.

#include "Actors/Lever.h"

#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/InteractionComponent.h"

ALever::ALever()
{
	PrimaryActorTick.bCanEverTick = false;

	LeverMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("LeverMesh"));
	SetRootComponent(LeverMesh);

	LeverInteractionTrigger = CreateDefaultSubobject<UBoxComponent>(FName("LeverInteractionTrigger"));
	LeverInteractionTrigger->SetupAttachment(LeverMesh);

	InteractionComponent = CreateDefaultSubobject<UInteractionComponent>(FName("InteractionComponent"));
}

void ALever::BeginPlay()
{
	Super::BeginPlay();

	for(const AActor* Actor : ConnectedActors)
	{
		InteractionComponent->AddInteractableClass(Actor->GetClass());
	}
}

bool ALever::Interact_Implementation()
{
	bool bSuccess = true;
	
	for(AActor* Actor : ConnectedActors)
	{
		bSuccess &= InteractionComponent->Interact(Actor);
	}

	return bSuccess;
}
