#include "neMathRadians.h"
#include "neMathDegrees.h"
#include "neMathConstants.h"

namespace neEngineSDK
{
  CRadian::CRadian(const CDegree& prm_Degree)
  {
    m_Value = CMath::DEG_TO_RAD * prm_Degree.ValueDegrees();
  }

  float CRadian::ValueDegrees() const
  {
    return m_Value * CMath::RAD_TO_DEG;
  }
}