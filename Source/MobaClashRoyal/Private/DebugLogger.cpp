#include "DebugLogger.h"

void UDebugLogger::LogError(const FString& Message)
{
    if (!Message.IsEmpty())
    {
        UE_LOG(LogTemp, Error, TEXT("%s"), *Message);
    }
}

void UDebugLogger::LogWarning(const FString& Message)
{
    if (!Message.IsEmpty())
    {
        UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
    }
}

void UDebugLogger::LogInfo(const FString& Message)
{
    if (!Message.IsEmpty())
    {
        UE_LOG(LogTemp, Log, TEXT("%s"), *Message);
    }
}