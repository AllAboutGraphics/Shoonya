workspace "Shoonya"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Shoonya"
    location "Shoonya"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "shpch.h"
    pchsource "Shoonya/src/shpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src"
    }

    filter "system:windows"
        cppdialect "c++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SH_PLATFORM_WINDOWS",
            "SH_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    
    filter "configurations:Debug"
        defines "SH_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SH_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SH_DIST"
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
        "Shoonya/vendor/spdlog/include",
        "Shoonya/src"
    }

    links
    {
        "Shoonya"
    }

    filter "system:windows"
        cppdialect "c++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SH_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "SH_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SH_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SH_DIST"
        optimize "On"