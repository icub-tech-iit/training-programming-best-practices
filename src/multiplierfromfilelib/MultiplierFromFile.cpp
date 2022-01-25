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
	return getDataFromFile(leftIndex) * getDataFromFile(rightIndex);
}

double MultiplierFromFile::invoke2(unsigned int leftIndex, unsigned int rightIndex) const
{
	double out1;
	double out2;
	getDataFromFile(leftIndex,out1);
	getDataFromFile(rightIndex,out2);
	return out1 * out2;
}

double MultiplierFromFile::invoke3(unsigned int leftIndex, unsigned int rightIndex) const
{
	double out1,out2;
	getDataFromFile(leftIndex,&out1);
	getDataFromFile(rightIndex,&out2);
	return out1 * out2;

}

double MultiplierFromFile::getDataFromFile(unsigned int index) const
{
	std::ifstream ifs(fileName_);
	//go to line by index
	std::string s;
	for (int i = 1; i < index; i++)
        std::getline(ifs, s);
	//...
	double out;
	ifs >> out;
	return out;
}

double MultiplierFromFile::getDataFromFile(unsigned int index, double* out) const
{
	std::ifstream ifs(fileName_);
	//go to line by index
	std::string s;
	for (int i = 1; i < index; i++)
        std::getline(ifs, s);
	//...
	double outFromFile;
	ifs >> outFromFile;
	*out = outFromFile;
	return *out;
}

double MultiplierFromFile::getDataFromFile(unsigned int index, double& out) const
{
	std::ifstream ifs(fileName_);
	//go to line by index
	std::string s;
	for (int i = 1; i < index; i++)
        std::getline(ifs, s);
	//...
	double outFromFile;
	ifs >> outFromFile;
	out = outFromFile;
	return out;
}