# eldenring.cpp

Elden Ring C++ bindings for mod creation and reverse engineering. Headers mostly generated from vswarte/fromsoftware-rs.

See `examples/` directory on how to use the project.

## Quick start (CMake)

```bash
git clone --recursive https://github.com/AlpinDale/eldenring.cpp
```

```cmake
FetchContent_Declare(eldenring_cpp
  GIT_REPOSITORY https://github.com/AlpinDale/eldenring.cpp
  GIT_TAG v0.0.1
)
FetchContent_MakeAvailable(eldenring_cpp)

target_link_libraries(my_mod PRIVATE eldenring::eldenring_cpp)
```

## Building examples

Examples are Windows-only and off by default:

```
cmake -S . -B build -DELDENRING_CPP_BUILD_EXAMPLES=ON
cmake --build build --config Release
```

Outputs are placed under `build/examples/`. See `examples/README.md` for usage.

## Scope

This project provides **low-level ABI layouts** (structs/enums/aliases) generated from
vswarte/fromsoftware-rs. It does **not** include the Rust crate's higher-level APIs
(singleton lookup, RVA helpers, task wrappers, input helpers, etc). Those behaviors
are still possible in C++, but you must implement the glue yourself. In the future,
those APIs will be re-implemented in this project.

## Contributing

If you want to contribute to this repo:

- fork the repo
- recursively pull your fork
- make your changes
- run the formatter:
```
cmake --build build --target format
```
- stage and commit your changes
- push and open a PR

Thanks for your interest.
