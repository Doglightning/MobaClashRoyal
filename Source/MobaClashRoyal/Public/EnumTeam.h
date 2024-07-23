// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"

UENUM(BlueprintType)
enum class ETeam : uint8
{
    Blue UMETA(DisplayName = "Blue"),
    Red UMETA(DisplayName = "Red"),
    Neutral UMETA(DisplayName = "Neutral"),
};
