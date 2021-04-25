cmake_minimum_required(VERSION 3.10)

# set the project name
project(mere-config-lite
        VERSION 0.0.1.1
        DESCRIPTION "A simple lightweight configuration library."
        HOMEPAGE_URL "https://config.merelabs.io"
        LANGUAGES C CXX)

#
cmake_host_system_information(RESULT HOSTNAME QUERY FQDN)
message(STATUS "Preparing build on ${HOSTNAME}")
message(STATUS "    System    : ${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_VERSION}")
message(STATUS "    Processor : ${CMAKE_HOST_SYSTEM_PROCESSOR}")

configure_file(Configure.h.in Configure.h)

# specify the mode
set(CMAKE_BUILD_TYPE Release)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

#set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


find_package(Qt5 COMPONENTS Core REQUIRED)
#find_package(mere-utils REQUIRED COMPONENTS utils )

file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS src/*.h)

# Create shared library
add_library(${PROJECT_NAME} SHARED ${SOURCES})

#target_include_directories(${PROJECT_NAME} PRIVATE src)
target_include_directories(${PROJECT_NAME} PUBLIC /usr/local/include)

#
# Install
#
install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION lib)

#install(FILES ${HEADERS} DESTINATION include/mere/config)
install(DIRECTORY "./src/" DESTINATION "include/mere/config" FILES_MATCHING PATTERN "*.h")
#
# Linking
#
target_link_libraries(${PROJECT_NAME} Qt5::Core)
