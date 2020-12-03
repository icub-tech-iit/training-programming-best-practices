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
#include "gmock/gmock.h"

#include "MultiplierFromDb.h"

using namespace testing;
using ::testing::_;
using ::testing::InvokeArgument;
using ::testing::Matcher;

class MultiplierFromDb_Mock : public MultiplierFromDb
{
public:
    MOCK_METHOD(double, getDataFromDb, (unsigned int), (const, override));

    MultiplierFromDb_Mock(const std::string &name) : MultiplierFromDb(name)
    {
    }
};

TEST(MultiplierFromDb, Test_001)
{

    MultiplierFromDb_Mock mult("Luca");

    EXPECT_CALL(mult, getDataFromDb(1)).Times(1);
    EXPECT_CALL(mult, getDataFromDb(2)).Times(1);

    mult.invoke(1, 2);
}

TEST(MultiplierFromDb, Test_002)
{

    MultiplierFromDb_Mock mult("Luca");

    EXPECT_CALL(mult, getDataFromDb(1)).WillOnce(Return(10));
    EXPECT_CALL(mult, getDataFromDb(2)).WillOnce(Return(11));

    EXPECT_EQ(mult.invoke(1, 2), 110);
}
