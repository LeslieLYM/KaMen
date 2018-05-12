// By WorldsEndLover

#pragma once

#include "CoreMinimal.h"
#include "KaMenMaskMasterComponent_C.h"
#include "KaMenMask1_C.generated.h"

/**
 * 
 */
UCLASS()
class KAMEN_API UKaMenMask1_C : public UKaMenMaskMasterComponent_C
{
	GENERATED_BODY()
	
	
public:
    UKaMenMask1_C();
    
    void ShowEquipped();
    
    virtual void UseMatchingPrimarySkill() override;
	
};
