// By WorldsEndLover

#include "KaMenStaticMeshComponent_C.h"

//Get right vector from Kamen
FVector UKaMenStaticMeshComponent_C::GetKamenRight(){
    if (KaMenRight == FVector(0.f)) {
        UE_LOG(LogTemp, Warning, TEXT("No Right."))
        KaMenRight = GetRightVector();
    }
    return KaMenRight;
}

void UKaMenStaticMeshComponent_C::SetKaMenMovment(float Direction, float Speed){
    auto velocity = KaMenRight * Direction * Speed;
    auto KamenRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());    
    
    //Move the mesh
    KamenRoot->SetAllPhysicsLinearVelocity(velocity);
}

void UKaMenStaticMeshComponent_C::Rotate(float AngleToRotate){
    //Rotate
    AddLocalRotation(FRotator(0, AngleToRotate, 0));
    
    auto CurrentRotation = GetComponentRotation().Yaw;
    
    //Reset rotation to a comparable value for both sides
    if (CurrentRotation < -179) {
        SetRelativeRotation(FRotator(0, 180, 0));
    }
    
    if (CurrentRotation > -1 && CurrentRotation < 0) {
        SetRelativeRotation(FRotator(0, 0, 0));
    }
}


