workspace "wrapper"

    --premake.gcc.cc  = 'clang'
    --premake.gcc.cxx = 'clang++'

    configurations { "Debug", "Release" }

    includedirs { 
        "include",
        --"/usr/include/luajit-2.1",
        --"~/projects/Chipmunk2D/include"
        --"/home/nagolove/projects/Chipmunk2D/include",
        --"/home/nagolove/myprojects/lua_capi",
    }
    buildoptions { 
        "-std=c++20",
        --"-fPIC",
        --"-Wall",
        --"-Werror",
        --"-Wno-strict-aliasing",
        --"-Wno-unused-function",
    }
    links { 
        --"luajit-5.1", 
        --"lua5.1",
        --"chipmunk",
        --"mem_guard",
        --"sfml",

        "sfml-audio",
        "sfml-graphics",
        "sfml-network",
        "sfml-system",
        "sfml-window",

        "tgui",
    }
    libdirs { 
        --"/home/nagolove/projects/Chipmunk2D/src/",
        --"/home/nagolove/myprojects/c_guard",
        --"/home/nagolove/myprojects/lua_capi",
    }
    language "C++"
    kind "ConsoleApp"
    --targetdir "bin/%{cfg.buildcfg}"
    --targetdir "bin/%{cfg.buildcfg}"
    targetprefix ""
    targetdir "."

    project "wrp"
        files { "**.cpp" }
        --links { "lua5.1" }

    filter "configurations:Debug"
    defines { "DEBUG" }
    symbols "On"

    filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"
