// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "Maze.h"
#include "MazeHUD.h"

const int MazeSizeMax = 101;

AMazeHUD::AMazeHUD(const class FObjectInitializer& ObjectInitializer):
	Super(ObjectInitializer)
{
    MazeXKeepODD = MazeSizeMax;
    MazeYKeepODD = MazeSizeMax;
    ShowTests = false;
}
void AMazeHUD::PostInitializeComponents(){
    Super::PostInitializeComponents();
    //Initial Message
    if (ShowTests){
        GenMaze(MazeXKeepODD, MazeYKeepODD);
    }
}
void AMazeHUD::DrawHUD(){
    Super::DrawHUD();
}
void AMazeHUD::GenMaze(float tileX, float tileY){
    float CaptureX = 0.0f;
    float CaptureY = 0.0f;
    float offset = 400.0f;
    float iter = 0;
    int tileID = 0;
    int RandomEndTileLoc = rand() % ((int)tileX - 1) + 1;

    AStaticMeshActor* grid[MazeSizeMax][MazeSizeMax];

    for (int x = 0; x < tileX; x++){
        for (int y = 0; y < tileY; y++){
            if (y == 0 || x == 0 || y == tileY - 1 || x == tileX - 1 || y % 2 == 0 && x % 2 == 0){
                //                          (X.Xf,Y.Yf,Z.Zf)
                const FVector  GenSpawnLoc(CaptureX, CaptureY, 0.0f);
                const FRotator GenSpawnRot(0.0f, 0.0f, 0.0f);
                AStaticMeshActor* BlockTile = SpawnBP<AStaticMeshActor>(GetWorld(), TileBlockBP, GenSpawnLoc, GenSpawnRot);

                grid[x][y] = BlockTile;
            }
            else{
                const FVector  GenSpawnLoc(CaptureX, CaptureY, 0.0f);
                const FRotator GenSpawnRot(0.0f, 0.0f, 0.0f);

                AStaticMeshActor* GroundTile = SpawnBP<AStaticMeshActor>(GetWorld(), TileGroundBP, GenSpawnLoc, GenSpawnRot);

                grid[x][y] = GroundTile;
            }
            //-------------Starting Tile Spawn---------------
            if (CaptureX == offset && CaptureY == offset){
                grid[1][1]->Destroy();

                const FVector  GenSpawnLoc(offset, offset, 0.0f);
                const FRotator GenSpawnRot(0.0f, 0.0f, 0.0f);
                //Tile Start
                AStaticMeshActor* StartTile = SpawnBP<AStaticMeshActor>(GetWorld(), TileStartBP, GenSpawnLoc, GenSpawnRot);

                grid[1][1] = StartTile;
            }
            //-------------Ending Tile Spawn---------------
            if (y == tileY - 1 && x == tileX - 1){
                grid[x - 1][y - 1]->Destroy();

                const FVector  GenSpawnLoc(((tileX - 2) * offset), ((tileY - 2) * offset), 0);
                const FRotator GenSpawnRot(0.0f, 0.0f, 0.0f);
                // Tile End
                AStaticMeshActor* EndTile = SpawnBP<AStaticMeshActor>(GetWorld(), TileEndBP, GenSpawnLoc, GenSpawnRot);

                grid[x - 1][y - 1] = EndTile;
            }
            CaptureY += offset;
            if (CaptureY >= offset * tileY){ CaptureY = 0; }
        }
        CaptureX += offset;
        if (CaptureX >= offset * tileX){ CaptureX = 0; }
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------
    for (int y = 2; y < tileY - 1; y += 2) {
        int dx = 2;
        int dy = y;
        int rnd4;

        switch (rnd4 = rand() % 4){
        case 0: dx++; break;
        case 1: dx--; break;
        case 2: dy++; break;
        case 3: dy--; break;
        }
        //if (bd.getPixel(dx, dy) != Status.WALL) {
        if (grid[dx][dy]->GetActorLabel() != "Block") {
            FVector f = grid[dx][dy]->GetActorLocation();
            grid[dx][dy]->Destroy();

            const FVector  GenSpawnLoc(f);
            const FRotator GenSpawnRot(0.0f, 0.0f, 0.0f);

            AStaticMeshActor* BlockTile = SpawnBP<AStaticMeshActor>(GetWorld(), TileBlockBP, GenSpawnLoc, GenSpawnRot);
            grid[dx][dy] = BlockTile;
        }
        else{
            y -= 2;
        }
    }
    for (int x = 4; x < tileX - 1; x += 2) {
        for (int y = 2; y < tileY - 1; y += 2) {
            int dx = x;
            int dy = y;
            int rnd3;

            switch (rnd3 = rand() % 3){
            case 0: dy++; break;
            case 1: dy--; break;
            case 2: dx++; break;
            }
            //if (bd.getPixel(dx, dy) != Status.WALL) {
            if (grid[dx][dy]->GetName() != "Block") {
                FVector f = grid[dx][dy]->GetActorLocation();
                grid[dx][dy]->Destroy();

                const FVector  GenSpawnLoc(f);
                const FRotator GenSpawnRot(0.0f, 0.0f, 0.0f);

                AStaticMeshActor* BlockTile = SpawnBP<AStaticMeshActor>(GetWorld(), TileBlockBP, GenSpawnLoc, GenSpawnRot);
                grid[dx][dy] = BlockTile;
            }
            else{
                y -= 2;
            }
        }
    }
}