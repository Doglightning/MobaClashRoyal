// Fill out your copyright notice in the Description page of Project Settings.


#include "ABaseUnit.h"

// Sets default values
AABaseUnit::AABaseUnit()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AABaseUnit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AABaseUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AABaseUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

