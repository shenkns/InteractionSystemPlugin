// Copyright shenkns Interaction System Developed With Unreal Engine. All Rights Reserved 2023.

#pragma once

#include "GameFramework/Actor.h"
#include "Interfaces/InteractionInterface.h"

#include "Lever.generated.h"

class UStaticMeshComponent;
class UBoxComponent;
class UInteractionComponent;

UCLASS()
class INTERACTIONSYSTEM_API ALever : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:
	
	ALever();
	
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* LeverMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	UBoxComponent* LeverInteractionTrigger;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	UInteractionComponent* InteractionComponent;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Interaction")
	TArray<AActor*> ConnectedActors;

public:

	virtual void BeginPlay() override;
	
	virtual bool Interact_Implementation() override;
};
