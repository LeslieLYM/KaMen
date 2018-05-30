// By WorldsEndLover

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "KaMenMaskMasterComponent_C.generated.h"

class UKaMenMaskStaticMeshComponent_C;
class UKaMenStaticMeshComponent_C;

UENUM()
enum class EMaskEquip : uint8
{
    ME_None,
    ME_Mask1
};

/**
 Kamen Mask Master Component overrides all mask components. It manages the equipment and usage of the masks by player.
 
 The Master Component focuses on the Equip, Unequip function. All abilities will be found in corresponding masks.
 */
UCLASS( meta=(BlueprintSpawnableComponent), ClassGroup = "Meshes", DisplayName = "Kamen Mask Component" )
class KAMEN_API UKaMenMaskMasterComponent_C : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UKaMenMaskMasterComponent_C();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
    
    UFUNCTION(BlueprintCallable, Category = "Mask")
    void SetMaskStaticMeshReference(UKaMenMaskStaticMeshComponent_C* KamenMaskToSet, UKaMenStaticMeshComponent_C* KamenMeshToSet);
    
    
    EMaskEquip GetCurrentMaskState();
    
    // Function to check the what key/ action is entered
    UFUNCTION(BlueprintCallable, Category = "Mask")
    void CheckMask(int32 MaskNum);
    
    UFUNCTION(BlueprintCallable, Category = "Mask")
    virtual void UseMatchingPrimarySkill();
    
    bool IsHooked(FHitResult& OutHit);
    
    void ThrowStringMM();
    
    void EquipMask();
    
    UPROPERTY(BlueprintReadWrite, Category = "Mask 1")
    bool IsAttached = false;
    
    UPROPERTY(BlueprintReadOnly, Category = "Mask 1")
    FHitResult OutHitResult;

private:
    UKaMenMaskStaticMeshComponent_C* KaMenMaskMesh = nullptr;
    UKaMenStaticMeshComponent_C* KaMenMesh = nullptr;

    
    
    EMaskEquip CurrentMaskState = EMaskEquip::ME_None;
    int32 CurrentState = 2;
    
		
	
};
