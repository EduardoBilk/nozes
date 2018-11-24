workspace "Nozes"
  architecture "x64"
  configurations{
    "Debug",
    "Release",
    "Dist"
  }
outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
  project "Nozes"
    location "Nozes"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/".. outputDir .."/%{prj.name}" )
    objdir ("bin-int/".. outputDir .."/%{prj.name}" )

    files{
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp"
    }
    includedirs{
      "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
      cppdialect "C++17"
      staticruntime "On"
      systemversion "latest"
      
      defines{
        "NZ_PLATFORM_WINDOWS",
        "NZ_BUILD_DLL"
      }

      postbuildcommands{
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")
      }
    filter "configurations:Debug"
      defines "NZ_DEBUG"
      symbols "On"
    filter "configurations:Release"
      defines "NZ_RELEASE"
      optimize "On"
    filter "configurations:Dist"
      defines "NZ_DIST"
      optimize "On"

  project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/".. outputDir .."/%{prj.name}" )
    objdir ("bin-int/".. outputDir .."/%{prj.name}" )

    files{
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp"
    }
    includedirs{
      "Nozes/vendor/spdlog/include",
      "Nozes/src"
    }

    links {
      "Nozes"
    }

    filter "system:windows"
      cppdialect "C++17"
      staticruntime "On"
      systemversion "latest"
      
      defines{
        "NZ_PLATFORM_WINDOWS"
      }
    filter "configurations:Debug"
      defines "NZ_DEBUG"
      symbols "On"
    filter "configurations:Release"
      defines "NZ_RELEASE"
      optimize "On"
    filter "configurations:Dist"
      defines "NZ_DIST"
      optimize "On"
  