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

void APuppetPawn_C::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
}

void APuppetPawn_C::SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) {
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}

bool APuppetPawn_C::IsGround() {
    FHitResult OutHit; //Hit Result stored on impact
    
    FVector SweepStart = GetActorLocation();
    FVector SweepEnd = GetActorLocation() + FVector(0.f, 0.f, -60.f);
    
    TArray<TEnumAsByte<EObjectTypeQuery>> TraceObjectType;
    TraceObjectType.Add(UEngineTypes::ConvertToObjectType(ECC_WorldStatic));
    
    FCollisionShape JumpColSphere = FCollisionShape::MakeSphere(50.f); //Make sphere collision shape
    
    FCollisionQueryParams TraceParameter (FName(TEXT("")), false, GetOwner());
    
    /*DrawDebugSphere(<#const UWorld *InWorld#>, <#const FVector &Center#>, <#float Radius#>, <#int32 Segments#>, <#const FColor &Color#>)
     
     //DrawDebugCapsule(<#const UWorld *InWorld#>, <#const FVector &Center#>, <#float HalfHeight#>, <#float Radius#>, <#const FQuat &Rotation#>, <#const FColor &Color#>) */
    
    DrawDebugSphere(GetWorld(), GetActorLocation(), JumpColSphere.GetSphereRadius(), 2, FColor(255, 0, 0), false, 5.f);
    
    /*bool SweepSingleByObjectType
     (
     struct FHitResult & OutHit,
     const FVector & Start,
     const FVector & End,
     const FQuat & Rot,     FQuat::Identity
     const FCollisionObjectQueryParams & ObjectQueryParams,
     const FCollisionShape & CollisionShape,
     const FCollisionQueryParams & Params
     ) */
    
    //Sphere trace for jumping
    auto bIsHit = GetWorld()->SweepSingleByObjectType(OutHit, SweepStart, SweepEnd, FQuat::Identity, TraceObjectType, JumpColSphere, TraceParameter);
    
    UE_LOG(LogTemp, Warning, TEXT("Hit : %s"), bIsHit ? TEXT("True") : TEXT("False"))
    
    DrawDebugSphere(GetWorld(), SweepEnd, JumpColSphere.GetSphereRadius(), 2, FColor(255, 0, 0), false, 5.f);
    
    return bIsHit;
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
    if (IsGround() && JumpCounter < 1) {
        PuppetMesh->Jump(PlayerJumpStrength);
        JumpCounter++;
        GetWorldTimerManager().SetTimer(JumpTraceTimer, this, &APuppetPawn_C::JumpTrace, TimerDelay, true);
        
    } else if (!IsGround() && JumpCounter < 2) {
        PuppetMesh->Jump(PlayerJumpStrength);
        JumpCounter++;
        GetWorldTimerManager().SetTimer(JumpTraceTimer, this, &APuppetPawn_C::JumpTrace, TimerDelay, true);
        //GetWorldTimerManager().SetTimer(JumpTraceTimer, this, &APuppetPawn_C::JumpTrace, );
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Jump : %s"), *FString::FromInt(JumpCounter))
}

void APuppetPawn_C::UsePrimarySkill() {
    if (!KaMenMaskM) {
        UE_LOG(LogTemp, Error, TEXT("No Kamen Mask Mesh Found (%s)"), *(this->GetClass()->GetName()))
        return;
    }
    auto ABC = KaMenMaskM->GetCurrentMaskState();
    
    if (ABC == EMaskEquip::ME_Mask1) {
        UE_LOG(LogTemp, Warning, TEXT("a Mask 1"))
    }
    KaMenMaskM->ThrowStringMM();
}

void APuppetPawn_C::JumpTrace() {
    UE_LOG(LogTemp, Warning, TEXT("Jump Trace"))
    if (IsGround()) {
        JumpCounter = 0;
        UE_LOG(LogTemp, Warning, TEXT("Jump : %s"), *FString::FromInt(JumpCounter))
        GetWorldTimerManager().ClearTimer(JumpTraceTimer);
    }
}
