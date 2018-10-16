// Fill out your copyright notice in the Description page of Project Settings.

#include "Classes/GameFramework/Actor.h"
#include "../Public/AimTankComponents.h"


// Sets default values for this component's properties
UAimTankComponents::UAimTankComponents()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAimTankComponents::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAimTankComponents::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAimTankComponents::AimAt(FVector HitLocation)
{
	auto OurPlayerTank = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s : Hit location at: %s"), *OurPlayerTank, *HitLocation.ToString());
}

