// By WorldsEndLover

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "PuppetStaticMeshComponent_C.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), ClassGroup = "Meshes", DisplayName = "Puppet Mesh")
class KAMEN_API UPuppetStaticMeshComponent_C : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    
    FVector GetPuppetRight();
    
    void SetPuppetMovment(float Direction, float Speed);
    
    void AdjustRotation();
    
    void Rotate(float AngleToRotate);
    
    void Jump(float Speed);
    
private:
    FVector PuppetRight = FVector(0.f);
	
	
};
