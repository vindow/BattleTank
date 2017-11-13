// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankBarrel.h"
#include "Engine/World.h"




void UTankBarrel::Elevate(float RelativeSpeed)
{
	//Clamp RelativeSpeed to be between -1.0 and 1.0
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0, 1.0);

	//Move the barrel towards the target rotation at a max elevation speed adjusted to frame time
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevation, MaxElevation);

	SetRelativeRotation(FRotator(Elevation, 0, 0));
}