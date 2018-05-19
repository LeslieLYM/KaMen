// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController_C.generated.h"

class AKaMenPawn_C;
//class APuppetPawn_C

/**
 * 
 */
UCLASS()
class KAMEN_API AMainPlayerController_C : public APlayerController
{
	GENERATED_BODY()
	
public:
    virtual void BeginPlay() override;
    
//protected:
  //  virtual void SetUpInputComponent (class UInputComponent* PlayerInputComponent) override;
    
private:
    AKaMenPawn_C* KamenPawn;
    //APuppetPawn_C* PuppetPawn;
	
	
};
