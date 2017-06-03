#include "neUtilities_Prerequisites.h"
#include "neUtilities_MathConstants.h"
#include <gtest/gtest.h>

using namespace neEngineSDK;

  TEST(Utilities, types) {
    EXPECT_TRUE(sizeof(uint8) == 1);
    EXPECT_TRUE(sizeof(uint16) == 2);
    EXPECT_TRUE(sizeof(uint32) == 4);
    EXPECT_TRUE(sizeof(uint64) == 8);
    EXPECT_TRUE(sizeof(int8) == 1);
    EXPECT_TRUE(sizeof(int16) == 2);
    EXPECT_TRUE(sizeof(int32) == 4);
    EXPECT_TRUE(sizeof(int64) == 8);
    EXPECT_TRUE(sizeof(SIZE_T) == 8);
    EXPECT_TRUE(sizeof(QWord) == 16);
  }
  TEST(Utilities, Math) {
    EXPECT_TRUE( CMath::PI == atanf(1.f/4.f));
    EXPECT_TRUE( CMath::MIN_UINT8 == 0);
    EXPECT_TRUE(CMath::MIN_INT8 == -CMath::Power(2,8)/2);
    EXPECT_TRUE( CMath::MIN_INT16 == -CMath::Power(2,16)/2);
    ASSERT_TRUE( CMath::Ceil(5.6f) == 6);
    EXPECT_TRUE( CMath::Floor(5.6) == 5);
    EXPECT_TRUE( CMath::Round(5.6) == 6);
    ASSERT_TRUE( CMath::Sqrt(9) == 3);
    ASSERT_TRUE( CMath::Exponential(0) == 1);
  }