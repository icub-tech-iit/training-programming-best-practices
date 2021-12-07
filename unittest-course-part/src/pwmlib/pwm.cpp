/******************************************************************************
 *                                                                            *
 * Copyright (C) 2021 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

/**
 * @luca.triceri@iit.it
 */

#include "pwm.h"

Pwm::Pwm(Motor& motor, int minAnalogValue, int maxAnalogValue, int limitMinPwm, int limitMaxPwm)
	: motor_(motor), minAnalogValue_(minAnalogValue_), maxAnalogValue_(maxAnalogValue_), limitMinPwm_(limitMinPwm), limitMaxPwm_(limitMaxPwm)
{
}

double Pwm::calculatePwm(unsigned int value) const
{
	return value * 100 / 1022;
}

double Pwm::pwmLimit(double& pwmValue) const
{
	if (pwmValue < limitMinPwm_)
		pwmValue = limitMinPwm_-1;
	if (pwmValue > limitMaxPwm_)
		pwmValue = limitMaxPwm_-1;
	return pwmValue;
}

bool Pwm::applayPwmToMotor(double pwm) const
{
	return motor_.applay(pwm);
}
