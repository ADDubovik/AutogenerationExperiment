cmake_minimum_required(VERSION 3.7)
project(AutogenerationExperiment)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set (BRAND_FULLNAME "AutogenerationExperiment")
set (BRAND_COMPANYNAME "ADDubovik")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set (SRC
	CopyMoveSemanticsHelpers.h
	main.cpp
)

add_executable(${PROJECT_NAME} ${SRC})
