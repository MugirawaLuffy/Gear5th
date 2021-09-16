workspace "Gear5th"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Gear5th"
	location "Gear5th"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include;"
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
		symbols "On"
	
	filter "configurations:Release"
		defines "G5_RELEASE"
		optimize "On"	
	
	filter "configurations:Dist"
		defines "G5_DIST"
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
			"G5_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "G5_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "G5_RELEASE"
		optimize "On"	
	
	filter "configurations:Dist"
		defines "G5_DIST"
		optimize "On"
