// By WorldsEndLover

#include "KaMenMaskMasterComponent_C.h"
#include "KaMenStaticMeshComponent_C.h"
#include "KaMenMaskStaticMeshComponent_C.h"
#include "DrawDebugHelpers.h"



// Sets default values for this component's properties
UKaMenMaskMasterComponent_C::UKaMenMaskMasterComponent_C()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UKaMenMaskMasterComponent_C::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UKaMenMaskMasterComponent_C::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UKaMenMaskMasterComponent_C::SetMaskStaticMeshReference(UKaMenMaskStaticMeshComponent_C* KamenMaskToSet, UKaMenStaticMeshComponent_C* KamenMeshToSet){
    KaMenMaskMesh = KamenMaskToSet;
    KaMenMaskMesh->SetKamenMeshReference(KamenMeshToSet);
}

EMaskEquip UKaMenMaskMasterComponent_C::GetCurrentMaskState() {
    
    return CurrentMaskState;
}



void UKaMenMaskMasterComponent_C::CheckMask(int32 MaskNum) {
    //Check which mask state is the player currently have
    switch (MaskNum) {
        case 1:
            UE_LOG(LogTemp, Warning, TEXT("%s"), *FString::FromInt(MaskNum))
            
            if (CurrentMaskState == EMaskEquip::ME_None) {
                UE_LOG(LogTemp, Warning, TEXT("Current Mask change to 1"))
                CurrentMaskState = EMaskEquip::ME_Mask1;
                CurrentState = 1;

            } else if (CurrentMaskState == EMaskEquip::ME_Mask1) {
                UE_LOG(LogTemp, Warning, TEXT("Current Mask change to 0"))
                CurrentMaskState = EMaskEquip::ME_None;
                CurrentState = 0;
            }
            
            break;
            
        case 2:
            UE_LOG(LogTemp, Warning, TEXT("%s"), *FString::FromInt(MaskNum))
            break;
        case 3:
            UE_LOG(LogTemp, Warning, TEXT("%s"), *FString::FromInt(MaskNum))
            break;
        case 4:
            UE_LOG(LogTemp, Warning, TEXT("%s"), *FString::FromInt(MaskNum))
            break;
            
        default:
            UE_LOG(LogTemp, Warning, TEXT("No Such Mask exist"))
            break;
    }
    
    if (CurrentMaskState == EMaskEquip::ME_Mask1) {
        UE_LOG(LogTemp, Warning, TEXT("Mask 1"))
    }
}

void UKaMenMaskMasterComponent_C::UseMatchingPrimarySkill() {
    if (!KaMenMaskMesh) {
        UE_LOG(LogTemp, Error, TEXT("No Kamen Mask Found (%s)"), *(this->GetClass()->GetName()))
        return;
    }
    
    if (CurrentState == 0) {
        UE_LOG(LogTemp, Warning, TEXT("Mask 0"))
    }
    
    if (CurrentMaskState == EMaskEquip::ME_Mask1) {
        KaMenMaskMesh->ThrowString();
    } else {
        UE_LOG(LogTemp, Warning, TEXT("No Mask Equipped."))
    }
    
}

void UKaMenMaskMasterComponent_C::EquipMask(){
    
}



bool UKaMenMaskMasterComponent_C::IsHooked(FHitResult& OutHit) {
    //FHitResult OutHit; //Hit Result stored on impact
    
    FVector SweepStart = GetOwner()->GetActorLocation();
    FVector SweepEnd = SweepStart + FVector(0.f, 0.f, 400.f);
    
    TArray<TEnumAsByte<EObjectTypeQuery>> TraceObjectType;
    TraceObjectType.Add(UEngineTypes::ConvertToObjectType(ECC_WorldStatic));
    
    FCollisionShape JumpColSphere = FCollisionShape::MakeSphere(50.f); //Make sphere collision shape
    
    FCollisionQueryParams TraceParameter (FName(TEXT("")), false, GetOwner());
    
    DrawDebugSphere(GetWorld(), SweepStart, JumpColSphere.GetSphereRadius(), 2, FColor(255, 0, 0), false, 5.f);
    
    //Sphere trace for jumping
    auto bIsHit = GetWorld()->SweepSingleByObjectType(OutHit, SweepStart, SweepEnd, FQuat::Identity, TraceObjectType, JumpColSphere, TraceParameter);
    
    DrawDebugSphere(GetWorld(), SweepEnd, JumpColSphere.GetSphereRadius(), 2, FColor(255, 0, 0), false, 5.f);
    
    return bIsHit;
}

void UKaMenMaskMasterComponent_C::ThrowStringMM() {
    UE_LOG(LogTemp, Warning, TEXT("Use String."))
    
    
    UE_LOG(LogTemp, Warning, TEXT("Hit : %s"), IsHooked(OutHitResult)? TEXT("True") : TEXT("False"))
    
    //Detect whether string can attach to a hook
    //if it is hooked, attach the current pawn to the
    if (IsHooked(OutHitResult)) {
        auto* HitActor = OutHitResult.GetActor();
        auto AttachLocation = HitActor->GetActorLocation() + FVector(0.f, 0.f, -300.f);
        
        if (HitActor->ActorHasTag(TEXT("Hook"))) {
            UE_LOG(LogTemp, Warning, TEXT("Has Tag."))
            FVector HitLocation = OutHitResult.ImpactPoint;
            
            auto KuuRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
            
            UE_LOG(LogTemp, Warning, TEXT("Hit Vector : %s"), *(HitLocation.ToString()))
            DrawDebugPoint(GetWorld(), HitLocation, 3, FColor(255,255,0), false, 5.f);

            
            if (GetOwner()->GetActorLocation() != AttachLocation) {
                UE_LOG(LogTemp, Warning, TEXT("Nope."))
                
                auto KuuPawn = GetOwner();
                
                KuuRoot->SetAllPhysicsLinearVelocity(FVector(0.f));
                GetOwner()->SetActorLocation(AttachLocation + FVector(0.f, 0.f, -47.f));
                
            }
            KuuRoot->SetEnableGravity(false);
            IsAttached = true;
        }
        
    }
    
}



/*
 
 DrawDebugSphere(<#const UWorld *InWorld#>, <#const FVector &Center#>, <#float Radius#>, <#int32 Segments#>, <#const FColor &Color#>)
 
 //DrawDebugCapsule(<#const UWorld *InWorld#>, <#const FVector &Center#>, <#float HalfHeight#>, <#float Radius#>, <#const FQuat &Rotation#>, <#const FColor &Color#>)

 bool SweepSingleByObjectType
 (
 struct FHitResult & OutHit,
 const FVector & Start,
 const FVector & End,
 const FQuat & Rot,     FQuat::Identity
 const FCollisionObjectQueryParams & ObjectQueryParams,
 const FCollisionShape & CollisionShape,
 const FCollisionQueryParams & Params
 )

 //DrawDebugLine(GetWorld(), AttachLocation, HitActor->GetActorLocation(), FColor(255,0,0),false, 5.f, 0, 12.333);
 //  GetOwner()->AttachToActor(HitActor, FAttachmentTransformRules(EAttachmentRule::KeepWorld, false), FName(""));
*/
