// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingMasterPawn_C.h"


// Sets default values
ATestingMasterPawn_C::ATestingMasterPawn_C()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestingMasterPawn_C::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestingMasterPawn_C::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATestingMasterPawn_C::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATestingMasterPawn_C::TestingS() {
    UE_LOG(LogTemp, Warning, TEXT("Testing"))
}

