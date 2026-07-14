cmake_minimum_required(VERSION 3.20)

project(cpp-basics LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB_RECURSE APP_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

foreach(SOURCE_FILE ${APP_SOURCES})

    # Executable name (filename without extension)
    get_filename_component(EXE_NAME ${SOURCE_FILE} NAME_WE)

    # Directory relative to src/
    get_filename_component(SRC_DIR ${SOURCE_FILE} DIRECTORY)
    file(RELATIVE_PATH REL_DIR
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
        "${SRC_DIR}"
    )

    add_executable(${EXE_NAME} ${SOURCE_FILE})

    # Corresponding include directory
    if(REL_DIR STREQUAL "")
        set(INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
    else()
        set(INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/${REL_DIR}")
    endif()

    if(REL_DIR STREQUAL "")
        set(OUTPUT_DIR "${CMAKE_BINARY_DIR}")
    else()
        set(OUTPUT_DIR "${CMAKE_BINARY_DIR}/${REL_DIR}")
    endif()

    set_target_properties(${EXE_NAME}
        PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}"
    )

    if(EXISTS "${INC_DIR}")
        target_include_directories(${EXE_NAME} PRIVATE ${INC_DIR})
    endif()

endforeach()