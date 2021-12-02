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
using ::testing::Gt;
using ::testing::InSequence;
using ::testing::InvokeArgument;
using ::testing::Matcher;
using ::testing::An;
using ::testing::TypedEq;

class MultiplierFromFile_Mock : public MultiplierFromFile
{
   public:																	  // always public
	MOCK_METHOD(double, getDataFromFile, (unsigned int), (const, override));  // note the parentesis
	MOCK_METHOD(double, getDataFromFile, (unsigned int,double*), (const, override));  // note the parentesis
	MOCK_METHOD(double, getDataFromFile, (unsigned int,double&), (const, override));  // note the parentesis

	MultiplierFromFile_Mock(const std::string &name) : MultiplierFromFile(name)
	{
	}
};

TEST(MultiplierFromFile, Test_base_001)
{
	MultiplierFromFile_Mock mult("Luca");

	EXPECT_CALL(mult, getDataFromFile(1));
	EXPECT_CALL(mult, getDataFromFile(2));

	mult.invoke(1, 2);
}

TEST(MultiplierFromFile, Test_times_001)
{
	MultiplierFromFile_Mock mult("Luca");

	EXPECT_CALL(mult, getDataFromFile(1)).Times(1);
	EXPECT_CALL(mult, getDataFromFile(2)).Times(1);

	mult.invoke(1, 2);
}

TEST(MultiplierFromFile, Test_times_002)
{
	MultiplierFromFile_Mock mult("Luca");
	EXPECT_CALL(mult, getDataFromFile(1)).Times(AnyNumber());
	EXPECT_CALL(mult, getDataFromFile(2)).Times(AnyNumber());

	mult.invoke(1, 2);
}

TEST(MultiplierFromFile, Test_match_001)
{
	MultiplierFromFile_Mock mult("Luca");

	EXPECT_CALL(mult, getDataFromFile(_)).Times(2);

	mult.invoke(1, 2);
}

TEST(MultiplierFromFile, Test_match_002)
{
	MultiplierFromFile_Mock mult("Luca");

	EXPECT_CALL(mult, getDataFromFile(Gt(0))).Times(2);

	mult.invoke(1, 2);
}

TEST(MultiplierFromFile, Test_sequence_001)
{
	MultiplierFromFile_Mock mult("Luca");

	InSequence s;
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

TEST(MultiplierFromFile, Test_return_002)
{
	MultiplierFromFile_Mock mult("Luca");

	EXPECT_CALL(mult, getDataFromFile(_)).WillRepeatedly(Return(9));

	EXPECT_EQ(mult.invoke(1, 2), 81);
}

TEST(MultiplierFromFile, Test_returnparam_001)
{
	MultiplierFromFile_Mock mult("Luca");

	EXPECT_CALL(mult, getDataFromFile(_,An<double&>())).WillRepeatedly(SetArgReferee<1>(5));

	EXPECT_EQ(mult.invoke2(1, 2), 25);
}

TEST(MultiplierFromFile, Test_returnparam_002)
{
	MultiplierFromFile_Mock mult("Luca");

	double a=5;
	EXPECT_CALL(mult, getDataFromFile(1,An<double&>())).WillOnce(DoAll(SetArgReferee<1>(a),Return(1)));
	EXPECT_CALL(mult, getDataFromFile(2,An<double&>())).WillOnce(DoAll(SetArgReferee<1>(a),Return(1)));

	EXPECT_EQ(mult.invoke2(1, 2), 25);
}

TEST(MultiplierFromFile, Test_returnparam_003)
{
	MultiplierFromFile_Mock mult("Luca");

	EXPECT_CALL(mult, getDataFromFile(_,An<double&>())).WillRepeatedly(DoAll(SetArgReferee<1>(5),Return(1)));

	EXPECT_EQ(mult.invoke2(1, 2), 25);
}

/*
TEST(MultiplierFromFile, Test_returnparam_004)
{
	MultiplierFromFile_Mock mult("Luca");

	EXPECT_CALL(mult, getDataFromFile(_,An<double*>())).WillRepeatedly(SetArgPointee<1>(5));

	EXPECT_EQ(mult.invoke2(1, 2), 25);

	delete a;
}
*/
