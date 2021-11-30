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

// Simple UT

TEST(Multiplier, Test_simple001)
{
	Multiplier mult;
	// EXPECT_EQ(expected,actual);<<<----expected,actual
	EXPECT_EQ(2, mult.invoke(1, 2));
    // ASSERT_FALSE(mult.invoke(1, 2) == 2);
}

TEST(Multiplier, Test_simple002)
{
	Multiplier mult;
	EXPECT_NE(3, mult.invoke(1, 2));
}

TEST(Multiplier, Test_simple003)
{
	Multiplier mult;
	EXPECT_LT(1, mult.invoke(1, 2));
}

TEST(Multiplier, Test_simple004)
{
	Multiplier mult;
	EXPECT_GT(3, mult.invoke(1, 2));

	EXPECT_TRUE(mult.invoke(1, 2) == 2);
	EXPECT_FALSE(mult.invoke(1, 2) == 3);
}

TEST(Multiplier, Test_exception)
{
	Multiplier mult;
	EXPECT_THROW(mult.invoke(10, 2), std::invalid_argument);
}
