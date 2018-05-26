// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController_C.generated.h"


UENUM()
enum class EPawnState : uint8
{
    PS_Kuu,
    PS_Puppet
};

class AKaMenPawn_C;
class APuppetPawn_C;
class UKaMenMaskMasterComponent_C;

/**
 * 
 */
UCLASS()
class KAMEN_API AMainPlayerController_C : public APlayerController
{
	GENERATED_BODY()
	
public:
    virtual void BeginPlay() override;
    
    UFUNCTION(BlueprintCallable, Category = "Controlling Pawn")
    AKaMenPawn_C* GetKamenPawn();
    
    UFUNCTION(BlueprintCallable, Category = "Controlling Pawn")
    APuppetPawn_C* GetPuppetPawn();
    
    UFUNCTION(BlueprintCallable, Category = "Controlling Pawn")
    void SetMaskMasterReference(UKaMenMaskMasterComponent_C* MaskMToSet);
    
    UFUNCTION(BlueprintCallable, Category = "Controlling Pawn")
    void SetCurrentPawnTransform(FTransform CurrentTransform);
    
    UFUNCTION(BlueprintCallable, Category = "Controlling Pawn")
    FTransform GetCurrentPawnTransform();
    
    UFUNCTION(BlueprintCallable, Category = "Controlling Pawn")
    void IntendSwitchPawn(APawn* CurrentPawn, FTransform CurrentTransform);
    
//protected:
  //  virtual void SetUpInputComponent (class UInputComponent* PlayerInputComponent) override;
    
private:
    AKaMenPawn_C* KamenPawn = nullptr;
    APuppetPawn_C* PuppetPawn = nullptr;
    UKaMenMaskMasterComponent_C* KamenMaskM = nullptr;
    
    FTransform PlayerCurrentTransform;
    
    UPROPERTY(EditDefaultsOnly, Category = Setup)
    TSubclassOf<AKaMenPawn_C> KuuBlueprint;
    
    UPROPERTY(EditDefaultsOnly, Category = Setup)
    TSubclassOf<APuppetPawn_C> PuppetBlueprint;
    
    EPawnState PawnState = EPawnState::PS_Kuu;
	
	
};
