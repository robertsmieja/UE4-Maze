

#include "Maze.h"
#include "MazeHUD.h"
#include "MazeGameMode.h"
#include "MazePlayerController.h"

AMazeGameMode::AMazeGameMode(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PlayerControllerClass = AMazePlayerController::StaticClass();

    HUDClass = AMazeHUD::StaticClass();
}


