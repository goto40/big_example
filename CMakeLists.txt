cmake_minimum_required(VERSION 2.8)
project(big_example)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(oatpp 1.3.0 REQUIRED)
find_package(oatpp-swagger 1.3.0 REQUIRED)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules ${CMAKE_MODULE_PATH})

include(Version) 
find_path(CATCH_INCLUDE_PATH catch.hpp REQUIRED)

include(CTest)
enable_testing()

file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE TST test/*.cpp)
file(GLOB_RECURSE OAT_TST oat_test/*.cpp)
file(GLOB EXAMPLES examples/*.cpp)

add_library(${PROJECT_NAME} ${SRC} ${version_file})
target_include_directories(${PROJECT_NAME} PUBLIC src)
target_link_libraries(${PROJECT_NAME}
    PUBLIC oatpp::oatpp
    PUBLIC oatpp::oatpp-swagger
)

add_definitions(-DOATPP_SWAGGER_RES_PATH="${OATPP_BASE_DIR}/bin/oatpp-swagger/res")
add_definitions(-DSWAGGER_ROOT_PATH="${OATPP_SWAGGER_RES_PATH}")
add_definitions(-DSWAGGER_UI_PATH="ui")

set(EXE_NAME "${PROJECT_NAME}.exe")
foreach(CPPFILE ${EXAMPLES})
    get_filename_component(EXE_NAME ${CPPFILE} NAME_WLE)
    add_executable(${EXE_NAME} ${CPPFILE})
    target_include_directories(${PROJECT_NAME} PRIVATE src)
    target_link_libraries(${EXE_NAME} ${PROJECT_NAME})
endforeach()

set(UNITTEST "${PROJECT_NAME}_unit_tests")
add_executable(${UNITTEST} ${TST})
target_include_directories(${UNITTEST} PRIVATE src)
target_include_directories(${UNITTEST} PRIVATE test)
target_include_directories(${UNITTEST} PRIVATE ${CATCH_INCLUDE_PATH})
target_link_libraries(${UNITTEST} ${PROJECT_NAME})

add_test(NAME unittest COMMAND ${UNITTEST})

set(OAT_UNITTEST "${PROJECT_NAME}_oat_unit_tests")
add_executable(${OAT_UNITTEST} ${OAT_TST})
target_include_directories(${OAT_UNITTEST} PRIVATE src)
target_include_directories(${OAT_UNITTEST} PRIVATE oat_test)
target_link_libraries(${OAT_UNITTEST} ${PROJECT_NAME})
target_link_libraries(${OAT_UNITTEST} PUBLIC oatpp::oatpp-test)

add_test(NAME oat_unittest COMMAND ${OAT_UNITTEST})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
