// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAimingComponent.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Public/TankBarrel.h"
#include "Public/TankTurret.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	
}

void UTankAimingComponent::Initialize(UTankTurret * TurretToSet, UTankBarrel * BarrelToSet)
{
	if (!ensure(BarrelToSet && TurretToSet))
	{
		return;
	}
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
{
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!ensure(Barrel))
	{
		return;
	}
	auto StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	FVector LaunchVelocity = FVector(0);
	//Calculate the launch velocity

	bool bIsAimSolutionFound = UGameplayStatics::SuggestProjectileVelocity(this, LaunchVelocity, StartLocation, HitLocation, LaunchSpeed, false, 0.0f, 0.0f, ESuggestProjVelocityTraceOption::DoNotTrace);
	if (bIsAimSolutionFound)
	{
		//normalize it for just the direction
		auto AimDirection = LaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) const
{
	if (!ensure(Barrel && Turret))
	{
		return;
	}
	//Find difference between current barrel rotation and target rotation
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);
}