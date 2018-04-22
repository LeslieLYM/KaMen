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
    auto Velocity = KaMenRight * Direction * Speed * 100;
    auto KamenRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());    
    
    //Move the mesh
    KamenRoot->SetAllPhysicsLinearVelocity(Velocity);
}

void UKaMenStaticMeshComponent_C::AdjustRotation(){
    auto CurrentRotation = GetComponentRotation().Yaw;
    
    //Reset rotation to a comparable value for both sides
    if (CurrentRotation > -180 || (CurrentRotation < 180 && CurrentRotation > 178)) {
        SetRelativeRotation(FRotator(0, 180, 0));
    }
    
    if (CurrentRotation > -1 && CurrentRotation < 0) {
        SetRelativeRotation(FRotator(0, 0, 0));
    }
}

void UKaMenStaticMeshComponent_C::Rotate(float AngleToRotate){
    //Rotate
    AddLocalRotation(FRotator(0, AngleToRotate, 0));
}

void UKaMenStaticMeshComponent_C::Jump(float Speed){
    auto Velocity = GetUpVector() * Speed * 100;
    auto ImpulseLocation = GetComponentLocation();
    auto KamenRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    
    KamenRoot->SetAllPhysicsLinearVelocity(Velocity);
    //KamenRoot->AddImpulseAtLocation(Velocity, ImpulseLocation);
}


