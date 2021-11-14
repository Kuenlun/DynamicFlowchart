workspace "DynamicFlowchart"
	architecture "x64"
	startproject "Sandbox"

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
IncludeDir["Glad"] = "KDF/vendor/Glad/include"
IncludeDir["ImGui"] = "KDF/vendor/imgui"



group "Dependencies"
	include "KDF/vendor/GLFW"
	include "KDF/vendor/Glad"
	include "KDF/vendor/imgui"
group ""

project "KDF"
	location "KDF"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

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
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"KDF_PLATFORM_WINDOWS",
			"KDF_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "KDF_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "KDF_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "KDF_DIST"
		runtime "Release"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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
		systemversion "latest"

		defines
		{
			"KDF_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "KDF_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "KDF_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "KDF_DIST"
		runtime "Release"
		optimize "On"