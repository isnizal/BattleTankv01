// Fill out your copyright notice in the Description page of Project Settings.

#include"BattleTankv01/Public/PlayerTank.h"


// Sets default values
APlayerTank::APlayerTank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AimTankComponents = CreateDefaultSubobject<UAimTankComponents>(FName("Aim Tank Components"));
}

// Called when the game starts or when spawned
void APlayerTank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
void APlayerTank::AimPlayer(FVector HitLocation) const
{
	AimTankComponents->AimAt(HitLocation);

}

