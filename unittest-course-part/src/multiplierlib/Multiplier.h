
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

class Multiplier
{
   public:
	double invoke(double, double) const;

   protected:
	virtual double internalInvoke(double, double) const;
};