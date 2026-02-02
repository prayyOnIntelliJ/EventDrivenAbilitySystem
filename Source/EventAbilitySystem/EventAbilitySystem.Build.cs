// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EventAbilitySystem : ModuleRules
{
	public EventAbilitySystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"EventAbilitySystem",
			"EventAbilitySystem/Variant_Platforming",
			"EventAbilitySystem/Variant_Platforming/Animation",
			"EventAbilitySystem/Variant_Combat",
			"EventAbilitySystem/Variant_Combat/AI",
			"EventAbilitySystem/Variant_Combat/Animation",
			"EventAbilitySystem/Variant_Combat/Gameplay",
			"EventAbilitySystem/Variant_Combat/Interfaces",
			"EventAbilitySystem/Variant_Combat/UI",
			"EventAbilitySystem/Variant_SideScrolling",
			"EventAbilitySystem/Variant_SideScrolling/AI",
			"EventAbilitySystem/Variant_SideScrolling/Gameplay",
			"EventAbilitySystem/Variant_SideScrolling/Interfaces",
			"EventAbilitySystem/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
