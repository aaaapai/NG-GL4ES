cmake_minimum_required(VERSION 3.10)

project(ng_gl4es)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -pipe -integrated-as -mllvm -polly -mllvm -polly-vectorizer=stripmine -mllvm -polly-invariant-load-hoisting -mllvm -polly-run-inliner -mllvm -polly-run-dce -mllvm -polly-invariant-load-hoisting -flto=auto -mllvm -polly-run-inliner -mllvm -polly-run-dce -mllvm -polly-parallel -mllvm -polly-scheduling=dynamic -fno-emulated-tls -fwhole-program-vtables -fdata-sections -ffunction-sections -fmerge-all-constants -mllvm -polly-detect-keep-going -mllvm -polly-ast-use-context -march=armv8-a+simd -fvisibility=hidden -Wall -Wextra -fPIC -DPIC -ferror-limit=0 -Wno-return-type -Wno-unused-parameter -Wno-c++98-compat -Wno-c++98-compat-pedantic -DGLM_FORCE_INTRINSICS -mllvm -polly-omp-backend=LLVM -Wno-macro-redefined -Wno-gcc-compat -DDEFAULT_ES=3 -DNO_GBM -DNOX11 --error-limit=0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -pipe -integrated-as -mllvm -polly -mllvm -polly-vectorizer=stripmine -mllvm -polly-invariant-load-hoisting -mllvm -polly-run-inliner -mllvm -polly-run-dce -mllvm -polly-invariant-load-hoisting -flto=auto -mllvm -polly-run-inliner -mllvm -polly-run-dce -mllvm -polly-parallel -mllvm -polly-scheduling=dynamic -fno-emulated-tls -fwhole-program-vtables -fdata-sections -ffunction-sections -fmerge-all-constants -mllvm -polly-detect-keep-going -mllvm -polly-ast-use-context -march=armv8-a+simd -fPIC -DPIC -Wall -Wextra -ferror-limit=0 -Wno-return-type -Wno-unused-parameter -Wno-c++98-compat -Wno-c++98-compat-pedantic -DGLM_FORCE_INTRINSICS -fexceptions -fno-rtti -mllvm -polly-omp-backend=LLVM -Wno-macro-redefined -Wno-gcc-compat -DDEFAULT_ES=3 -DNO_GBM -DNOX11 --error-limit=0")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=lld -flto=auto -O3 -Wl,-plugin-opt=-emulated-tls=0 -Wl,--strip-all -fvisibility=hidden -Wl,-Bsymbolic -Wl,-O3 -Wl,--sort-common -Wl,--relax -Wl,--gc-sections -Wl,--as-needed --error-limit=0")

set(CMAKE_ANDROID_STL_TYPE c++_static)

set(CMAKE_BUILD_TYPE Release)

include_directories(${CMAKE_SOURCE_DIR}/include )

add_library(${CMAKE_PROJECT_NAME} SHARED
        src/gl/string_utils.c
        src/gl/cJSON.c
        src/gl/config.c
        src/gl/arbgenerator.c
        src/gl/arbhelper.c
        src/gl/arbparser.c
        src/gl/array.c
        src/gl/blend.c
        src/gl/blit.c
        src/gl/buffers.c
        src/gl/build_info.c
        src/gl/debug.c
        src/gl/decompress.c
        src/gl/depth.c
        src/gl/directstate.c
        src/gl/drawing.c
        src/gl/enable.c
        src/gl/envvars.c
        src/gl/eval.c
        src/gl/face.c
        src/gl/fog.c
        src/gl/fpe.c
        src/gl/fpe_cache.c
        src/gl/fpe_shader.c
        src/gl/framebuffers.c
        src/gl/gl_lookup.c
        src/gl/gl4es.c
        src/gl/glstate.c
        src/gl/hint.c
        src/gl/init.c
        src/gl/light.c
        src/gl/line.c
        src/gl/list.c
        src/gl/listdraw.c
        src/gl/listrl.c
        src/gl/loader.c
        src/gl/logs.c
        src/gl/matrix.c
        src/gl/matvec.c
        src/gl/oldprogram.c
        src/gl/pixel.c
        src/gl/planes.c
        src/gl/pointsprite.c
        src/gl/preproc.c
        src/gl/program.c
        src/gl/queries.c
        src/gl/raster.c
        src/gl/render.c
        src/gl/shader.c
        src/gl/shaderconv.c
        src/gl/shader_hacks.c
        src/gl/stack.c
        src/gl/stencil.c
        src/gl/stubs.c
        src/gl/texenv.c
        src/gl/texgen.c
        src/gl/texture.c
        src/gl/texture_compressed.c
        src/gl/texture_params.c
        src/gl/texture_read.c
        src/gl/texture_3d.c
        src/gl/uniform.c
        src/gl/vertexattrib.c
        src/gl/wrap/gl4eswraps.c
        src/gl/wrap/gles.c
        src/gl/wrap/glstub.c
        src/gl/math/matheval.cpp
        src/glx/hardext.c
        src/glx/glx.c
        src/glx/lookup.c
        src/glx/gbm.c
        src/glx/streaming.c
        src/gl/vgpu/shaderconv.c
        src/gl/vgpu/Initialization.cpp
        src/gl/vgpu/load.cpp
        src/gl/vgpu/pack.cpp
        src/gl/samplers.c
        src/gl/arbconverter.cpp
        src/glsl/glsl_for_es.cpp
        src/gl/getter.cpp
        )

find_library(GLSLANG_LIB glslang PATHS ${CMAKE_SOURCE_DIR}/libraries/arm64-v8a/)

target_link_libraries(ng_gl4es
        ${CMAKE_SOURCE_DIR}/libraries/arm64-v8a/libglslang.a
        ${CMAKE_SOURCE_DIR}/libraries/arm64-v8a/libspirv-cross-c-shared.so
        dl
        libomp.a
        )

target_include_directories(ng_gl4es PUBLIC
        ${CMAKE_SOURCE_DIR}/include
        )
