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

Pwm::Pwm(Motor& motor, int minAnalogValue, int maxAnalogValue, int minPwmPercent, int maxPwmPercent)
	: motor_(motor), minAnalogValue_(minAnalogValue_), maxAnalogValue_(maxAnalogValue_), minPwmPercent_(minPwmPercent), maxPwmPercent_(maxPwmPercent)
{
}

double Pwm::calculatePwmFromPercent(unsigned int pwmPercent) const
{
	double pwmValue=(double)(pwmPercent-minPwmPercent_)*(double)(maxAnalogValue_-minAnalogValue_)/(double)(maxPwmPercent_-minPwmPercent_)+(double)minAnalogValue_;
	pwmLimit(pwmValue);
	return pwmValue;
}

double Pwm::pwmLimit(double& pwmValue) const
{
	if (pwmValue <= minAnalogValue_)
		pwmValue = minAnalogValue_;
	if (pwmValue >= maxAnalogValue_)
		pwmValue = maxAnalogValue_;
	return pwmValue;
}

bool Pwm::applyPwmToMotor(double pwm) const
{
	return motor_.apply(pwm);
}

