/******************************************************************************
 *                                                                            *
 * Copyright (C) 2020 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

/**
 * @luca.triceri@iit.it
 */ 

#include <cstdlib>
#include <ctime>

#include "MultiplierFromDb.h"

double MultiplierFromDb::invoke(unsigned int leftIndex,unsigned int rightIndex) const
{
    return getData(1)*getData(2);
}

double MultiplierFromDb::getData(unsigned int index) const
{
    std::srand(std::time(nullptr));
    return std::rand()%10;
}