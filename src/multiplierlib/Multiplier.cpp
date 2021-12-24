/******************************************************************************
 *                                                                            *
 * Copyright (C) 2021 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

/**
 * @luca.triceri@iit.it
 */

#include "Multiplier.h"
#include <stdexcept>

double Multiplier::invoke(double left, double right) const
{
	if(left==10)
	{
		throw std::invalid_argument("Wrong left argument");
	}
	return internalInvoke(left,right);
}

double Multiplier::internalInvoke(double left, double right) const
{
	return left * right;
}