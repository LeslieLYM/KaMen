// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TestingMasterPawn_C.generated.h"

UCLASS()
class KAMEN_API ATestingMasterPawn_C : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATestingMasterPawn_C();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void TestingS();
	
};
