# Template: C++, CMake, and vcpkg

Based on [this blog post](https://sam.elborai.me/blog/vscode-cpp-dev-environment-2020) where I describe how to setup a modern and cross-platform C++ environment.

Features:

- CMake config for library, executable, and test.
- Depends on Catch2 and fmt installed from vcpkg.
- VSCode setup (config and extension recommendations)

Note (from [the author](https://github.com/dgellow)): Some of my personal settings are hardcoded.


## Build

First configure via `cmake` (where `DCMAKE_TOOLCHAIN_FILE` matches your vcpkg path):

```
$ cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=C:/Users/Sam/Development/vcpkg/scripts/buildsystems/vcpkg.cmake
```

If that was successful, build via `cmake --build`:

```
$ cmake --build build
$ ./build/Debug/main.exe
Greetings stranger. Or should I say: Hello world!
```

Run tests via `ctest`:

```
$ cd build
$ ctest --output-on-failure
```
