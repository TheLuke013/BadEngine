workspace "BadEngine"
	startproject "Editor"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Libs"
	include "ThirdParty/ImGui"
group ""

project "Engine"
	location "Engine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/include/**.h",
		"%{prj.name}/src/**.cpp"
	}

	defines
    {
        "_CRT_SECURE_NO_WARNINGS",
		"_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS",
		"_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING",
        "ENGINE_EXPORTS"
    }

	includedirs
	{
		"%{prj.name}/include",
		"ThirdParty/ImGui/include",
		"ThirdParty/raylib/include"
	}

	links
	{
		"DearImGui",
		"ThirdParty/raylib/lib/raylib.lib",
        "winmm.lib",
        "kernel32.lib",
        "gdi32.lib",
        "user32.lib",
        "shell32.lib",
        "opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Editor")
		}

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"
        linkoptions { "/NODEFAULTLIB:MSVCRT" }

    filter "configurations:Release"
        runtime "Release"
        optimize "On"
        linkoptions { "/NODEFAULTLIB:MSVCRT" }

    filter "configurations:Dist"
        runtime "Release"
        optimize "On"
        linkoptions { "/NODEFAULTLIB:MSVCRT" }

project "Editor"
	location "Editor"
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
		"Engine/include",
		"ThirdParty/ImGui/include",
		"ThirdParty/raylib/include"
	}

	links
	{
		"Engine",
		"DearImGui"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

	filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        runtime "Release"
        optimize "On"