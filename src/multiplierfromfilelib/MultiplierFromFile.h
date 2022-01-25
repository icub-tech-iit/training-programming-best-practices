
/******************************************************************************
 *                                                                            *
 * Copyright (C) 2021 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

/**
 * @luca.triceri@iit.it
 */

#pragma once

#include <string>

class MultiplierFromFile
{
   public:
	explicit MultiplierFromFile(const std::string &fileName) : fileName_(fileName){};
	double invoke(unsigned int leftIndex, unsigned int rightIndex) const;
	double invoke2(unsigned int leftIndex, unsigned int rightIndex) const;
	double invoke3(unsigned int leftIndex, unsigned int rightIndex) const;

   private:
	virtual double getDataFromFile(unsigned int index) const;
	virtual double getDataFromFile(unsigned int index, double* out) const;
	virtual double getDataFromFile(unsigned int index, double& out) const;
	const std::string fileName_;
};