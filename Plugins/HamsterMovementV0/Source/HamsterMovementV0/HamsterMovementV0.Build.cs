// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class HamsterMovementV0 : ModuleRules
{
    public HamsterMovementV0(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "EnhancedInput"
        });
    }
}