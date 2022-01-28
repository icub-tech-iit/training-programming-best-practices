
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
#include "motor.h"

class Pwm
{
   public:
	Pwm(Motor& motor, int minAnalogValue, int maxAnalogValue, int limitMinPwmPercent, int limitMaxPwmPercent);
	double calculatePwmFromPercent(unsigned int pwmPercent) const;	// return a proportional pwm value for in
	bool applyPwmToMotor(double pwm) const;							// apply pwm to motor

   protected:
	int minAnalogValue_{0};
	int maxAnalogValue_{1023};
	int minPwmPercent_{0};
	int maxPwmPercent_{100};
	Motor& motor_;

	double pwmLimit(double& pwmValue) const;						// limit pwm
};