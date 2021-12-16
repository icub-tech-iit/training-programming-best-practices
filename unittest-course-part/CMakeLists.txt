################################################################################
#                                                                              #
# Copyright (C) 2021 Fondazione Istitito Italiano di Tecnologia (IIT)          #
# All Rights Reserved.                                                         #
#                                                                              #
################################################################################

# @author Luca Tricerri <luca.tricerri@iit.it>

include(FetchContent)
cmake_minimum_required(VERSION 3.16)

project(unittesttraining)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


FetchContent_Declare(
  unittest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)
FetchContent_GetProperties(unittest)
if(NOT unittest)
  FetchContent_Populate(unittest)
  add_subdirectory(src/unittest)
  add_subdirectory(${unittest_SOURCE_DIR} ${unittest_BINARY_DIR})
endif()


add_subdirectory(src)

