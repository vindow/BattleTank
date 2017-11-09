// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

ATankPlayerController::ATankPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *ControlledTank->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
	
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}
	FVector HitLocation; //Out parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
	}
	//Get world location of linetrace through crosshair
	//If it hits a landscape
		//Tell the controlled tank to aim at this point
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	//Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	//De-project the screen position of the crosshair into a unit vector world position
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Crosshair Direction: %s"), *LookDirection.ToString());
	}

	
	//line-trace along the unit vector direction and see what we hit (up to max range)
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & OutLookDirection) const
{
	FVector CameraLocation; //To be discarded
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraLocation, OutLookDirection);
}
