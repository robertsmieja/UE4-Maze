

#include "Maze.h"
#include "MazeClass.h"


UMazeClass::UMazeClass(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

 AStaticMeshActor* UMazeClass::Get(FInt3 Coordinate)
{
     return MazeGrid.FindChecked(Coordinate);
}

void UMazeClass::Set(FInt3 Coordinate, AStaticMeshActor * Tile)
{
    MazeGrid.Add(Coordinate, Tile);
}

int32 UMazeClass::Remove(FInt3 Coordinate)
{
   return MazeGrid.Remove(Coordinate);
}

void UMazeClass::Empty()
{
    MazeGrid.Empty();
}
