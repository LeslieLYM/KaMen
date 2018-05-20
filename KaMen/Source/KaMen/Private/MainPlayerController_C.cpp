// Fill out your copyright notice in the Description page of Project Settings.

#include "MainPlayerController_C.h"
#include "KaMenPawn_C.h"
#include "PuppetPawn_C.h"


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

