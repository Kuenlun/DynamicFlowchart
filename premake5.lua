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
IncludeDir["glm"] = "KDF/vendor/glm"



group "Dependencies"
	include "KDF/vendor/GLFW"
	include "KDF/vendor/Glad"
	include "KDF/vendor/imgui"
group ""

project "KDF"
	location "KDF"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "KDFpch.h"
	pchsource "KDF/src/KDFpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"KDF_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "KDF_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "KDF_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "KDF_DIST"
		runtime "Release"
		optimize "on"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		"KDF/src",
		"%{IncludeDir.glm}"
	}

	links
	{
		"KDF"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"KDF_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "KDF_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "KDF_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "KDF_DIST"
		runtime "Release"
		optimize "on"
