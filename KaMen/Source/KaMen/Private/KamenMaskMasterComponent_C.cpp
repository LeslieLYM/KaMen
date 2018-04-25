// By WorldsEndLover

#include "KaMenMaskMasterComponent_C.h"

//Interface



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

void UKaMenMaskMasterComponent_C::CheckMask(FKey KeyInput, int32 MaskNum) {
    switch (MaskNum) {
        case 1:
            UE_LOG(LogTemp, Warning, TEXT("%s"), *FString::FromInt(MaskNum))
            //auto Mask1
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

