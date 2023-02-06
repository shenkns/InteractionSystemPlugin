// Copyright shenkns Interaction System Developed With Unreal Engine. All Rights Reserved 2023.

#pragma once

#include "Components/ActorComponent.h"

#include "InteractionComponent.generated.h"

UCLASS(ClassGroup = (Interaction), meta = (BlueprintSpawnableComponent))
class INTERACTIONSYSTEM_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	
	UInteractionComponent();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Interaction")
	TArray<TSubclassOf<AActor>> InteractableClasses;

public:

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	bool Interact(AActor* Target);

	UFUNCTION(BlueprintPure, Category = "Interaction")
	bool CanInteractWithActor(AActor* Target) const;

	UFUNCTION(BlueprintPure, Category = "Interaction")
	bool CanInteractWithClass(TSubclassOf<AActor> Class) const;

	UFUNCTION(Server, Reliable)
	void ServerInteract(AActor* Target);

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void AddInteractableClass(TSubclassOf<AActor> Class);

protected:
	
	virtual void BeginPlay() override;
	
};
