#include "neUtilities_MathRadians.h"
#include "neUtilities_MathDegrees.h"
#include "neUtilities_MathConstants.h"

namespace neEngineSDK
{
  CRadian::CRadian(const CDegree& prm_Degree)
  {
    Value = CMath::DEG_TO_RAD * prm_Degree.ValueDegrees();
  }

  float CRadian::ValueDegrees() const
  {
    return Value * CMath::RAD_TO_DEG;
  }
}