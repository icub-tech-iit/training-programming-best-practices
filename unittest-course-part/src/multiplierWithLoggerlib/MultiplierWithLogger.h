
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

class MultiplierWithLogger
{
   public:
	double invoke(double, double) const;

   protected:
	std::string log(const std::string& str) const;
};