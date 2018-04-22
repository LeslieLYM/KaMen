// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TestingMasterPawn_C.h"
#include "KaMenPawn_C.generated.h"

class UKaMenStaticMeshComponent_C;

UCLASS()
class KAMEN_API AKaMenPawn_C : public ATestingMasterPawn_C
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AKaMenPawn_C();
    
    //Setters
    UFUNCTION(BlueprintCallable, Category = "Setup")
    void SetKamenMeshReference(UKaMenStaticMeshComponent_C* KamenMeshToSet);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    
    FTimerHandle JumpTraceTimer;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
    bool IsGround();
    
    // Passes a player intended movement to the corresponding Unit, pawn mesh
    UFUNCTION(BlueprintCallable, Category = "Player Movements")
    void IntendRight(float Axis);
    
    UFUNCTION(BlueprintCallable, Category = "Player Movements")
    void IntendJump();
    
    void JumpTrace();
    
    UPROPERTY(EditDefaultsOnly, Category = "Player Movements Attributes")
    float PlayerSpeed = 8.f;
    
    UPROPERTY(EditDefaultsOnly, Category = "Player Movements Attributes")
    float PlayerJumpStrength = 5.f;;
    
private:
    UKaMenStaticMeshComponent_C* KaMenMesh = nullptr;
    
    int32 JumpCounter = 0;
    
    float TimerDelay = 0.2f;

    //AKaMenPawn_C* AKaMenPawn;
	
};
