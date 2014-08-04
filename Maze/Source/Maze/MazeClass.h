

#pragma once

#include "Object.h"
#include "Int3.h"
#include "MazeClass.generated.h"

/**
 * Wrapper class for TMap<FInt3, AStaticMeshActor>
 */
UCLASS()
class MAZE_API UMazeClass : public UObject
{
    GENERATED_UCLASS_BODY()

    UFUNCTION(BlueprintCallable, Category = MazeStruct)
        AStaticMeshActor* Get(FInt3 Coordinate);

    UFUNCTION(BlueprintCallable, Category = MazeStruct)
        void Set(FInt3 Coordinate, AStaticMeshActor* Tile);

    UFUNCTION(BlueprintCallable, Category = MazeStruct)
        int32 Remove(FInt3 Coordinate);

    UFUNCTION(BlueprintCallable, Category = MazeStruct)
        void Empty();

private:
        TMap<FInt3, AStaticMeshActor*> MazeGrid;

};
