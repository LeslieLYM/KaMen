// Fill out your copyright notice in the Description page of Project Settings.

#include "KaMenPawn_C.h"
#include "KaMenStaticMeshComponent_C.h"


// Sets default values
AKaMenPawn_C::AKaMenPawn_C()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

//Set Kamen Reference
void AKaMenPawn_C::SetKamenMeshReference(UKaMenStaticMeshComponent_C* KamenMeshToSet){
    KaMenMesh = KamenMeshToSet;
}

// Called when the game starts or when spawned
void AKaMenPawn_C::BeginPlay()
{
	Super::BeginPlay();
    
    //AKaMenPawn->TestingS();
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

void AKaMenPawn_C::IntendRight(float Axis){
    if (!KaMenMesh) {
        UE_LOG(LogTemp, Error, TEXT("No Kamen Mesh Found"))
        return;
    }
    
    //Set Motion according to the Direction and Speed
    if (Axis != 0) {
        
        auto KaMenDirection = KaMenMesh->GetComponentRotation().Yaw;
        
        auto KaMenRight = KaMenMesh->GetKamenRight();
        
        //Determine whether character rotates
        if (Axis > 0) {
            if (KaMenDirection < 181 && KaMenDirection > 179) {
                KaMenMesh->Rotate(-180);
            }
        }
        if (Axis < 0){
            if (KaMenDirection < 1 && KaMenDirection > -1) {
                KaMenMesh->Rotate(180);
            }
        }
        
        //Move character
        KaMenMesh->SetKaMenMovment(Axis, PlayerSpeed);
    }
    
}

