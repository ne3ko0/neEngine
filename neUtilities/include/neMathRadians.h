/*!
\file neUtilities_MathRadians.h
\author Alberto Flores Guzm�n
\brief Declares the Radians operations for the engine
\date 25-05-17

\details Declares a Radians class, which exists inside NEEngineSDK namespace, and contains
Radians operations

\version 1.0
\copyright Alberto Flores Guzm�n
*/


#pragma once

#include "neUtilities_PlatformDefines.h"

namespace neEngineSDK
{
  class CDegree;

  class NE_UTILITIES_EXPORT CRadian
  {
  public:
    explicit CRadian(float prm_Value) : m_Value(prm_Value) {}
    CRadian(const CDegree& prm_Degree);
    ~CRadian() {}

    float			m_Value;

    inline float	ValueRadians() const { return m_Value; }
    inline float	ValueDegrees() const;
  };
}