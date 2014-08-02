

#include "Maze.h"
#include "MazeHUD.h"
#include "MazeGameMode.h"
#include "MazePlayerController.h"

AMazeGameMode::AMazeGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PlayerControllerClass = AMazePlayerController::StaticClass();

    HUDClass = AMazeHUD::StaticClass();
}


