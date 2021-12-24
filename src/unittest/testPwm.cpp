/******************************************************************************
 *                                                                            *
 * Copyright (C) 2021 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

/**
 * @luca.triceri@iit.it
 */

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "motor.h"
#include "pwm.h"

using namespace testing;
using ::testing::_;
using ::testing::An;
using ::testing::Gt;
using ::testing::InSequence;
using ::testing::InvokeArgument;
using ::testing::Matcher;
using ::testing::TypedEq;

class Motor_Mock : public Motor
{
   public:
	MOCK_METHOD(bool, apply, (double), (const, override));
};

TEST(MotorFile, Test_base_001)
{
	Motor_Mock motor;

	Pwm pwm(motor, 0, 1023, 0, 100);

	EXPECT_CALL(motor, apply(20)).Times(1);

    pwm.applyPwmToMotor(20);

}