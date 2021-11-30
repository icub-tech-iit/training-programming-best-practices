/******************************************************************************
 *                                                                            *
 * Copyright (C) 2021 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

/**
 * @luca.triceri@iit.it
 */

#include "MultiplierFromFile.h"

#include <cstdlib>
#include <ctime>
#include <fstream>

double MultiplierFromFile::invoke(unsigned int leftIndex, unsigned int rightIndex) const
{
	return getDataFromFile(1) * getDataFromFile(2);
}

double MultiplierFromFile::getDataFromFile(unsigned int) const
{
	std::ifstream ifs("data.txt");
	double out;
	ifs >> out;
	return out;
}

double MultiplierFromFile::getDataFromFile(unsigned int, unsigned int) const
{
	return 0;
}