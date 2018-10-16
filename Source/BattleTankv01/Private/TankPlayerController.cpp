// Fill out your copyright notice in the Description page of Project Settings.

#include"BattleTankv01/Public/TankPlayerController.h"
#include"Classes/Engine/World.h"


APlayerTank * ATankPlayerController::GetControlledTank() const
{
	return Cast<APlayerTank>(GetPawn());
}
//Tick
void ATankPlayerController::Tick(float deltaTime)
{
	//Super
	Super::Tick(deltaTime);
	AimPlayerTank();
	//aim crosshair for tank
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & HitLocation) const
{
	HitLocation = FVector(1.0f);
	//Get and Set Viewport Location in Vector2D
	int32 GetViewportX, GetViewportY;
	GetViewportSize(GetViewportX, GetViewportY);
	auto ScreenLocation = FVector2D(GetViewportX * CrossHairXLocation, GetViewportY *CrossHairYLocation);
	//UE_LOG(LogTemp, Warning, TEXT("ScreenLocation at: %s"), *ScreenLocation.ToString());
	//set the sight ray so it match with the crosshair
	FVector WorldDirection;
	if (ScreenLocationAndDirection( ScreenLocation,  WorldDirection))
	{
		GetLookVectorHitLocation(WorldDirection, HitLocation);
	}
	return true;
}
bool ATankPlayerController::ScreenLocationAndDirection(FVector2D ScreenLocation, FVector &WorldDirection) const
{
	FVector WorldLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		WorldLocation, 
		WorldDirection);
}
bool ATankPlayerController::GetLookVectorHitLocation(FVector WorldDirection, FVector &HitLocation)const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (WorldDirection * LineTrace);

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0.0f);
	return false;
}
void ATankPlayerController::AimPlayerTank() 
{
	
	if (!GetControlledTank()){return;}
	//get player crosshair with the linetrace
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimPlayer(HitLocation);
	}
	//if hit the landscape
		//match into the pointer of the crosshair
}
	

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto GetControlled = GetControlledTank();
	if (!GetControlled)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Player Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Possessing Tank %s"), * GetControlled->GetName());
	}
	
}
