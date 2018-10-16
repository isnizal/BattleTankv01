// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AimTankComponents.h"
#include "GameFramework/Pawn.h"
#include "PlayerTank.generated.h"

UCLASS()
class BATTLETANKV01_API APlayerTank : public APawn
{
	GENERATED_BODY()

public:

	void AimPlayer(FVector HitLocation) const;

protected:

	UAimTankComponents * AimTankComponents = nullptr;
	

private:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Sets default values for this pawn's properties
	APlayerTank();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	
	
};
