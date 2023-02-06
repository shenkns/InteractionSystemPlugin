// Copyright shenkns Interaction System Developed With Unreal Engine. All Rights Reserved 2023.

#pragma once

#include "UObject/Interface.h"

#include "InteractionInterface.generated.h"

UINTERFACE(MinimalAPI, BlueprintType, Blueprintable)
class UInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

class INTERACTIONSYSTEM_API IInteractionInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, Category = "Interaction")
	bool Interact();
};
