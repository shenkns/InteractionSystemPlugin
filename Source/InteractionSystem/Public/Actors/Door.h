// Copyright shenkns Interaction System Developed With Unreal Engine. All Rights Reserved 2023.

#pragma once

#include "GameFramework/Actor.h"
#include "Interfaces/InteractionInterface.h"

#include "Door.generated.h"

UCLASS()
class INTERACTIONSYSTEM_API ADoor : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:
	
	ADoor();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, Category = "Interaction")
	bool bOpened;

public:
	
	virtual void Tick(float DeltaTime) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual bool Interact_Implementation() override;

protected:
	
	virtual void BeginPlay() override;
};
