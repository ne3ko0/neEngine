#include "neUtilities_Prerequisites.h"

#include <gtest/gtest.h>


namespace neEngineSDK {
  TEST(Utilities, types) {
    EXPECT_TRUE(sizeof(uint8) == 1);
    EXPECT_TRUE(sizeof(uint16) == 2);
    EXPECT_TRUE(sizeof(uint32) == 4);
    EXPECT_TRUE(sizeof(uint64) == 8);
    EXPECT_TRUE(sizeof(int8) == 1);
    EXPECT_TRUE(sizeof(int16) == 2);
    EXPECT_TRUE(sizeof(int32) == 4);
    EXPECT_TRUE(sizeof(int64) == 8);
  }
  TEST(Utilities, Math) {
    ASSERT_TRUE(CMath::Power(2, 2) == 4);
    ASSERT_TRUE(CMath::Ceil(5.6f) == 6);
    ASSERT_TRUE(CMath::Sqrt(9) == 3);
    ASSERT_TRUE(CMath::Exponential(0) == 1);
  }
}