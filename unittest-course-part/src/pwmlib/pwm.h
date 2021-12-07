
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

class Motor
{
   public:
	bool applay(double pwm) const
	{
		return true;
	};
};

class Pwm
{
   public:
	Pwm(Motor& motor, int minAnalogValue, int maxAnalogValue, int limitMinPwm, int limitMaxPwm);
	double calculatePwm(unsigned int value) const;	// return a proportional pwm value for in
	double pwmLimit(double& pwmValue) const;				// limit pwm
	bool applayPwmToMotor(double pwm) const;		// limit pwm

   protected:
	int minAnalogValue_{0};
	int maxAnalogValue_{1023};
	int limitMinPwm_{0};
	int limitMaxPwm_{100};
	Motor& motor_;
};