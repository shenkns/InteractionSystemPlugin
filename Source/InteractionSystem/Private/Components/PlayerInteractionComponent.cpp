// Copyright shenkns Interaction System Developed With Unreal Engine. All Rights Reserved 2023.

#include "Components/PlayerInteractionComponent.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"

bool UPlayerInteractionComponent::TryInteract()
{
	const APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(this, 0);
	if(!CameraManager) return false;

	const FVector TraceStart = CameraManager->GetCameraLocation();
	const FVector TraceEnd = TraceStart + UKismetMathLibrary::GetForwardVector(CameraManager->GetCameraRotation()) * InteractionTraceDistance;
	FHitResult Hit;

	DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Green, false, 3.f);

	if(!GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, TraceChannel)) return false;

	DrawDebugLine(GetWorld(), TraceStart, Hit.ImpactPoint, FColor::Red, false, 3.f);

	ServerInteract(Hit.GetActor());

	return true;
}
