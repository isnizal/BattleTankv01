// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include"PlayerTank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKV01_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	public:
		APlayerTank * GetControlledTank() const;
		virtual void AimPlayerTank();
		virtual void BeginPlay() override;
		bool GetLookVectorHitLocation(FVector WorldDirection, FVector & HitLocation)const;
		virtual void Tick(float deltaTime) override;
		bool GetSightRayHitLocation(FVector& HitLocation) const;
		bool ScreenLocationAndDirection(FVector2D ScreenLocation, FVector &WorldDirection) const;
	private:
		UPROPERTY(EditAnywhere,Category = "Components")
			float CrossHairXLocation = 0.5f;
		UPROPERTY(EditAnywhere, Category = "Components")
			float CrossHairYLocation = 0.33f;
		UPROPERTY(EditAnywhere, Category = "Components")
			float LineTrace = 1000000.0f;

	
	
	
};
