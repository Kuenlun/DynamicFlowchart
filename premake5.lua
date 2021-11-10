workspace "DynamicFlowchart"
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
IncludeDir["GLFW"] = "KDF/vendor/GLFW/include"

startproject "Sandbox"


include "KDF/vendor/GLFW"

project "KDF"
	location "KDF"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "KDFpch.h"
	pchsource "KDF/src/KDFpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"KDF_PLATFORM_WINDOWS",
			"KDF_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
			--("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "KDF_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "KDF_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "KDF_DIST"
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
		"KDF/vendor/spdlog/include",
		"KDF/src"
	}

	links
	{
		"KDF"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"KDF_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "KDF_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "KDF_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "KDF_DIST"
		optimize "On"