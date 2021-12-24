################################################################################
#                                                                              #
# Copyright (C) 2021 Fondazione Istitito Italiano di Tecnologia (IIT)          #
# All Rights Reserved.                                                         #
#                                                                              #
################################################################################

# @author Luca Tricerri <luca.tricerri@iit.it>

include(CMakePackageConfigHelpers)

set(LIBRARY_TARGET_NAME multiplier)

set(MultiplierSrc    Multiplier.cpp
                        )

set(MultiplierHdr   Multiplier.h
                       )

add_library(${LIBRARY_TARGET_NAME} STATIC ${MultiplierSrc} ${MultiplierHdr})
add_library(${PROJECT_NAME}::${LIBRARY_TARGET_NAME} ALIAS ${LIBRARY_TARGET_NAME})
target_link_libraries(${LIBRARY_TARGET_NAME} PUBLIC ${Common_LIBRARIES})

target_include_directories(${LIBRARY_TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
                                                         "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${LIBRARY_TARGET_NAME}>")

install(TARGETS ${LIBRARY_TARGET_NAME}
        EXPORT ${LIBRARY_TARGET_NAME}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${LIBRARY_TARGET_NAME})
