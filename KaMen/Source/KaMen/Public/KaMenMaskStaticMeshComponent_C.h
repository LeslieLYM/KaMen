// By WorldsEndLover

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "KaMenMaskMasterComponent_C.h"
#include "KaMenMaskStaticMeshComponent_C.generated.h"

class UKaMenMask1_C;
class UKaMenStaticMeshComponent_C;
//class UKaMenMaskMasterComponent_C;

/**
 * Static Mesh for Mask to be equip. Able to use the corresponding mask abilities.
 */
UCLASS(meta = (BlueprintSpawnableComponent), ClassGroup = "Meshes", DisplayName = "Kamen Mask")
class KAMEN_API UKaMenMaskStaticMeshComponent_C : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    void SetKamenMeshReference(UKaMenStaticMeshComponent_C* KamenMeshToSet);
    
    //Display the equipped mask, it shall be called every time equipment changes
    void SetEquippedMask(EMaskEquip MaskT);
    
    //void
    
    //Overall Abilities (Abilities script/ Pawn, actor component)
        //Push
    
    //Mask 1 Abilities
    //Climb ledges
        //when near a ()m ledge, pressing button () allow players to climb up
    
    //String
        //stretch lines upwards, detect if there is hook actors
            //if there is hook, attach string to hook, drag hook to move
            //need hook actor reference
    
    //Transform
        //Immdiately done when equip with Mask 1
        
            //Change mesh from Kamen to Large Puppets
            //Speed difference, Jump height different
    void Transform(EMaskEquip CurrentMask);
    
    //Mask 2 Abilities
    
    UPROPERTY(EditDefaultsOnly, Category = "Mask1")
    UStaticMesh* UnequipFormMesh = nullptr;
    UPROPERTY(EditDefaultsOnly, Category = "Mask1")
    UStaticMesh* EquipFormMesh = nullptr;
    
    
protected:
    virtual void BeginPlay() override;
    
private:
    UKaMenMaskMasterComponent_C* Mask1 = nullptr;
    UKaMenStaticMeshComponent_C* KaMenMesh = nullptr;
	
    EMaskEquip MaskEquip = EMaskEquip::ME_None;
};
