// Fill out your copyright notice in the Description page of Project Settings.

#include "KaMenPawn_C.h"
#include "KaMenStaticMeshComponent_C.h"
#include "KaMenMaskStaticMeshComponent_C.h"
#include "DrawDebugHelpers.h"


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

void AKaMenPawn_C::SetKamenMaskMeshReference(UKaMenMaskStaticMeshComponent_C* KamenMaskToSet) {
    KaMenMask = KamenMaskToSet;
}

// Called when the game starts or when spawned
void AKaMenPawn_C::BeginPlay()
{
	Super::BeginPlay();

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

bool AKaMenPawn_C::IsGround(){
    FHitResult OutHit; //Hit Result stored on impact
    
    FVector SweepStart = GetActorLocation();
    FVector SweepEnd = GetActorLocation() + FVector(0.f, 0.f, -10.f);
    
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

void AKaMenPawn_C::IntendRight(float Axis){
    if (!KaMenMesh) {
        UE_LOG(LogTemp, Error, TEXT("No Kamen Mesh Found (%s)"), *(this->GetClass()->GetName()))
        return;
    }
    
    //Set Motion according to the Direction and Speed
    if (Axis != 0) {
        KaMenMesh->AdjustRotation();
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
        KaMenMesh->SetKaMenMovment(Axis, PlayerSpeed);
    }
}

void AKaMenPawn_C::IntendJump(){
    if (IsGround() && JumpCounter < 1) {
        KaMenMesh->Jump(PlayerJumpStrength);
        JumpCounter++;
        GetWorldTimerManager().SetTimer(JumpTraceTimer, this, &AKaMenPawn_C::JumpTrace, TimerDelay, true);
        
    } else if (!IsGround() && JumpCounter < 2) {
        KaMenMesh->Jump(PlayerJumpStrength);
        JumpCounter++;
        GetWorldTimerManager().SetTimer(JumpTraceTimer, this, &AKaMenPawn_C::JumpTrace, TimerDelay, true);
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Jump : %s"), *FString::FromInt(JumpCounter))
}

void AKaMenPawn_C::UsePrimarySkill() {
    //auto
}

void AKaMenPawn_C::JumpTrace(){
    UE_LOG(LogTemp, Warning, TEXT("Jump Trace    asdkfj"))
    if (IsGround()) {
        JumpCounter = 0;
        UE_LOG(LogTemp, Warning, TEXT("Jump : %s"), *FString::FromInt(JumpCounter))
        GetWorldTimerManager().ClearTimer(JumpTraceTimer);
    }
}


