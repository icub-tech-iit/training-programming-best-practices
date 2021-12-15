/******************************************************************************
 *                                                                            *
 * Copyright (C) 2021 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

/**
 * @luca.triceri@iit.it
 */

#include "mediaScanner.h"
#include "InterfaceForCApi.h"
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

class InterfaceForCApi_Mock : public InterfaceForCApi
{
   public:																	
  MOCK_METHOD(int, open_c, (const char *, int), (override));
  MOCK_METHOD(struct udev *, udev_new_c, (), (override));

};

TEST(MediaScanner, Test_MediaScanner_001)
{
	//MultiplierFromFile_Mock mult("Luca");

	//EXPECT_CALL(mult, getDataFromFile(1));
	//EXPECT_CALL(mult, getDataFromFile(2));

	//mult.invoke(1, 2);
}
