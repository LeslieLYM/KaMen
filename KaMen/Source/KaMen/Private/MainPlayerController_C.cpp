// Fill out your copyright notice in the Description page of Project Settings.

#include "MainPlayerController_C.h"
#include "KaMenPawn_C.h"
#include "PuppetPawn_C.h"
#include "KamenMaskMasterComponent_C.h"


void AMainPlayerController_C::BeginPlay() {
    Super::BeginPlay();
    
    //SpawnActor
    
    
    FActorSpawnParameters SpawnParams;
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    KamenPawn = GetWorld()->SpawnActor<AKaMenPawn_C>(KuuBlueprint, FVector(-100.f), FRotator(0.f), SpawnParams);
    PuppetPawn = GetWorld()->SpawnActor<APuppetPawn_C>(PuppetBlueprint, FVector(-100.f), FRotator(0.f), SpawnParams);
    
}

AKaMenPawn_C* AMainPlayerController_C::GetKamenPawn() {
    /*if (!KamenPawn) {
        UE_LOG(LogTemp, Warning, TEXT("No Kamen Pawn Found."))
    }*/
    return KamenPawn;
}

APuppetPawn_C* AMainPlayerController_C::GetPuppetPawn() {
    return PuppetPawn;
}

void AMainPlayerController_C::SetCurrentPawnTransform(FTransform CurrentTransform) {
    PlayerCurrentTransform = CurrentTransform;
}

void AMainPlayerController_C::SetMaskMasterReference(UKaMenMaskMasterComponent_C* MaskMToSet) {
    KamenMaskM = MaskMToSet;
}

FTransform AMainPlayerController_C::GetCurrentPawnTransform() {
    
    return PlayerCurrentTransform;
}

void AMainPlayerController_C::IntendSwitchPawn(APawn* CurrentPawn, FTransform CurrentTransform) {
    if (!KamenMaskM) {
        UE_LOG(LogTemp, Error, TEXT("No Mask Master Found."))
        return;
    }
    
    if (!CurrentPawn) {
        UE_LOG(LogTemp, Error, TEXT("No Pawn Found."))
        return;
    }
    
    if (CurrentTransform.GetScale3D() != FVector(1.f)) {
        UE_LOG(LogTemp, Error, TEXT("No Transform Found."))
        return;
    }
    
    APawn* CurrentPawnReceive = CurrentPawn;
    
    //Record this pawn location
    SetCurrentPawnTransform(CurrentTransform);
    
    //Change State of Pawn
    if (Cast<AKaMenPawn_C>(CurrentPawnReceive)) {
        UE_LOG(LogTemp, Warning, TEXT("KamenPawn."))
        PawnState = EPawnState::PS_Puppet;
    } else if (Cast<APuppetPawn_C>(CurrentPawnReceive)) {
        UE_LOG(LogTemp, Warning, TEXT("PuppetPawn."))
        PawnState = EPawnState::PS_Kuu;
    }
    //Unpossess
    this->UnPossess();
    //Destroy this pawn
    CurrentPawn->Destroy();
    //Spawn new pawn
    //Set pawn to previous location location
    FActorSpawnParameters SpawnParams;
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    
    APawn* PawnToSpawn;
    
    //Possess the corresponding pawn to the player controller
    if (PawnState == EPawnState::PS_Kuu) {
        UE_LOG(LogTemp, Warning, TEXT("Spawn KamenPawn."))
        auto SpawnLocation = PlayerCurrentTransform.GetLocation() + FVector(0.f, 0.f, 47.f);
        auto SpawnRotation = PlayerCurrentTransform.GetRotation().Rotator();
        
        PawnToSpawn = GetWorld()->SpawnActor<AKaMenPawn_C>(KuuBlueprint, SpawnLocation, SpawnRotation, SpawnParams);
        this->Possess(PawnToSpawn);
        
        IsJump = true;
    } else if (PawnState == EPawnState::PS_Puppet) {
        UE_LOG(LogTemp, Warning, TEXT("Spawn PuppetPawn."))
        auto SpawnLocation = PlayerCurrentTransform.GetLocation() + FVector(0.f, 0.f, 47.f);
        auto SpawnRotation = PlayerCurrentTransform.GetRotation().Rotator();
        
        PawnToSpawn = GetWorld()->SpawnActor<APuppetPawn_C>(PuppetBlueprint, SpawnLocation, SpawnRotation, SpawnParams);
        this->Possess(PawnToSpawn);
        
        IsJump = true;
    }
    
    
    
    
}
