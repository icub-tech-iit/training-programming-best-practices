/******************************************************************************
 *                                                                            *
 * Copyright (C) 2020 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

/**
 * @luca.triceri@iit.it
 */

#include "gtest/gtest.h"

#include "Multiplier.h"

TEST(Multiplier, Test_001)
{

    Multiplier mult;
    EXPECT_EQ(mult.invoke(1, 2), 2);
    EXPECT_TRUE(mult.invoke(1, 2) == 2);
    EXPECT_FALSE(mult.invoke(1, 2) == 3);
}
