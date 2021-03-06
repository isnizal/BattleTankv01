// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include"PlayerTank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKV01_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	private:
		APlayerTank * GetPlayerController() const;
		APlayerTank * GetControlledPlayerTank()const;
		virtual void BeginPlay() override;
		virtual void Tick(float deltaTimeSeconds) override;

	
	
	
};
