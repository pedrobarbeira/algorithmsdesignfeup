cmake_minimum_required(VERSION 3.17)
project(AD_TP_Classes)

# Build the Google tests
set(GOOGLETEST_PATH lib/googletest-master)
add_subdirectory(${GOOGLETEST_PATH})

# Add the source files of each TP class
file(GLOB TP1_FILES CONFIGURE_DEPENDS "tp1/*.cpp")
file(GLOB TP2_FILES CONFIGURE_DEPENDS "tp2a/*.cpp" "tp2b/*.cpp")
file(GLOB TP3_FILES CONFIGURE_DEPENDS "tp3a/*.cpp" "tp3b/*.cpp")
file(GLOB TP4_FILES CONFIGURE_DEPENDS "tp4/*.cpp")
file(GLOB TP5_FILES CONFIGURE_DEPENDS "tp5/*.cpp")
file(GLOB TP6_FILES CONFIGURE_DEPENDS "tp6/*.cpp")
file(GLOB TP7_FILES CONFIGURE_DEPENDS "tp7/*.cpp")
#...

add_executable(TP1 main.cpp ${TP1_FILES} tp7/ex1.cpp tp7/exercises.h tp4/ex1.cpp)
add_executable(TP2 main.cpp ${TP2_FILES})
add_executable(TP3 main.cpp ${TP3_FILES})
add_executable(TP4 main.cpp ${TP4_FILES})
add_executable(TP5 main.cpp ${TP5_FILES})
add_executable(TP6 main.cpp ${TP6_FILES})
add_executable(TP7 main.cpp ${TP7_FILES})
#...

target_link_libraries(TP1 gtest_main gmock_main)
target_link_libraries(TP2 gtest_main gmock_main)
target_link_libraries(TP3 gtest_main gmock_main)
target_link_libraries(TP4 gtest_main gmock_main)
target_link_libraries(TP5 gtest_main gmock_main)
target_link_libraries(TP6 gtest_main gmock_main)
target_link_libraries(TP7 gtest_main gmock_main)
#...