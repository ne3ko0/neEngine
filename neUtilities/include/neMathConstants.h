/*!
\file neUtilities_MathConstants.h
\author Alberto Flores Guzmán
\brief Declares the constants for a math class
\date 25-05-17

\details Declares a Match class, which exists inside neEngineSDK namespace, and contains
mathemathical constants

\version 1.0
\copyright Alberto Flores Guzmán
*/

#pragma once

#include "neUtilities_Prerequisites.h"


/*!
\namespace neEngineSDK
\brief Declares every function (math, types, objects) for use in the engine
*/
namespace neEngineSDK {
  class CRadian;
  class CDegree;

  ////! Absolute
  //template<class T> FORCE_INLINE T Abs(const T prm_Value) {
  //  return (prm_Value >= (T)0) ? prm_Value : -prm_Value;
  //}

  //template <> FORCE_INLINE float Abs<float>(const float prm_Value) {
  //  return (float)std::fabs(prm_Value);
  //}

  /*!
  \class CMath
  \brief Class that controls basic mathematical scalar operations
  */
  class NE_UTILITIES_EXPORT CMath {
  public:

    //! Constants
    /*!
    \var PI
    \brief Pi constant = 3.141592535897
    */
    static const float		PI;
    /*!
    \var INVERSEPI
    \brief
    */
    static const float		INVERSEPI;
    /*!
    \var PIBYTWO
    \brief
    */
    static const float		PIBYTWO;
    /*!
    \var TWOPI
    \brief
    */
    static const float		TWOPI;
    /*!
    \var EULER
    \brief
    */
    static const float		EULER;
    /*!
    \var MIN_UINT8
    \brief
    */
    static const uint8		MIN_UINT8;
    /*!
    \var MIN_UINT16
    \brief
    */
    static const uint16		MIN_UINT16;
    /*!
    \var UINT32
    \brief
    */
    static const uint32		MIN_UINT32;
    /*!
    \var MIN_INT8
    \brief
    */
    static const int8		MIN_INT8;
    /*!
    \var MIN_INT16
    \brief
    */
    static const int16		MIN_INT16;
    /*!
    \var MIN_INT32
    \brief
    */
    static const int32		MIN_INT32;
    /*!
    \var MIN_FLOAT
    \brief
    */
    static const float		MIN_FLOAT;
    /*!
    \var MAX_UINT8
    \brief
    */
    static const uint8		MAX_UINT8;
    /*!
    \var UINT16
    \brief
    */
    static const uint16		MAX_UINT16;
    /*!
    \var UINT32
    \brief
    */
    static const uint32		MAX_UINT32;
    /*!
    \var MAX_INT8
    \brief
    */
    static const int8		MAX_INT8;
    /*!
    \var MAX_INT16
    \brief
    */
    static const int16		MAX_INT16;
    /*!
    \var MAX_INT32
    \brief
    */
    static const int32		MAX_INT32;
    /*!
    \var MAX_FLOAT
    \brief
    */
    static const float		MAX_FLOAT;
    /*!
    \var DEG_TO_RAD
    \brief Transforms degrees to radians
    */
    static const float		DEG_TO_RAD;
    /*!
    \var RAD_TO_RAD
    \brief Transforms degrees to radians
    */
    static const float		RAD_TO_DEG;

    static const float		LOG2;

    static const float		DELTA;

    static const float		F_INFINITE;

    // Thresholds
    /*	template<class T>
    static Abs()
    {
    neEngineSDK::Abs();
    }*/

    template<class T> FORCE_INLINE T Abs(const T prm_Value) {
      return (prm_Value >= (T)0) ? prm_Value : -prm_Value;
    }

    //! Truncate
    /*!
    \fn Trunc
    \brief Truncates a int32 value
    \param prm_Value Value to be truncated
    */
    static FORCE_INLINE int32	Trunc(float prm_Value) { return (int32)prm_Value; }
    //! Truncate float
    /*!
    \fn TruncFloat
    \brief Truncates a float
    \param prm_Value Value to be truncated
    */
    static FORCE_INLINE float	TruncFloat(float prm_Value) { return (float)Trunc(prm_Value); }

    //! Roundings
    /*!
    \fn Floor
    \brief Rounds a value to the lowest
    \param prm_Value Value to be floored
    */
    static FORCE_INLINE int32	Floor(float prm_Value) {
      return Trunc((float)std::floor(prm_Value));
    }

    /*!
    \fn Round
    \brief Rounds a value to the half
    \param prm_Value Value to be half rounded
    */
    static FORCE_INLINE int32	Round(float prm_Value) {

      return Floor(prm_Value + 0.5f);
    }

    /*!
    \fn Ceil
    \brief Rounds a value to the highest
    \param prm_Value Value to be ceiled
    */
    static FORCE_INLINE int32	Ceil(float prm_Value) {
      return Trunc((float)std::ceil(prm_Value));
    }

    //! Fraccional
    /*!
    \fn Fractional
    \brief Obtains the fractional of a value
    \param prm_Value Value to be fractionalized
    */
    static FORCE_INLINE float	Fractional(float prm_Value) {
      return prm_Value - TruncFloat(prm_Value);
    }
    //! Module
    /*!
    \fn ModuleFloat
    \brief Obtains modulo of two values
    \param prm_X Divider
    \param prm_Y Dividendo
    */
    static FORCE_INLINE float	ModuleFloat(float prm_X, float prm_Y) {
      return (float)std::fmod(prm_X, prm_Y);
    }

    //! Power
    /*!
    \fn Power
    \brief Raise a value to a given power
    \param prm_Base Base of the power operation
    \param prm_Exponent Exponent of the power operation
    */
    static FORCE_INLINE float	Power(float prm_Base, float prm_Exponent) {
      return (float)std::pow(prm_Base, prm_Exponent);
    }
    //! Exponential
    /*!
    \fn Exponential
    \brief Obtains the exponential function of a value
    \param prm_Value Value to obtain the exponential function
    */
    static FORCE_INLINE float	Exponential(float prm_Value) {
      return (float)std::exp(prm_Value);
    }


    //! Logarithm (Euler)
    /*!*/
    static FORCE_INLINE float	LogE(float prm_Value) {
      return (float)std::log(prm_Value);
    }
    // Natural Logarithm (Base 2)
    /*!*/
    static FORCE_INLINE float	Log2(float prm_Value);
    //! Base 'x' Logarithm
    /*!*/
    static FORCE_INLINE float	LogX(float prm_Base, float prm_Value) {
      return LogE(prm_Base) / LogE(prm_Value);
    }

    //! Square root
    /*!*/
    static FORCE_INLINE float	Sqrt(float prm_Value) {
      return (float)std::sqrt(prm_Value);
    }
    //! Square root degrees
    /*!*/
    
    static CDegree Sqrt(const CDegree& prm_Value);
  
    //! Square root radians
    /*!*/
    static CRadian Sqrt(const CRadian& prm_Value);

    //! Inverse Square root
    /*!*/
    static FORCE_INLINE float	InverseSqrt(float prm_F) {
      return(1.0f / (float)std::sqrt(prm_F));
    }
    //! Inverse Square root 
    /*!*/
    static FORCE_INLINE float	InvSqrtEst(float prm_F) {
      return InverseSqrt(prm_F);
    }

    //! CHECK is nan?
    /*!*/
    static FORCE_INLINE bool	IsNan(float prm_Value) {
      return ((*(uint32*)&prm_Value) & 0x7FFFFFFF) > 0x7F800000;
    }

    //! CHECK is finite?
    /*!*/
    static FORCE_INLINE bool	IsFinite(float prm_Value) {
      return ((*(uint32*)&prm_Value) & 0x7F800000) != 0x7F800000;
    }

    //! CHECK is Negative float?
    /*!*/
    static FORCE_INLINE bool	IsNegativeFloat(float prm_Value) {
      return ((*(uint32*)&prm_Value) >= (uint32)0x80800000);
    }

    //! Trigonometrics

    //!RandianSine
    /*!*/
    static FORCE_INLINE float	Sine(float prm_Value) {
      return (float)std::sin(prm_Value);
    }

    /*!
    */
    static FORCE_INLINE float	Cosine(float prm_Value) {
      return (float)std::cos(prm_Value);
    }

    /*!
    */
    static FORCE_INLINE float	Tangent(float prm_Value) {
      return (float)std::tan(prm_Value);
    }

    //! Radian trigonometrics
    /*!
    \fn m_RadianSine
    \brief
    */
    static float RadianSine(const CRadian& prm_Radian);

    /*!
    \fn m_RadianCosine
    \brief
    */
    static float RadianCosine(const CRadian& prm_Radian);

    /*!
    \fn m_RadianTangent
    \brief
    */
    static float RadianTangent(const CRadian& prm_Radian);

    //! Radian arcs
    /*!
    \fn m_Acos
    \brief
    */
    static CRadian Acos(float prm_Value);

    /*!
    \fn m_Asin
    \brief
    */
    static CRadian	Asin(float prm_Value);

    /*!
    \fn m_Atan
    \brief
    */
    static CRadian	Atan(float prm_Value);

    /*!
    \fn m_Atan2
    \brief
    */
    static CRadian	Atan2(float prm_Y, float prm_X);

    template<class T, class U>
    /*!
    \fn m_Linear_Interpolation
    \brief Obtains linear interpolation between two scalar with a given alpha
    \param prm_A Reference to a scalar
    \param prm_B Reference to a scalar
    \param prm_Alpha Reference to the alpha
    */
    static FORCE_INLINE T		Linear_Interpolation(const T& prm_A, const T& prm_B, const U& prm_Alpha) {
      return (T)(prm_A + prm_Alpha *(prm_B - prm_A));
    }
    template<class T>
    /*!
    \fn m_Minimum
    \brief Obtains minimum between two scalars
    \param prm_A Reference to a scalar
    \param prm_B Reference to a scalar
    */
    static FORCE_INLINE	T		Minimum(const T& prm_A, const T& prm_B) {
      return (prm_A < prm_B ? prm_A : prm_B);
    }

    template<class T>
    /*!
    \fn m_Maximum
    \brief Obtains maximum between two scalars
    \param prm_A Reference to a scalar
    \param prm_B Reference to a scalar
    */
    static FORCE_INLINE T		Maximum(const T& prm_A, const T& prm_B) {
      return (prm_A > prm_B ? prm_A : prm_B);
    }
  };
}