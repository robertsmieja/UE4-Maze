

using UnrealBuildTool;
using System.Collections.Generic;

public class MazeTarget : TargetRules
{
    public MazeTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;

        ExtraModuleNames.AddRange(new string[] { "Maze" });
    }
}
