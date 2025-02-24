// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATankPlayerController();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:
	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.3333f;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.0f;

	virtual void SetPawn(APawn* InPawn) override;
	
	//Starts the tank moving the barrel so that it will hit where the crosshair is pointed
	void AimTowardsCrosshair();

	//Returns true if the crosshair is pointed at the landscape. Also returns the location of the hit in the world as an out parameter
	bool GetSightRayHitLocation(FVector &OutHitLocation) const;

	//Returns true if it could get a look direction. Sets the OutLookDirection to unit vector of the direction the crosshair is looking
	bool GetLookDirection(FVector2D ScreenLocation, FVector& OutLookDirection) const;
	bool GetLookVectorHitDirection(FVector LookDirection, FVector& OutHitLocation) const;

	UFUNCTION()
	void OnTankDeath();
};
