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
#include "gtest/gtest.h"

// Simple UT with internal functions

class TestMultiplier : public Multiplier
{
   public:
	using Multiplier::internalInvoke;
};

TEST(InternalMultiplier, Test_simple001)
{
	TestMultiplier mult;
	EXPECT_EQ(2,mult.internalInvoke(1, 2));
	EXPECT_TRUE(mult.internalInvoke(1, 2) == 2);
	EXPECT_FALSE(mult.internalInvoke(1, 2) == 3);
}

TEST(InternalMultiplier, Test_simple002)
{
	TestMultiplier mult;
	EXPECT_TRUE(mult.internalInvoke(1, 2) == 2);
	EXPECT_FALSE(mult.internalInvoke(1, 2) == 3);
}
