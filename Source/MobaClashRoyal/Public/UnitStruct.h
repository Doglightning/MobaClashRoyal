#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "EnumTeam.h"  // Include the custom enum header
#include "ABaseUnit.h"
#include "GameFramework/Character.h"
#include "UnitStruct.generated.h"

USTRUCT(BlueprintType)
struct FUnitStruct
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
    ETeam Team;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
    float CurrentHP;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
    float MaxHP;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
    FVector Position;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
    FRotator Rotation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
    float Movespeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
    bool Combat;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
    int attackFrame;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
    int DamageFrameSP;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
    int AttackRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
    int EndFrameSP;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
    int SpRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
    float CurrentSP;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
    TArray<FString> EffectsList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
    bool ChargedSP;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
    bool Stunned;

};

USTRUCT(BlueprintType)
struct FStructureStruct
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
    ETeam Team;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
    float CurrentHP;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
    FVector Position;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
    FString State;

};

USTRUCT(BlueprintType)
struct FProjectileStruct
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
    FVector Position;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
    FRotator Rotation;

};

USTRUCT(BlueprintType)
struct FSpStruct
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
    FVector Position;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
    FRotator Rotation;

};