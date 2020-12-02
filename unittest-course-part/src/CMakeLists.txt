################################################################################
#                                                                              #
# Copyright (C) 2019 Fondazione Istitito Italiano di Tecnologia (IIT)          #
# All Rights Reserved.                                                         #
#                                                                              #
################################################################################

# @author Nicolo Genesio <nicolo.genesio@iit.it> ,Luca Tricerri <luca.tricerri@iit.it>

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(COMPILE_WITHUNITTEST "Compile also unittest" ON)

if(COMPILE_WITHUNITTEST)
  FetchContent_Declare(
    unittest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.10.0
  )
  FetchContent_GetProperties(unittest)
  if(NOT unittest)
    FetchContent_Populate(unittest)
    add_subdirectory(unittest)
    add_subdirectory(${unittest_SOURCE_DIR} ${unittest_BINARY_DIR})
  endif()
endif()

add_subdirectory(multiplierlib)
