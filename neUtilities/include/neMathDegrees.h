#pragma once

#include "neUtilities_PlatformDefines.h"

namespace neEngineSDK {
  class CRadian;

  class NE_UTILITIES_EXPORT CDegree
  {
  public:
    float		m_Value;

    explicit CDegree(float prm_Value) : m_Value(prm_Value) {}
    CDegree(const CRadian& prm_Radian);
    ~CDegree() {}

    inline float ValueDegrees() const { return m_Value; }
    inline float ValueRadians() const;
  };
}