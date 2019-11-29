// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

/* A rewrite of MazeHUD, using a TMap, with a Class wrapped around it for access in a Blueprint, using a struct to represent a coordinate */
#pragma once


#include "GameFramework/HUD.h"
#include "MazeClass.h"
#include "MazeClassHUD.generated.h"

UCLASS()
class AMazeClassHUD : public AHUD
{
    GENERATED_UCLASS_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MazeHUD)
        bool ShowTests;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MazeGen101isMax)
        float MazeXKeepODD;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MazeGen101isMax)
        float MazeYKeepODD;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = MazeTiles)
        UClass* TileGroundBP;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = MazeTiles)
        UClass* TileBlockBP;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = MazeTiles)
        UClass* TilePillarBP;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = MazeTiles)
        UClass* TileStartBP;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = MazeTiles)
        UClass* TileEndBP;

    UPROPERTY()
		UMazeClass* MazeGrid;

    UFUNCTION(BlueprintCallable, Category = MazeGen)
        void GenMaze(float tileX, float tileY);

public:
    virtual void DrawHUD() override;
    virtual void PostInitializeComponents() override;
};

