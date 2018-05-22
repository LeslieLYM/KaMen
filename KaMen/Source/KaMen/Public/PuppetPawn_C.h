// By WorldsEndLover

#pragma once

#include "CoreMinimal.h"
#include "TestingMasterPawn_C.h"
#include "PuppetPawn_C.generated.h"

class UKaMenStaticMeshComponent_C;
class UKaMenMaskMasterComponent_C;
class UPuppetStaticMeshComponent_C;

/**
 * 
 */
UCLASS()
class KAMEN_API APuppetPawn_C : public ATestingMasterPawn_C
{
	GENERATED_BODY()
	
public:
    // Sets default values for this pawn's properties
    APuppetPawn_C();
    
    UFUNCTION(BlueprintCallable, Category = "Setup")
    void SetPuppetMeshReference(UPuppetStaticMeshComponent_C* PuppetMeshToSet);
    
    UFUNCTION(BlueprintCallable, Category = "Setup")
    void SetKamenMaskMeshReference(UKaMenMaskMasterComponent_C* KamenMaskMToSet);
 
protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    
    FTimerHandle JumpTraceTimer;
 
public:
 /*   // Called every frame
    virtual void Tick(float DeltaTime) override; */
    
    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
 
    //bool IsGround();
    
    // Passes a player intended movement to the corresponding Unit, pawn mesh
    UFUNCTION(BlueprintCallable, Category = "Player Movements")
    void IntendRight(float Axis);
    
    UFUNCTION(BlueprintCallable, Category = "Player Movements")
    void IntendJump();
    
    /*UFUNCTION(BlueprintCallable, Category = "Player Abilities")
    void UsePrimarySkill();
    */
    void JumpTrace();
    
    UPROPERTY(EditDefaultsOnly, Category = "Player Movements Attributes")
    float PlayerSpeed = 8.f;
    
    UPROPERTY(EditDefaultsOnly, Category = "Player Movements Attributes")
    float PlayerJumpStrength = 5.f;

    
private:
    UPuppetStaticMeshComponent_C* PuppetMesh = nullptr;
    UKaMenMaskMasterComponent_C* KaMenMaskM = nullptr;
    //UKaMenMask1_C* Mask1 = nullptr;
    
    int32 JumpCounter = 0;
    
    float TimerDelay = 0.2f;
	
};
