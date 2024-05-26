// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Components/SplineComponent.h"
#include "BFL_MeshPartition.generated.h"

// Struct to hold data on each cell
USTRUCT(BlueprintType)
struct FBPS_GridCell
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FVector CellPosition;

	UPROPERTY(BlueprintReadWrite)
	FVector Direction1;

	UPROPERTY(BlueprintReadWrite)
	FVector Direction2;

	UPROPERTY(BlueprintReadWrite)
	AActor* MySpine;

};

// Struct to hold data on each spline
USTRUCT(BlueprintType)
struct FSplineData 
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	AActor* SplineActor;

	UPROPERTY(BlueprintReadWrite)
	int32 MaxPoints;
};

/**
 * 
 */
UCLASS()
class MOBACLASHROYAL_API UBFL_MeshPartition : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Grid Partition")
		static void PartitionNavMeshBounds(const FVector& NavMeshBoundsOrigin, const FVector& NavMeshBoundsExtent, float CellSize, TArray<FVector>& OutGridCenters);

	UFUNCTION()
		static void InitializeSplineData(const TArray<AActor*>& Splines);

	UFUNCTION(BlueprintCallable, Category = "Grid Partition")
		static void CalculateGridCellsWithSplineDirections(const TArray<FVector>& GridCenterCells, const TArray<AActor*>& Splines);

	UFUNCTION()
		static FVector FindClosestPointOnSpline(const USplineComponent* SplineComponent, const FVector& TargetLocation, int32 NumPoints);

	UFUNCTION(BlueprintCallable, Category = "Grid Partition")
		static FVector GetDirectionFromLocation(const FVector& Location);

	UFUNCTION(BlueprintCallable, Category = "Grid Partition")
		static TArray<FBPS_GridCell> GetDirectionArray();
	
private:
	// Array to store grid cells
	static TArray<FBPS_GridCell> GridCells;
	static TArray<FSplineData> SplineData;
	static int32 gridWidth;
	static int32 gridHeight;
	static int32 cellSize;
	static FVector NavMeshOrigin;
	static FVector NavMeshExtent;
};


