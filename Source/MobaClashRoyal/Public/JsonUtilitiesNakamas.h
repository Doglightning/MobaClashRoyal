// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "JsonUtilitiesNakamas.generated.h"

UCLASS()
class MOBACLASHROYAL_API UJsonUtilitiesNakamas : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    // Function to parse JSON string and return array of unit JSON strings
    UFUNCTION(BlueprintCallable, Category = "Utilities|Json")
    static bool ParseJsonArray(const FString& JsonString, const FString& ArrayFieldName, TArray<FString>& OutJsonStrings);

    // Function to parse JSON string and return array of unit JSON strings
    UFUNCTION(BlueprintCallable, Category = "Utilities|Json")
    static bool ParseJsonIntArray(const FString& JsonString, const FString& ArrayFieldName, TArray<int32>& OutIntegers, FString& OutStringRepresentation);
};