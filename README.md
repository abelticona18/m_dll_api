# API

```
m_cpp_haptic/

├── demoCpp
│   ├── CMakeLists.txt
│   └── src
├── demoCsharp
│   ├── demoCsharp.csproj
│   └── Program.cs
├── myApi
│   ├── CMakeLists.txt
│   └── src
├── out
├── CMakeLists.txt
├── common.cmake
├── DemoCsharp.sln
└── README.md

```
- **myApi**: is a c++ project to develop external functions and classes and export them as dll library
- **demoCpp**: is a c++ project to test myApi.dll
- **demoCsharp**: is a c# project to use myApi.dll
- **out**: contains dlls, libs and headers

## Pre requirements
- CMake 3.5 <=
- .NET 6.0 <=

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
# 3. build (generate dll)
cmake --build ./build myApp
# 4. to generate the headers (only for c++)
cmake --install ./build
```

*Note:* to use vcvars64 you must add the path `C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build` in the environment variables

### For Linux

```bash
# 1. generate project for make files
cmake -B build . -G "Make Makefiles" -DCMAKE_BUILD_TYPE=Release
# 2. build
cd build && make .
```

## Build & Run Demos
### demoCpp
```bash
# build
cmake --build ./build demoCpp
# run
./out/bin/myDemo.exe
```

### demoCsharp
```bash
cd demoCsharp
# build & run
dotnet run
```