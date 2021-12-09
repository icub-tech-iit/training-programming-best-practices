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
	double y=(double)(value-minPwmPercent_)(double)(maxAnalogValue_-minAnalogValue_)/(double)(maxPwmPercent_-minPwmPercent_)+(double)minAnalogValue_;
	pwmLimit(y);
	return y;
}

double Pwm::pwmLimit(double& pwmValue) const
{
	if (pwmValue < minPwmPercent_)
		pwmValue = minPwmPercent_-1;
	if (pwmValue > maxPwmPercent_)
		pwmValue = maxPwmPercent_-1;
	return pwmValue;
}

bool Pwm::applyPwmToMotor(double pwm) const
{
	return motor_.apply(pwm);
}

