// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"
#include "TankPlayerController.h"
#include "Engine/World.h"
#include "Public/Tank.h"


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
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (!ControlledTank)
	{
		return;
	}

	if (PlayerTank)
	{
		//Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius);
		auto HitLocation = PlayerTank->GetActorLocation();
		ControlledTank->AimAt(HitLocation);
		ControlledTank->Fire();
	}
	
}
