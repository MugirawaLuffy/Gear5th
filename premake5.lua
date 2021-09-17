workspace "Gear5th"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Gear5th/vendor/GLFW/include"
IncludeDir["Glad"] = "Gear5th/vendor/Glad/include"

include "Gear5th/vendor/GLFW"
include "Gear5th/vendor/Glad"

project "Gear5th"
	location "Gear5th"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "g5pch.h"
	pchsource "Gear5th/src/g5pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include;",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"G5_PLATFORM_WINDOWS",
			"G5_BUILD_DLL",
			"_WINDLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath}  ../bin/"  .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "G5_DEBUG"
		buildoptions "/MDd"
		symbols "On"
	
	filter "configurations:Release"
		defines "G5_RELEASE"
		buildoptions "/MD"
		optimize "On"	
	
	filter "configurations:Dist"
		defines "G5_DIST"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Gear5th/vendor/spdlog/include",
		"Gear5th/src"
	}

	links
	{
		"Gear5th"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"G5_PLATFORM_WINDOWS",
		"G5_BUILD_DLL",
		"GLFW_INCLUDE_NONE"
	}

	filter "configurations:Debug"
		defines "G5_DEBUG"
		buildoptions "/MDd"
		symbols "On"
	
	filter "configurations:Release"
		defines "G5_RELEASE"
		buildoptions "/MD"
		optimize "On"	
	
	filter "configurations:Dist"
		defines "G5_DIST"
		buildoptions "/MD"
		optimize "On"
