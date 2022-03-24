/******************************************************************************
 *                                                                            *
 * Copyright (C) 2021 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

/**
 * @luca.triceri@iit.it
 */

#include "InterfaceForCApi.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "mediaScanner.h"

using namespace testing;
using ::testing::_;
using ::testing::An;
using ::testing::Gt;
using ::testing::InSequence;
using ::testing::InvokeArgument;
using ::testing::Matcher;
using ::testing::TypedEq;

class InterfaceForCApi_Mock : public InterfaceForCApi
{
   public:
	MOCK_METHOD(int, open_c, (const char *, int), (override));
	MOCK_METHOD(struct udev *, udev_new_c, (), (override));
};

TEST(MediaScanner, MediaScanner_simple_negative_001)
{
	InterfaceForCApi_Mock api;
	MediaScanner mediaScanner(api);

	EXPECT_CALL(api, open_c(_,_)).WillRepeatedly(DoAll(Return(-1)));
	EXPECT_CALL(api, udev_new_c()).WillRepeatedly(DoAll(Return(nullptr)));

	//The test
	EXPECT_FALSE(mediaScanner.scan("/dev/media0"));
	EXPECT_FALSE(mediaScanner.scan("/dev/v4l"));
}

TEST(MediaScanner, MediaScanner_simple_negative_002)
{
	InterfaceForCApi_Mock api;
	MediaScanner mediaScanner(api);

	EXPECT_CALL(api, open_c(_,_)).WillRepeatedly(DoAll(Return(1)));
	EXPECT_CALL(api, udev_new_c()).WillRepeatedly(DoAll(Return(nullptr)));

	//The test
	EXPECT_FALSE(mediaScanner.scan("/dev/media0"));
	EXPECT_FALSE(mediaScanner.scan("/dev/v4l"));
}

TEST(MediaScanner, MediaScanner_simple_positive_001)
{
	InterfaceForCApi_Mock api;
	MediaScanner mediaScanner(api);

	EXPECT_CALL(api, open_c(_,_)).WillRepeatedly(DoAll(Return(1)));
	udev tmp;
	EXPECT_CALL(api, udev_new_c()).WillRepeatedly(DoAll(Return(&tmp)));

	//The test
	EXPECT_TRUE(mediaScanner.scan("/dev/media0"));
	EXPECT_TRUE(mediaScanner.scan("/dev/v4l"));
}