/******************************************************************************
 *                                                                            *
 * Copyright (C) 2021 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

/**
 * @luca.triceri@iit.it
 */

#include <tuple>

#include "Multiplier.h"
#include "gtest/gtest.h"

using ::testing::TestWithParam;
using ::testing::Values;

//--------------FIXTURE

class MultiplierTest : public ::testing::Test
{
   protected:
	void SetUp() override{
		// WRITE your setup
	};
	void TearDown() override{
		// WRITE your close
	};

	Multiplier mult_;
};

TEST_F(MultiplierTest, feature_with_setup)
{
	EXPECT_EQ(2, mult_.invoke(1, 2));
}

using ::testing::TestWithParam;
using ::testing::Values;

//--------------PARAM

class MultiplierParamIntTest : public ::testing::TestWithParam<int>
{
   protected:
	void SetUp() override{
		// WRITE your setup
	};
	void TearDown() override{
		// WRITE your close
	};

	Multiplier mult_;
};

INSTANTIATE_TEST_CASE_P(WithParamSingle, MultiplierParamIntTest, ::testing::Values(1, 1, 1, 1));

TEST_P(MultiplierParamIntTest, param_integer_001)
{
	int tmp = GetParam();
	EXPECT_EQ(2, mult_.invoke(tmp, 2));
}

//--

class MultiplierParamTupleTest : public ::testing::TestWithParam<std::tuple<int, int, int>>
{
   protected:
	Multiplier mult_;
};

INSTANTIATE_TEST_CASE_P(WithParamMultiple, MultiplierParamTupleTest, ::testing::Values(std::make_tuple(1, 2, 2), std::make_tuple(2, 4, 8), std::make_tuple(3, 6, 18)));

TEST_P(MultiplierParamTupleTest, param_tuple_001)
{
	int left = std::get<0>(GetParam());
	int right = std::get<1>(GetParam());
	int result = std::get<2>(GetParam());
	EXPECT_EQ(result, mult_.invoke(left,right));
}
