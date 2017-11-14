// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankTurret.h"
#include "Engine/World.h"


void UTankTurret::Rotate(float RelativeSpeed)
{
	//Clamp RelativeSpeed to be between -1.0 and 1.0
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0, 1.0);

	//Move the turret towards the target rotation at a max rotation speed adjusted to frame time
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;\
	SetRelativeRotation(FRotator(0, Rotation, 0));
}

