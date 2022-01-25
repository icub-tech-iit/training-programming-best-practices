################################################################################
#                                                                              #
# Copyright (C) 2021 Fondazione Istitito Italiano di Tecnologia (IIT)          #
# All Rights Reserved.                                                         #
#                                                                              #
################################################################################

# @author Luca Tricerri <luca.tricerri@iit.it> 

project(unittest)

set(SOURCES gtest_main.cc
            testMultiplier.cpp
            testMultiplierInternal.cpp
            testMultiplierFromFile.cpp
            testPwm.cpp
            testMediaScanner.cpp
            testDivision.cpp
            testMultiplierParamAndFixture.cpp
            )

set(CMAKE_EXE_LINKER_FLAGS  "-rdynamic")
set(CMAKE_INSTALL_RPATH ./)

add_executable(${PROJECT_NAME} ${SOURCES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME}  udev gtest gmock multiplier multiplierfromfile pwm mediascanner division)

# install
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})