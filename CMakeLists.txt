cmake_minimum_required(VERSION 3.28)

project(splash-start)

find_package(PkgConfig REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)


add_executable(splash-start)
target_sources(splash-start PRIVATE
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)
target_compile_features(splash-start PRIVATE 
    cxx_std_23
)
target_link_libraries(splash-start PUBLIC 
    ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} SDL2_image
)
target_include_directories(splash-start PRIVATE 
    ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} 
)