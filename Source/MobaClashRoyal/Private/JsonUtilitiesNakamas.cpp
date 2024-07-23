// Fill out your copyright notice in the Description page of Project Settings.


#include "JsonUtilitiesNakamas.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

bool UJsonUtilitiesNakamas::ParseJsonArray(const FString& JsonString, const FString& ArrayFieldName, TArray<FString>& OutJsonStrings)
{
    // Parse the JSON string into a JSON object
    TSharedPtr<FJsonObject> JsonObject;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);

    if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
    {
        // Check if the specified array field exists in the JSON object
        const TArray<TSharedPtr<FJsonValue>>* JsonArray;
        if (JsonObject->TryGetArrayField(ArrayFieldName, JsonArray))
        {
            // Iterate over each element in the JSON array and convert each to a string
            for (const TSharedPtr<FJsonValue>& Value : *JsonArray)
            {
                TSharedPtr<FJsonObject> JsonItemObject = Value->AsObject();
                if (JsonItemObject.IsValid())
                {
                    FString ItemString;
                    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&ItemString);
                    FJsonSerializer::Serialize(JsonItemObject.ToSharedRef(), Writer);
                    OutJsonStrings.Add(ItemString);
                }
            }
            return true;
        }
    }
    return false;
}

bool UJsonUtilitiesNakamas::ParseJsonIntArray(const FString& JsonString, const FString& ArrayFieldName, TArray<int32>& OutIntegers, FString& OutStringRepresentation)
{
    // Parse the JSON string into a JSON object
    TSharedPtr<FJsonObject> JsonObject;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);

    if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
    {
        // Check if the specified array field exists and is not null
        const TArray<TSharedPtr<FJsonValue>>* JsonArray;
        if (JsonObject->TryGetArrayField(ArrayFieldName, JsonArray))
        {
            OutStringRepresentation = "["; // Start the string representation
            bool bFirst = true; // To handle comma placement

            // Iterate over each element in the JSON array
            for (const TSharedPtr<FJsonValue>& Value : *JsonArray)
            {
                int32 CurrentValue = Value->AsNumber();
                OutIntegers.Add(CurrentValue); // Add to the array

                // Append to the string representation
                if (!bFirst) // If not the first element, prepend a comma
                {
                    OutStringRepresentation += ", ";
                }
                OutStringRepresentation += FString::FromInt(CurrentValue);
                bFirst = false;
            }

            OutStringRepresentation += "]"; // End the string representation
            return true;
        }
        else
        {
            // Handle the case where the array is explicitly null or not present
            OutIntegers.Empty(); // Ensure array is empty to reflect 'null' or non-existent field
            OutStringRepresentation.Empty(); // Clear the string representation
        }
    }
    return false;
}
