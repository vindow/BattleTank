// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ATankAIController();

	virtual void Tick(float DeltaTime) override;
	
protected:
	void BeginPlay() override;

private:
	//How close the AI tank can get
	float AcceptanceRadius = 3000.0f;
};
