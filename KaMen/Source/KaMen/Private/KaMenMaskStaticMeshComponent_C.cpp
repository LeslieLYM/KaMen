// By WorldsEndLover

#include "KaMenMaskStaticMeshComponent_C.h"
#include "KaMenStaticMeshComponent_C.h"
#include "KaMenMask1_C.h"
#include "DrawDebugHelpers.h"


void UKaMenMaskStaticMeshComponent_C::BeginPlay(){
    Super::BeginPlay();
    
    //UKaMenMask1_C MaskX = new UKaMenMask1_C();
    
    //Mask1->ShowEquipped();
}

void UKaMenMaskStaticMeshComponent_C::SetKamenMeshReference(UKaMenStaticMeshComponent_C* KamenMeshToSet) {
    KaMenMesh = KamenMeshToSet;
}

void UKaMenMaskStaticMeshComponent_C::SetEquippedMask(EMaskEquip MaskT) {
    MaskEquip = MaskT;
}

bool UKaMenMaskStaticMeshComponent_C::IsHooked(FHitResult& OutHit) {
    //FHitResult OutHit; //Hit Result stored on impact
    
    FVector SweepStart = GetOwner()->GetActorLocation();
    FVector SweepEnd = SweepStart + FVector(0.f, 0.f, 300.f);
    
    TArray<TEnumAsByte<EObjectTypeQuery>> TraceObjectType;
    TraceObjectType.Add(UEngineTypes::ConvertToObjectType(ECC_WorldStatic));
    
    FCollisionShape JumpColSphere = FCollisionShape::MakeSphere(50.f); //Make sphere collision shape
    
    FCollisionQueryParams TraceParameter (FName(TEXT("")), false, GetOwner());
    
    /*DrawDebugSphere(<#const UWorld *InWorld#>, <#const FVector &Center#>, <#float Radius#>, <#int32 Segments#>, <#const FColor &Color#>)
     
     //DrawDebugCapsule(<#const UWorld *InWorld#>, <#const FVector &Center#>, <#float HalfHeight#>, <#float Radius#>, <#const FQuat &Rotation#>, <#const FColor &Color#>) */
    
    DrawDebugSphere(GetWorld(), SweepStart, JumpColSphere.GetSphereRadius(), 2, FColor(255, 0, 0), false, 5.f);
    
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
    
    DrawDebugSphere(GetWorld(), SweepEnd, JumpColSphere.GetSphereRadius(), 2, FColor(255, 0, 0), false, 5.f);
    
    return bIsHit;
}

void UKaMenMaskStaticMeshComponent_C::ThrowString() {
    UE_LOG(LogTemp, Warning, TEXT("Use String."))
    
    
    UE_LOG(LogTemp, Warning, TEXT("Hit : %s"), IsHooked(OutHitResult)? TEXT("True") : TEXT("False"))
    
    //Detect whether string can attach to a hook
    //if IsHooked
    if (IsHooked(OutHitResult)) {
        auto* HitActor = OutHitResult.GetActor();
        
        if (HitActor->ActorHasTag(TEXT("Hook"))) {
            UE_LOG(LogTemp, Warning, TEXT("Has Tag."))
            FVector HitLocation = OutHitResult.ImpactPoint;
            
            UE_LOG(LogTemp, Warning, TEXT("Hit Vector : %s"), *(HitLocation.ToString()))
            DrawDebugPoint(GetWorld(), HitLocation, 3, FColor(255,255,0), false, 5.f);
            
            GetOwner()->AttachToActor(HitActor, FAttachmentTransformRules(EAttachmentRule::KeepWorld, false), FName(""));
        }
        
    }
        //Spawn String
        //Attach pawn offset to the hook,
        //allow hook to move by keys
    //else
        //Set IsFailHook true *For animation*
}

void UKaMenMaskStaticMeshComponent_C::Transform(EMaskEquip CurrentMask) {
    
    if (!KaMenMesh) {
        UE_LOG(LogTemp, Error, TEXT("No Kamen Mesh Found (%s)"), *(this->GetClass()->GetName()))
        return;
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Transformd."))
    if (CurrentMask == EMaskEquip::ME_None) {
        KaMenMesh->SetStaticMesh(UnequipFormMesh);
        UE_LOG(LogTemp, Warning, TEXT("Trans to unequip."))
    } else if (CurrentMask == EMaskEquip::ME_Mask1) {
        KaMenMesh->SetStaticMesh(EquipFormMesh);
        UE_LOG(LogTemp, Warning, TEXT("Trans to equip."))
    }
    
}

/*

 
 
*/
