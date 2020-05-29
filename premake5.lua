workspace "Ragnarok"
	configurations
	{
		"Debug",
		"Release"
	}
	startproject = "Ragnarok"

	platforms
	{
		"x86",
	}
	characterset ("MBCS")


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["FMOD"] = "vendor/fmod/inc"

project "01. Ragnarok"
	location "01. Ragnarok"
	kind "WindowedApp"
	language "C++"

	pchheader "stdafx.h"
	pchsource "01. Ragnarok/src/stdafx.cpp"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs
	{
		"%{prj.name}/src",
	}
	libdirs
	{
		"vendor/fmod/lib",
		"vendor/Json/lib"
	}
	links
	{
		"fmod_vc.lib",
		"jsoncpp.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"
		
	filter "configurations:Release"
		runtime "Debug"
		optimize "On"