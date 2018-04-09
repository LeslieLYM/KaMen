// By WorldsEndLover

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "KaMenStaticMeshComponent_C.generated.h"

/**
 * Static Mesh for KaMen Pawn. Accessing the mechanic functions of KaMen through here.
 */
UCLASS(meta = (BlueprintSpawnableComponent), ClassGroup = "Meshes", DisplayName = "Kamen Mesh")
class KAMEN_API UKaMenStaticMeshComponent_C : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    void SetKaMenMovment(float Direction, float Speed);
	
    
	
};
