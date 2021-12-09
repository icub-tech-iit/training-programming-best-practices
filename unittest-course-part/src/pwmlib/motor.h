
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

//interface to motor
class Motor
{
   public:
	bool apply(double pwm) const
	{
        //...
		return true;
	};
};