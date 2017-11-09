// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Public/Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATankPlayerController();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.3333;

	ATank* GetControlledTank() const;

	//Starts the tank moving the barrel so that it will hit where the crosshair is pointed
	void AimTowardsCrosshair();

	//Returns true if the crosshair is pointed at the landscape. Also returns the location of the hit in the world as an out parameter
	bool GetSightRayHitLocation(FVector &OutHitLocation) const;

	//Returns true if it could get a look direction. Sets the OutLookDirection to unit vector of the direction the crosshair is looking
	bool GetLookDirection(FVector2D ScreenLocation, FVector& OutLookDirection) const;
};
