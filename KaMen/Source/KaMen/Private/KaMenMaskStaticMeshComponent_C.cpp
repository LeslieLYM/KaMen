// By WorldsEndLover

#include "KaMenMaskStaticMeshComponent_C.h"
#include "KaMenStaticMeshComponent_C.h"
#include "KaMenMask1_C.h"


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
