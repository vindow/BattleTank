// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"
#include "TankPlayerController.h"
#include "Engine/World.h"
#include "Public/Tank.h"
#include "Public/TankAimingComponent.h"


ATankAIController::ATankAIController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent))
	{
		return;
	}

	if (ensure(PlayerTank))
	{
		//Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius);
		auto HitLocation = PlayerTank->GetActorLocation();
		AimingComponent->AimAt(HitLocation);
		//ControlledTank->Fire(); TODO: call the AimingComponent to fire when firing is refactored
	}
	
}
