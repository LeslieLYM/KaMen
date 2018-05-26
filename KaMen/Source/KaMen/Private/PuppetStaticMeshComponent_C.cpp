// By WorldsEndLover

#include "PuppetStaticMeshComponent_C.h"

FVector UPuppetStaticMeshComponent_C::GetPuppetRight() {
    if (PuppetRight == FVector(0.f)) {
        UE_LOG(LogTemp, Warning, TEXT("No Right."))
        PuppetRight = GetRightVector();
    }
    return PuppetRight;
}

void UPuppetStaticMeshComponent_C::SetPuppetMovment(float Direction, float Speed) {
    auto Velocity = PuppetRight * Direction * Speed * 100;
    auto PuppetRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    
    //Move the mesh
    PuppetRoot->SetAllPhysicsLinearVelocity(Velocity);
}

void UPuppetStaticMeshComponent_C::AdjustRotation() {
    
}

void UPuppetStaticMeshComponent_C::Rotate(float AngleToRotate) {
    
}

void UPuppetStaticMeshComponent_C::Jump(float Speed) {
    auto Velocity = GetUpVector() * Speed * 100;
    auto ImpulseLocation = GetComponentLocation();
    auto PuppetRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    
    PuppetRoot->SetAllPhysicsLinearVelocity(Velocity);
}

