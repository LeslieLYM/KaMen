// By WorldsEndLover

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HookToAttach.generated.h"

UCLASS()
class KAMEN_API AHookToAttach : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHookToAttach();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
