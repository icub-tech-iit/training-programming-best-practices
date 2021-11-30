/******************************************************************************
 *                                                                            *
 * Copyright (C) 2021 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

/**
 * @luca.triceri@iit.it
 */

#include "MultiplierFromFile.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace testing;
using ::testing::_;
using ::testing::InvokeArgument;
using ::testing::Matcher;

class MultiplierFromFile_Mock : public MultiplierFromFile
{
   public:	// always public
	MOCK_METHOD(double, getDataFromFile, (unsigned int), (const, override));  // note round the parentesis

	MultiplierFromFile_Mock(const std::string &name) : MultiplierFromFile(name)
	{
	}
};

TEST(MultiplierFromFile, Test_times_001)
{
	MultiplierFromFile_Mock mult("Luca");

	EXPECT_CALL(mult, getDataFromFile(1)).Times(1);
	EXPECT_CALL(mult, getDataFromFile(2)).Times(1);

	mult.invoke(1, 2);
}

TEST(MultiplierFromFile, Test_return_001)
{
	MultiplierFromFile_Mock mult("Luca");

	EXPECT_CALL(mult, getDataFromFile(1)).WillOnce(Return(10));
	EXPECT_CALL(mult, getDataFromFile(2)).WillOnce(Return(11));

	EXPECT_EQ(mult.invoke(1, 2), 110);
}
