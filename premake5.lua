workspace "Lzengine"
    architecture "x64"

    configurations {
        "Debug", "Release", "Dist" 
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Lzengine/vendor/GLFW/include"

include "Lzengine/vendor/GLFW"

project "Lzengine"
    location "Lzengine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "lzepch.h"
    pchsource "Lzengine/src/lzepch.cpp"

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "Lzengine/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "c++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "LZE_PLATFORM_WINDOWS", "LZE_BUILD_DLL"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "LZE_DEBUG"
        buildoptions "/MDd"
        symbols "On"
    
    filter "configurations:Release"
        defines "LZE_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "LZE_DIST"
        buildoptions "/MD"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "Lzengine/vendor/spdlog/include",
        "Lzengine/src"
    }

    links {
        "Lzengine"
    }

    filter "system:windows"
        cppdialect "c++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "LZE_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
        defines "LZE_DEBUG"
        buildoptions "/MDd"
        symbols "On"
    
    filter "configurations:Release"
        defines "LZE_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "LZE_DIST"
        buildoptions "/MD"
        optimize "On"