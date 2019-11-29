// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#pragma once


#include "GameFramework/HUD.h"
#include "MazeHUD.generated.h"


UCLASS()
class AMazeHUD : public AHUD
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
    UFUNCTION(BlueprintCallable, Category = MazeGen)
        void GenMaze(float tileX, float tileY);

public:
    virtual void DrawHUD() override;
    virtual void PostInitializeComponents() override;
};

template <typename AMazeGen>
FORCEINLINE AMazeGen* SpawnBP(
    UWorld* TheWorld,
    UClass* TheBP,
    const FVector& Loc,
    const FRotator& Rot,
    const bool bNoFail = true,
    AActor* Owner = NULL,
    APawn* Instigator = NULL
    ){
    if (!TheWorld) return NULL;
    if (!TheBP) return NULL;
    //~~~~~~~~~~~


    FActorSpawnParameters SpawnInfo;
    SpawnInfo.bNoFail = bNoFail;
    SpawnInfo.Owner = Owner;
    SpawnInfo.Instigator = Instigator;
    SpawnInfo.bDeferConstruction = false;


    return TheWorld->SpawnActor<AMazeGen>(TheBP, Loc, Rot, SpawnInfo);
}