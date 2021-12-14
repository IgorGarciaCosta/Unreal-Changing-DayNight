// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NightDayProj : ModuleRules
{
	public NightDayProj(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
