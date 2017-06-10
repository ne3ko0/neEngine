#include "neMathConstants.h"
#include "neMathRadians.h"
#include "neMathDegrees.h"

namespace neEngineSDK
{
  const float					CMath::PI = atanf(1.f)*4.f;
  const float					CMath::INVERSEPI = 1.0f / PI;
  const float					CMath::PIBYTWO = PI / 2.0f;
  const float					CMath::TWOPI = 2.0f * PI;

  const float					CMath::EULER = 2.7182818284590f;

  const uint8					CMath::MIN_UINT8 = std::numeric_limits<uint8>::min();
  const uint16				CMath::MIN_UINT16 = std::numeric_limits<uint16>::min();
  const uint32				CMath::MIN_UINT32 = std::numeric_limits<uint32>::min();
  const int8					CMath::MIN_INT8 = std::numeric_limits<int8>::min();
  const int16					CMath::MIN_INT16 = std::numeric_limits<int16>::min();
  const int32					CMath::MIN_INT32 = std::numeric_limits<int32>::min();
  const float					CMath::MIN_FLOAT = std::numeric_limits<float>::min();

  const uint8					CMath::MAX_UINT8 = std::numeric_limits<uint8>::max();
  const uint16				CMath::MAX_UINT16 = std::numeric_limits<uint16>::max();
  const uint32				CMath::MAX_UINT32 = std::numeric_limits<uint32>::max();
  const int8					CMath::MAX_INT8 = std::numeric_limits<int8>::max();
  const int16					CMath::MAX_INT16 = std::numeric_limits<int16>::max();
  const int32					CMath::MAX_INT32 = std::numeric_limits<int32>::max();
  const float					CMath::MAX_FLOAT = std::numeric_limits<float>::max();
  const float					CMath::F_INFINITE = std::numeric_limits<float>::infinity();

  const float					CMath::LOG2 = std::log(2.0f);

  const float					CMath::DELTA = 0.0f;

  const float         CMath::DEG_TO_RAD = CMath::PI / 180.0f;
  const float         CMath::RAD_TO_DEG = 180.0f / CMath::PI;

  float						CMath::Log2(float prm_Value)
  {
    return (float)(std::log(prm_Value) / LOG2);
  }

  CDegree CMath::Sqrt(const CDegree & prm_Value)
  {
    return CDegree(Sqrt(prm_Value.ValueDegrees()));
  }

  CRadian CMath::Sqrt(const CRadian & prm_Value)
  {
    return CRadian(Sqrt(prm_Value.ValueRadians()));
  }

  float CMath::RadianSine(const CRadian & prm_Radian)
  {
    return std::sinf(prm_Radian.ValueRadians());
  }

  float CMath::RadianCosine(const CRadian & prm_Radian)
  {
    return std::cosf(prm_Radian.ValueRadians());
  }

  float CMath::RadianTangent(const CRadian & prm_Radian)
  {
    return std::tanf(prm_Radian.ValueRadians());
  }

  CRadian CMath::Acos(float prm_Value)
  {
    return CRadian( std::acosf(prm_Value) );
  }

  CRadian CMath::Asin(float prm_Value) {
    if (prm_Value > -1.0f) {
      if (prm_Value < 1.0f) {
        return (CRadian)(std::asin(prm_Value));
      }

      else
        return CRadian(0.0f);
    }

    else {
      return CRadian(PI);
    }
  }
  CRadian CMath::Atan(float prm_Value)
  {
    return CRadian(std::atan(prm_Value));
  }
  CRadian CMath::Atan2(float prm_Y, float prm_X)
  {
    return CRadian(std::atan2(prm_Y, prm_X));
  }
}
