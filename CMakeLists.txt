cmake_minimum_required(VERSION 3.10)

project(ng_gl4es)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden -fPIC -DPIC -flto=auto")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DNOX11 -fPIC -DPIC -DNO_GBM -DDEFAULT_ES=3 -std=c17 -O3 -fvisibility=hidden -flto=auto")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -flto=auto")

set(CMAKE_ANDROID_STL_TYPE c++_static)

set(CMAKE_BUILD_TYPE Release)

include_directories(${CMAKE_SOURCE_DIR}/include )

set(C_SRC_FILES
        src/gl/string_utils.cpp
        src/gl/cJSON.cpp
        src/gl/config.cpp
        src/gl/arbgenerator.cpp
        src/gl/arbhelper.cpp
        src/gl/arbparser.cpp
        src/gl/array.cpp
        src/gl/blend.cpp
        src/gl/blit.cpp
        src/gl/buffers.cpp
        src/gl/build_info.cpp
        src/gl/debug.cpp
        src/gl/decompress.cpp
        src/gl/depth.cpp
        src/gl/directstate.cpp
        src/gl/drawing.cpp
        src/gl/enable.cpp
        src/gl/envvars.cpp
        src/gl/eval.cpp
        src/gl/face.cpp
        src/gl/fog.cpp
        src/gl/fpe.cpp
        src/gl/fpe_cache.cpp
        src/gl/fpe_shader.cpp
        src/gl/framebuffers.cpp
        src/gl/gl_lookup.cpp
        src/gl/gl4es.cpp
        src/gl/glstate.cpp
        src/gl/hint.cpp
        src/gl/init.cpp
        src/gl/light.cpp
        src/gl/line.cpp
        src/gl/list.cpp
        src/gl/listdraw.cpp
        src/gl/listrl.cpp
        src/gl/loader.cpp
        src/gl/logs.cpp
        src/gl/matrix.cpp
        src/gl/matvec.cpp
        src/gl/oldprogram.cpp
        src/gl/pixel.cpp
        src/gl/planes.cpp
        src/gl/pointsprite.cpp
        src/gl/preproc.cpp
        src/gl/program.cpp
        src/gl/queries.cpp
        src/gl/raster.cpp
        src/gl/render.cpp
        src/gl/shader.cpp
        src/gl/shaderconv.cpp
        src/gl/shader_hacks.cpp
        src/gl/stack.cpp
        src/gl/stencil.cpp
        src/gl/stubs.cpp
        src/gl/texenv.cpp
        src/gl/texgen.cpp
        src/gl/texture.cpp
        src/gl/texture_compressed.cpp
        src/gl/texture_params.cpp
        src/gl/texture_read.cpp
        src/gl/texture_3d.cpp
        src/gl/uniform.cpp
        src/gl/vertexattrib.cpp
        src/gl/wrap/gl4eswraps.cpp
        src/gl/wrap/gles.cpp
        src/gl/wrap/glstub.cpp
        src/gl/math/matheval.cpp
        src/glx/hardext.cpp
        src/glx/glx.cpp
        src/glx/lookup.cpp
        src/glx/gbm.cpp
        src/glx/streaming.cpp
        src/gl/vgpu/shaderconv.cpp
        src/gl/vgpu/Initialization.cpp
        src/gl/vgpu/load.cpp
        src/gl/vgpu/pack.cpp
        src/gl/samplers.cpp
        )

set(CPP_SRC_FILES
        src/gl/arbconverter.cpp
        src/glsl/glsl_for_es.cpp
        src/gl/getter.cpp
        )

set(SRC_FILES ${CPP_SRC_FILES} ${C_SRC_FILES})

find_library(GLSLANG_LIB glslang PATHS ${CMAKE_SOURCE_DIR}/libraries/arm64-v8a/)

add_library(ng_gl4es SHARED ${SRC_FILES})

target_link_libraries(ng_gl4es
        ${CMAKE_SOURCE_DIR}/libraries/arm64-v8a/libglslang.a
        ${CMAKE_SOURCE_DIR}/libraries/arm64-v8a/libspirv-cross-c-shared.so
        dl
        libomp.a
        )

target_include_directories(ng_gl4es PUBLIC
        ${CMAKE_SOURCE_DIR}/include
        )
