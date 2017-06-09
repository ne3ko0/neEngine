#include "neMathDegrees.h"
#include "neMathRadians.h"
#include "neMathConstants.h"

namespace neEngineSDK
{
  CDegree::CDegree(const CRadian& prm_Radian)
  {
    m_Value = prm_Radian.ValueDegrees();
  }

  float CDegree::ValueRadians() const
  {
    return m_Value * CMath::PI / 180.0f;
  }
}
