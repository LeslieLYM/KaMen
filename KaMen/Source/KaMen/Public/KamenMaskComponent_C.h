// By WorldsEndLover

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KamenMaskComponent_C.generated.h"

UCLASS()
class KAMEN_API AKamenMaskComponent_C : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKamenMaskComponent_C();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
