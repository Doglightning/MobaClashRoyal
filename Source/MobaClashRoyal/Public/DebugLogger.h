#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DebugLogger.generated.h"

UCLASS(BlueprintType)
class MOBACLASHROYAL_API UDebugLogger : public UObject
{
    GENERATED_BODY()

public:
    // Function to log an error message
    UFUNCTION(BlueprintCallable, Category = "Logging")
    static void LogError(const FString& Message);

    // You can add more logging levels as needed
    UFUNCTION(BlueprintCallable, Category = "Logging")
    static void LogWarning(const FString& Message);

    UFUNCTION(BlueprintCallable, Category = "Logging")
    static void LogInfo(const FString& Message);
};