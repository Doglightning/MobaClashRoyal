using UnrealBuildTool;
using System.IO;

public class MobaClashRoyal : ModuleRules
{
    public MobaClashRoyal(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "Json",           // Include JSON module
            "JsonUtilities"   // Include JSON Utilities module
        });
        PrivateDependencyModuleNames.AddRange(new string[] { "NakamaUnreal" });

        PrivateDependencyModuleNames.AddRange(new string[] { });

        
        
        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}