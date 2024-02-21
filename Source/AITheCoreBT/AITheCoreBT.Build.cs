// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AITheCoreBT : ModuleRules
{
	public AITheCoreBT(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		bLegacyPublicIncludePaths = true;
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "GameplayTasks", "AIModule" });
	}
}
