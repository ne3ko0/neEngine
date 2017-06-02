#include "neUtilities_MathDegrees.h"
#include "neUtilities_MathRadians.h"
#include "neUtilities_MathConstants.h"

namespace neEngineSDK
{
  CDegree::CDegree(const CRadian& prm_Radian)
  {
    Value = prm_Radian.ValueDegrees();
  }

  float CDegree::ValueRadians() const
  {
    return Value * CMath::PI / 180.0f;
  }
}
