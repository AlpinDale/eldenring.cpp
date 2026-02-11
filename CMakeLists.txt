cmake_minimum_required(VERSION 3.20)
project(eldenring_cpp LANGUAGES CXX)

add_library(eldenring_cpp INTERFACE)
add_library(eldenring::eldenring_cpp ALIAS eldenring_cpp)

target_include_directories(eldenring_cpp INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_features(eldenring_cpp INTERFACE cxx_std_17)

include(CTest)
option(ELDENRING_CPP_BUILD_EXAMPLES "Build eldenring.cpp examples" OFF)
set(ELDENRING_CPP_FSRS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/third_party/fromsoftware-rs"
    CACHE PATH "Path to fromsoftware-rs (repo root)")

if(EXISTS "${ELDENRING_CPP_FSRS_DIR}/Cargo.toml")
    add_custom_target(eldenring_cpp_generate
        COMMAND cargo run --release -- --fsrs "${ELDENRING_CPP_FSRS_DIR}"
                --out "${CMAKE_CURRENT_SOURCE_DIR}/include/eldenring"
        COMMAND cargo run --release --bin api_gen -- --fsrs "${ELDENRING_CPP_FSRS_DIR}"
                --out "${CMAKE_CURRENT_SOURCE_DIR}/include/eldenring"
                --report "${CMAKE_CURRENT_SOURCE_DIR}/api_parity_report.md"
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/tools/generate"
        COMMENT "Regenerating eldenring.cpp headers"
        VERBATIM
    )
else()
    message(STATUS "fromsoftware-rs not found at ${ELDENRING_CPP_FSRS_DIR} (generator target disabled)")
endif()

find_program(CLANG_FORMAT_EXE NAMES clang-format)
if(CLANG_FORMAT_EXE)
    if(WIN32)
        add_custom_target(format
            COMMAND powershell -NoProfile -ExecutionPolicy Bypass
                -File "${CMAKE_CURRENT_SOURCE_DIR}/tools/format.ps1"
            WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
            COMMENT "Running clang-format"
        )
    else()
        add_custom_target(format
            COMMAND bash "${CMAKE_CURRENT_SOURCE_DIR}/tools/format.sh"
            WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
            COMMENT "Running clang-format"
        )
    endif()
else()
    message(STATUS "clang-format not found; format target disabled")
endif()

if(BUILD_TESTING)
    add_executable(eldenring_cpp_header_smoke tests/header_smoke.cpp)
    target_link_libraries(eldenring_cpp_header_smoke PRIVATE eldenring_cpp)
    target_compile_features(eldenring_cpp_header_smoke PRIVATE cxx_std_17)
    add_test(NAME eldenring_cpp_header_smoke COMMAND eldenring_cpp_header_smoke)
endif()

if(ELDENRING_CPP_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
