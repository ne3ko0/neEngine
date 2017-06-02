#include "neUtilities_Prerequisites.h"

#include <gtest/gtest.h>


namespace neEngineSDK {
  TEST(Game, Math) {
    ASSERT_TRUE(CMath::Power(2, 2) == 4);
    ASSERT_TRUE(CMath::Ceil(5.6f) == 6);
    ASSERT_TRUE(CMath::Sqrt(9) == 3);
    ASSERT_TRUE(CMath::Exponential(0) == 1);
  }
}