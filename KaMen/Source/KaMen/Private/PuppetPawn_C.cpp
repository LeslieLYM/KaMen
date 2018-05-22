// By WorldsEndLover

#include "PuppetPawn_C.h"
#include "KaMenStaticMeshComponent_C.h"
#include "KamenMaskMasterComponent_C.h"
#include "PuppetStaticMeshComponent_C.h"
#include "DrawDebugHelpers.h"

APuppetPawn_C::APuppetPawn_C() {
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

void APuppetPawn_C::SetPuppetMeshReference(UPuppetStaticMeshComponent_C *PuppetMeshToSet) {
    PuppetMesh = PuppetMeshToSet;
}

void APuppetPawn_C::SetKamenMaskMeshReference(UKaMenMaskMasterComponent_C *KamenMaskMToSet) {
    KaMenMaskM = KamenMaskMToSet;
}

void APuppetPawn_C::BeginPlay() {
    Super::BeginPlay();
}

void APuppetPawn_C::SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) {
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APuppetPawn_C::IntendRight(float Axis) {
    if (!PuppetMesh) {
        UE_LOG(LogTemp, Error, TEXT("No Puppet Mesh Found (%s)"), *(this->GetClass()->GetName()))
        return;
    }
    
    //Set Motion according to the Direction and Speed
    if (Axis != 0) {
        PuppetMesh->AdjustRotation();
        auto PuppetDirection = PuppetMesh->GetComponentRotation().Yaw;
        auto PuppetRight = PuppetMesh->GetPuppetRight();
        
        UE_LOG(LogTemp, Warning, TEXT("Rotation : %f"), PuppetDirection)
        
        //Determine whether character rotates
        if (Axis > 0) {
            if (PuppetDirection < 181 && PuppetDirection > 179) {
                PuppetMesh->Rotate(-180);
            }
        }
        if (Axis < 0){
            if (PuppetDirection < 1 && PuppetDirection > -1) {
                PuppetMesh->Rotate(180);
            }
        }
        
        //Move character
        PuppetMesh->SetPuppetMovment(Axis, PlayerSpeed);
    }
}

void APuppetPawn_C::IntendJump() {
    
}

void APuppetPawn_C::JumpTrace() {
    
}
