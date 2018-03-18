// Fill out your copyright notice in the Description page of Project Settings.

#include "KaMenPawn_C.h"


// Sets default values
AKaMenPawn_C::AKaMenPawn_C()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AKaMenPawn_C::BeginPlay()
{
	Super::BeginPlay();
    
    AKaMenPawn->TestingS();
}

// Called every frame
void AKaMenPawn_C::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AKaMenPawn_C::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

