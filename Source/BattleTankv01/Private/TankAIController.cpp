// Fill out your copyright notice in the Description page of Project Settings.


#include"BattleTankv01/Public/TankAIController.h"
#include"Runtime/Engine/Classes/Engine/World.h"

APlayerTank * ATankAIController::GetControlledPlayerTank()const
{
	return Cast<APlayerTank>(GetPawn());
}

void ATankAIController::Tick(float deltaTimeSeconds)
{
	Super::Tick(deltaTimeSeconds);
	GetPlayerController()->AimPlayer(GetControlledPlayerTank()->GetActorLocation());
	
}
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto GetAIController = GetPlayerController();
	if (!GetAIController)
	{
		UE_LOG(LogTemp, Warning, TEXT("no ai controller tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller for : %s"), *GetAIController->GetName());
	}
}
APlayerTank * ATankAIController::GetPlayerController() const
{
	auto GetPlayerController = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!GetPlayerController)
	{
		return nullptr;
	}
	return Cast<APlayerTank>(GetPlayerController);
}


