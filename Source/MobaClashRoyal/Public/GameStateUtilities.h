// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UnitStruct.h" // Ensure this includes your FUnitStruct definition.
#include "GameStateUtilities.generated.h"

UCLASS()
class MOBACLASHROYAL_API UGameStateUtilities : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    // Function to update a map of unit data. It does not return anything and updates the map by reference.
    UFUNCTION(BlueprintCallable, Category = "GameStateUtils", meta = (AutoCreateRefTerm = "UnitDataUIDMap"))
    static void UpdateUnitData(UPARAM(ref) TMap<int32, FUnitStruct>& UnitDataUIDMap, const FUnitStruct& UnitStruct, int32 UID);

    
};
