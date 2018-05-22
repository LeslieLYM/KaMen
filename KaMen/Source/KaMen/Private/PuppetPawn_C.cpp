// By WorldsEndLover

#include "PuppetPawn_C.h"
#include "KaMenStaticMeshComponent_C.h"
#include "KamenMaskMasterComponent_C.h"
#include "DrawDebugHelpers.h"

APuppetPawn_C::APuppetPawn_C() {
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

void APuppetPawn_C::SetKamenMeshReference(UKaMenStaticMeshComponent_C *KamenMeshToSet) {
    KaMenMesh = KamenMeshToSet;
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
    if (!KaMenMesh) {
        UE_LOG(LogTemp, Error, TEXT("No Kamen Mesh Found (%s)"), *(this->GetClass()->GetName()))
        return;
    }
    
    //Set Motion according to the Direction and Speed
    if (Axis != 0) {
      /*  KaMenMesh->AdjustRotation();
        auto KaMenDirection = KaMenMesh->GetComponentRotation().Yaw;
        auto KaMenRight = KaMenMesh->GetKamenRight();
        
        UE_LOG(LogTemp, Warning, TEXT("Rotation : %f"), KaMenDirection)
        
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
        KaMenMesh->SetKaMenMovment(Axis, PlayerSpeed); */
    }
}
