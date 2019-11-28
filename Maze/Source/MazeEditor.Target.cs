

using UnrealBuildTool;
using System.Collections.Generic;

public class MazeEditorTarget : TargetRules
{
    public MazeEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;

        ExtraModuleNames.AddRange(new string[] { "Maze" });
    }
}
