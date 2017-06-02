#include "neUtilities_MathRadians.h"
#include "neUtilities_MathDegrees.h"
#include "neUtilities_MathConstants.h"

namespace neEngineSDK
{
  CRadian::CRadian(const CDegree& prm_Degree)
  {
    
  }
  inline float CRadian::ValueDegrees() const
  {
    return Value * 180.0f / CMath::PI;
  }
}