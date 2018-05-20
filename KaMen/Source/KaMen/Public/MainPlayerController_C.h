// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController_C.generated.h"

class AKaMenPawn_C;
class APuppetPawn_C;

/**
 * 
 */
UCLASS()
class KAMEN_API AMainPlayerController_C : public APlayerController
{
	GENERATED_BODY()
	
public:
    virtual void BeginPlay() override;
    
    UFUNCTION(BlueprintCallable, Category = Setup)
    AKaMenPawn_C* GetKamenPawn();
    
    UFUNCTION(BlueprintCallable, Category = Setup)
    APuppetPawn_C* GetPuppetPawn();
    
//protected:
  //  virtual void SetUpInputComponent (class UInputComponent* PlayerInputComponent) override;
    
private:
    AKaMenPawn_C* KamenPawn = nullptr;
    APuppetPawn_C* PuppetPawn = nullptr;
    
    FTransform PlayerCurrentTransform;
    
    UPROPERTY(EditDefaultsOnly, Category = Setup)
    TSubclassOf<AKaMenPawn_C> KuuBlueprint;
    
    UPROPERTY(EditDefaultsOnly, Category = Setup)
    TSubclassOf<APuppetPawn_C> PuppetBlueprint;
	
	
};
