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
using ::testing::An;
using ::testing::Gt;
using ::testing::InSequence;
using ::testing::InvokeArgument;
using ::testing::Matcher;
using ::testing::TypedEq;

class MultiplierFromFile_Mock : public MultiplierFromFile
{
   public:																				// always public
	MOCK_METHOD(double, getDataFromFile, (unsigned int), (const, override));			// note the parentesis
	MOCK_METHOD(double, getDataFromFile, (unsigned int, double *), (const, override));	// note the parentesis
	MOCK_METHOD(double, getDataFromFile, (unsigned int, double &), (const, override));	// note the parentesis

	MultiplierFromFile_Mock(const std::string &name) : MultiplierFromFile(name)
	{
	}
};

TEST(MultiplierFromFile, expect_call_base_001)
{
	MultiplierFromFile_Mock mult("myFileName");

	EXPECT_CALL(mult, getDataFromFile(1));
	EXPECT_CALL(mult, getDataFromFile(2));

	//The test
	mult.invoke(1, 2);
}

TEST(MultiplierFromFile, expect_call_times_001)
{
	MultiplierFromFile_Mock mult("myFileName");

	EXPECT_CALL(mult, getDataFromFile(1)).Times(1);
	EXPECT_CALL(mult, getDataFromFile(2)).Times(1);

	//The test
	mult.invoke(1, 2);
}

TEST(MultiplierFromFile, expect_call_times_002)
{
	MultiplierFromFile_Mock mult("myFileName");
	EXPECT_CALL(mult, getDataFromFile(1)).Times(AnyNumber());
	EXPECT_CALL(mult, getDataFromFile(2)).Times(AnyNumber());

	mult.invoke(1, 2);
}

TEST(MultiplierFromFile, expect_call_match_generic_001)
{
	MultiplierFromFile_Mock mult("myFileName");

	EXPECT_CALL(mult, getDataFromFile(_)).Times(2);

	mult.invoke(1, 2);
}

TEST(MultiplierFromFile, expect_call_match_002)
{
	MultiplierFromFile_Mock mult("myFileName");

	EXPECT_CALL(mult, getDataFromFile(Gt(0))).Times(2);

	mult.invoke(1, 2);
}

TEST(MultiplierFromFile, expect_call_match_003)
{
	MultiplierFromFile_Mock mult("myFileName");

	EXPECT_CALL(mult, getDataFromFile(Gt(100))).Times(1);
	EXPECT_CALL(mult, getDataFromFile(Lt(100))).Times(1);

	mult.invoke( 2,1010);
}

TEST(MultiplierFromFile, expect_call_sequence_001)
{
	MultiplierFromFile_Mock mult("myFileName");

	//Sequence
	InSequence s;
	EXPECT_CALL(mult, getDataFromFile(1)).Times(1);
	EXPECT_CALL(mult, getDataFromFile(2)).Times(1);

	mult.invoke(1, 2);
}

TEST(MultiplierFromFile, expect_call_return_001)
{
	MultiplierFromFile_Mock mult("myFileName");

	EXPECT_CALL(mult, getDataFromFile(1)).WillOnce(Return(10));
	EXPECT_CALL(mult, getDataFromFile(2)).WillOnce(Return(11));

	EXPECT_EQ(110, mult.invoke(1, 2));
}

TEST(MultiplierFromFile, expect_call_return_002)
{
	MultiplierFromFile_Mock mult("myFileName");

	EXPECT_CALL(mult, getDataFromFile(_)).WillRepeatedly(Return(9));

	EXPECT_EQ(81, mult.invoke(1, 2));
}

//More advanced

TEST(MultiplierFromFile, expect_call_returnparam_001)
{
	MultiplierFromFile_Mock mult("myFileName");

	double value=5;
	EXPECT_CALL(mult, getDataFromFile(_, An<double &>())).WillRepeatedly(DoAll(SetArgReferee<1>(5),Return(5)));
	//used method double getDataFromFile(unsigned int index, double& out) const

	EXPECT_EQ(25, mult.invoke2(1, 2));//Reference version
}

TEST(MultiplierFromFile, expect_call_returnparam_002)
{
	MultiplierFromFile_Mock mult("myFileName");


	EXPECT_CALL(mult, getDataFromFile(1, An<double &>())).WillOnce(DoAll(SetArgReferee<1>(5), Return(5)));
	EXPECT_CALL(mult, getDataFromFile(2, An<double &>())).WillOnce(DoAll(SetArgReferee<1>(5), Return(5)));

	EXPECT_EQ(25,mult.invoke2(1, 2));//Reference version
}

TEST(MultiplierFromFile, expect_call_returnparam_003)
{
	MultiplierFromFile_Mock mult("myFileName");

	EXPECT_CALL(mult, getDataFromFile(_, An<double &>())).WillRepeatedly(DoAll(SetArgReferee<1>(5), Return(5)));

	EXPECT_EQ(25,mult.invoke2(1, 2));//Reference version
}


TEST(MultiplierFromFile, Test_returnparam_004)
{
	MultiplierFromFile_Mock mult("myFileName");

	EXPECT_CALL(mult, getDataFromFile(_,An<double*>())).WillRepeatedly(DoAll(SetArgPointee<1>(5),Return(5)));
	////used method double getDataFromFile(unsigned int index, double* out) const

	EXPECT_EQ(25,mult.invoke3(1, 2));//Pointer version

}

