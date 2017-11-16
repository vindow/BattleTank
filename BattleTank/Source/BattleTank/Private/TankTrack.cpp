// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{

	//TODO: Clamp throttle value
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

