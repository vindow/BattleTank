// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankBarrel.h"




void UTankBarrel::Elevate(float DegreesPerSecond)
{
	//Move the barrel towards the target rotation at a max elevation speed adjusted to frame time
	UE_LOG(LogTemp, Warning, TEXT("Elevate called at %f degrees per second"), DegreesPerSecond)
}