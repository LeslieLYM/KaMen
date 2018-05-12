// By WorldsEndLover

#include "KaMenMaskMasterComponent_C.h"
#include "KaMenStaticMeshComponent_C.h"
#include "KaMenMaskStaticMeshComponent_C.h"



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

void UKaMenMaskMasterComponent_C::CheckMask(FKey KeyInput, int32 MaskNum) {
    
    if (!KaMenMaskMesh) {
        UE_LOG(LogTemp, Error, TEXT("No Kamen Mask Found (%s)"), *(this->GetClass()->GetName()))
        return;
    }
    
    switch (MaskNum) {
        case 1:
            UE_LOG(LogTemp, Warning, TEXT("%s"), *FString::FromInt(MaskNum))
            //KaMenMaskMesh->SetEquippedMask(EMaskEquip::ME_Mask1);
            
            if (CurrentMaskState == EMaskEquip::ME_None) {
                UE_LOG(LogTemp, Warning, TEXT("Current Mask change to 1"))
                CurrentMaskState = EMaskEquip::ME_Mask1;
            } else if (CurrentMaskState == EMaskEquip::ME_Mask1) {
                UE_LOG(LogTemp, Warning, TEXT("Current Mask change to 0"))
                CurrentMaskState = EMaskEquip::ME_None;
            }
            KaMenMaskMesh->Transform(CurrentMaskState);
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
}

void UKaMenMaskMasterComponent_C::EquipMask(){
    
}

