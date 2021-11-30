/******************************************************************************
 *                                                                            *
 * Copyright (C) 2021 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

/**
 * @luca.triceri@iit.it
 */

#include "MultiplierWithLogger.h"

double MultiplierWithLogger::invoke(double left, double right) const
{
	return left * right;
}

std::string MultiplierWithLogger::log(const std::string& str) const
{
	std::string out;
	out="Severity Debug: "+str;
	return out;
}