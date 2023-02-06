// Copyright shenkns Interaction System Developed With Unreal Engine. All Rights Reserved 2023.

#include "Actors/Door.h"

#include "Net/UnrealNetwork.h"

ADoor::ADoor()
{
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;
}

void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADoor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	DOREPLIFETIME(ADoor, bOpened);
}

bool ADoor::Interact_Implementation()
{
	bOpened = !bOpened;

	//UE_LOG(LogTemp, Log, TEXT("%s"), FString::FromInt(bOpened));

	return true;
}

void ADoor::BeginPlay()
{
	Super::BeginPlay();
}



