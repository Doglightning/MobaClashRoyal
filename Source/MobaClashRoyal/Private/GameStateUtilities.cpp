// Fill out your copyright notice in the Description page of Project Settings.


#include "GameStateUtilities.h"

void UGameStateUtilities::UpdateUnitData(UPARAM(ref) TMap<int32, FUnitStruct>& UnitDataUIDMap, const FUnitStruct& UnitStruct, int32 UID)
{
    if (UnitDataUIDMap.Contains(UID))
    {
        // Access the existing unit struct from the map
        FUnitStruct& ExistingUnitStruct = UnitDataUIDMap[UID];

        // Update only specific fields
        ExistingUnitStruct.Team = UnitStruct.Team;
        ExistingUnitStruct.CurrentHP = UnitStruct.CurrentHP;
        ExistingUnitStruct.Position = UnitStruct.Position;
        ExistingUnitStruct.Rotation = UnitStruct.Rotation;
        ExistingUnitStruct.Movespeed = UnitStruct.Movespeed;
        ExistingUnitStruct.Combat = UnitStruct.Combat;
        ExistingUnitStruct.attackFrame = UnitStruct.attackFrame;

        // Do not update 'UnitRef' and 'UnitClass'
    }
    else
    {
        // Optionally handle the case where UID does not exist
        // This could be logging an error or creating a new entry if that's the desired behavior
        UE_LOG(LogTemp, Warning, TEXT("UID %d not found in map."), UID);
    }
}

