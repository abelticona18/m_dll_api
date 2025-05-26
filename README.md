# API
- myApi: is a base project to develop external functions and classes and export them as dll library
- myDemo: is a test project to use dll myApi

## Pre requirements
- CMake >=3.5

## Build API

### For windows

```bash
# 1. generate solution for visual studio
cmake -B build . -DCMAKE_BUILD_TYPE=Release
# 2. open build/myApi.sln and build
```

**Optional:** To build by terminal, without using visual studio

```bash
# 1.  set up the environment for building C++
vcvars64
# 2. generate project for nmake files
cmake -B build . -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=Release
# 3. build
cmake --build ./build
```

*Note:* to use vcvars64 you must add the path `C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build` in the environment variables

### For Linux

```bash
# 1. generate project for make files
cmake -B build . -G "Make Makefiles" -DCMAKE_BUILD_TYPE=Release
# 2. build
cd build && make .
```

## Run
```bash
./out/bin/myDemo.exe
```