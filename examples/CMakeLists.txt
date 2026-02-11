if(NOT WIN32)
  message(STATUS "eldenring.cpp examples are Windows-only; skipping.")
else()
  set(ERD_EXAMPLE_OUT_DIR "${CMAKE_BINARY_DIR}/examples")

  add_library(erd_example_common STATIC
    common/pattern_scan.cpp
    common/example_util.cpp
  )
  target_include_directories(erd_example_common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/common)
  target_compile_features(erd_example_common PRIVATE cxx_std_17)
  target_compile_definitions(erd_example_common PRIVATE WIN32_LEAN_AND_MEAN NOMINMAX)
  target_link_libraries(erd_example_common PRIVATE eldenring_cpp version)

  function(add_erd_example target)
    add_library(${target} SHARED ${ARGN})
    target_link_libraries(${target} PRIVATE eldenring_cpp erd_example_common)
    target_compile_features(${target} PRIVATE cxx_std_17)
    target_compile_definitions(${target} PRIVATE WIN32_LEAN_AND_MEAN NOMINMAX)
    set_target_properties(${target} PROPERTIES
      OUTPUT_NAME ${target}
      RUNTIME_OUTPUT_DIRECTORY "${ERD_EXAMPLE_OUT_DIR}/${target}"
      LIBRARY_OUTPUT_DIRECTORY "${ERD_EXAMPLE_OUT_DIR}/${target}"
      ARCHIVE_OUTPUT_DIRECTORY "${ERD_EXAMPLE_OUT_DIR}/${target}"
      RUNTIME_OUTPUT_DIRECTORY_RELEASE "${ERD_EXAMPLE_OUT_DIR}/${target}"
      LIBRARY_OUTPUT_DIRECTORY_RELEASE "${ERD_EXAMPLE_OUT_DIR}/${target}"
      ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${ERD_EXAMPLE_OUT_DIR}/${target}"
    )
  endfunction()

  add_erd_example(erd_example_apply_speffect apply-speffect/dllmain.cpp)
  add_erd_example(erd_example_player_info player-info/dllmain.cpp)

  add_executable(erd_example_launcher launcher/main.cpp)
  target_compile_features(erd_example_launcher PRIVATE cxx_std_17)
  target_compile_definitions(erd_example_launcher PRIVATE WIN32_LEAN_AND_MEAN NOMINMAX)
  set_target_properties(erd_example_launcher PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${ERD_EXAMPLE_OUT_DIR}"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${ERD_EXAMPLE_OUT_DIR}"
  )
endif()
