// Fill out your copyright notice in the Description page of Project Settings.


#include "BFL_MeshPartition.h"

TArray<FBPS_GridCell> UBFL_MeshPartition::GridCells;
TArray<FSplineData> UBFL_MeshPartition::SplineData;
int32 UBFL_MeshPartition::gridWidth;
int32 UBFL_MeshPartition::gridHeight;
int32 UBFL_MeshPartition::cellSize;
FVector UBFL_MeshPartition::NavMeshOrigin;
FVector UBFL_MeshPartition::NavMeshExtent;

void UBFL_MeshPartition::PartitionNavMeshBounds(const FVector& NavMeshBoundsOrigin, const FVector& NavMeshBoundsExtent, float CellSize, TArray<FVector>& OutGridCenters)
{
    OutGridCenters.Empty();
    NavMeshOrigin = NavMeshBoundsOrigin;
    NavMeshExtent = NavMeshBoundsExtent;

    // Calculate the number of cells needed based on NavMeshBounds and desired cell size
    gridWidth = FMath::CeilToInt(NavMeshBoundsExtent.X * 2 / CellSize);
    gridHeight = FMath::CeilToInt(NavMeshBoundsExtent.Y * 2 / CellSize);
    cellSize = CellSize;

    // Calculate the starting position of the grid
    FVector GridStart = NavMeshBoundsOrigin - NavMeshBoundsExtent + FVector(CellSize / 2, CellSize / 2, 0);

    // Generate grid centers
    for (int32 X = 0; X < gridWidth; ++X)
    {
        for (int32 Y = 0; Y < gridHeight; ++Y)
        {
            FVector GridCenter = GridStart + FVector(X * CellSize, Y * CellSize, 0);
            OutGridCenters.Add(GridCenter);
        }
    }
}

// Function to process splines and save data
void UBFL_MeshPartition::InitializeSplineData(const TArray<AActor*>& Splines)
{
    // Clear the existing spline data array
    SplineData.Empty();

    // Iterate through each spline actor
    for (AActor* SplineActor : Splines) {
        if (SplineActor) {
            // Get the spline component of the actor
            USplineComponent* SplineComponent = SplineActor->FindComponentByClass<USplineComponent>();
            if (SplineComponent) {
                // Get the number of spline points
                int32 NumPoints = SplineComponent->GetNumberOfSplinePoints();

                // Create a new spline data struct and populate sit
                FSplineData NewSplineData{};
                NewSplineData.SplineActor = SplineActor;
                NewSplineData.MaxPoints = NumPoints;

                // Add the spline data to the array
                SplineData.Add(NewSplineData);
            }
        }
    }
}

void UBFL_MeshPartition::CalculateGridCellsWithSplineDirections(const TArray<FVector>& GridCenterCells, const TArray<AActor*>& Splines)
{
    InitializeSplineData(Splines);
    GridCells.Empty();

    // Iterate through each grid center cell
    for (const FVector& CellPosition : GridCenterCells)
    {
        // Initialize a new grid cell
        FBPS_GridCell NewGridCell;
        NewGridCell.CellPosition = CellPosition;

        // Initialize variables for storing closest spline and direction
        USplineComponent* ClosestSpline = nullptr;
        FVector ClosestPointOnSpline;
        FVector ClosestSplineDirection;

        // Find the closest spline and direction for the current grid cell
        float ClosestDistanceSquared = FLT_MAX;
        AActor* ClosestSplineActor = nullptr; // New variable to store the closest spline actor

        for (const FSplineData& IteratedSplineData : SplineData)
        {
            USplineComponent* SplineComponent = IteratedSplineData.SplineActor->FindComponentByClass<USplineComponent>();


            if (SplineComponent)
            {
                
                FVector ClosestWorldLocation = FindClosestPointOnSpline(SplineComponent, NewGridCell.CellPosition, IteratedSplineData.MaxPoints);
                float DistanceSquared = FVector::DistSquared(NewGridCell.CellPosition, ClosestWorldLocation);
                

                if (DistanceSquared < ClosestDistanceSquared)
                {
                    FVector ClosestWorldLocation2 = SplineComponent->FindLocationClosestToWorldLocation(NewGridCell.CellPosition, ESplineCoordinateSpace::World);
                    ClosestDistanceSquared = DistanceSquared;
                    ClosestSpline = SplineComponent;
                    ClosestPointOnSpline = ClosestWorldLocation2;
                    ClosestSplineActor = IteratedSplineData.SplineActor; // Update the closest spline actor

                    
                }
            }
        }

        // If a closest spline is found, calculate the direction at the closest point
        if (ClosestSpline)
        {
            ClosestSplineDirection = ClosestSpline->FindDirectionClosestToWorldLocation(ClosestPointOnSpline, ESplineCoordinateSpace::World);

            // Save the direction in the grid cell
            NewGridCell.Direction1 = ClosestSplineDirection;
            NewGridCell.MySpine = ClosestSplineActor;
        }
        //Add to Array
        GridCells.Add(NewGridCell);
    }
    
}

FVector UBFL_MeshPartition::FindClosestPointOnSpline(const USplineComponent* SplineComponent, const FVector& TargetLocation, int32 NumPoints)
{
    FVector ClosestPoint = FVector::ZeroVector;
    float ClosestDistanceSquared = FLT_MAX;

    for (int32 PointIndex = 0; PointIndex < NumPoints; ++PointIndex)
    {
        // Get the point on the spline
        FVector SplinePoint = SplineComponent->GetLocationAtSplinePoint(PointIndex, ESplineCoordinateSpace::World);

        // Calculate the distance squared between the spline point and the target location
        float DistanceSquared = FVector::DistSquared(SplinePoint, TargetLocation);

        // Update the closest point if this point is closer
        if (DistanceSquared < ClosestDistanceSquared)
        {
            ClosestDistanceSquared = DistanceSquared;
            ClosestPoint = SplinePoint;
        }
    }

    return ClosestPoint;
}

FVector UBFL_MeshPartition::GetDirectionFromLocation(const FVector& Location)
{
    // Calculate row and column indices
    int32 RowIndex = FMath::FloorToInt((Location.Y - NavMeshOrigin.Y + NavMeshExtent.Y) / cellSize);
    int32 ColIndex = FMath::FloorToInt((NavMeshOrigin.X + NavMeshExtent.X - Location.X) / cellSize);

    // Convert row index to match grid array orientation
   

    // Check if indices are within grid boundaries
    if (RowIndex < 0 || RowIndex >= gridHeight || ColIndex < 0 || ColIndex >= gridWidth)
    {
        // Location is outside grid boundaries
        return FVector::ZeroVector; // Use INDEX_NONE as equivalent to null
    }

    // Calculate cell index in the flattened grid array
    int32 CellIndex = (gridWidth - 1 - ColIndex) * gridHeight + RowIndex;

    // Check if the cell index is valid
    if (CellIndex >= 0 && CellIndex < GridCells.Num())
    {
        // Return the direction vector associated with the cell
        return GridCells[CellIndex].Direction1;
    }

    // If the cell index is invalid, return zero vector or some default value
    return FVector::ZeroVector;
}


TArray<FBPS_GridCell> UBFL_MeshPartition::GetDirectionArray()
{
    return GridCells;
}






