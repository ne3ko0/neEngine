/*!
\file neUtilities_MathVector4.h
\author Alberto Flores Guzmán
\brief Declares the vector4 operations for the engine
\date 01-06-17

\details Declares a Vector4 class, which exists inside NEEngineSDK namespace, and contains
vector3 operations

\version 1.0
\copyright Alberto Flores Guzmán
*/

#pragma once
#include "neUtilities_Prerequisites.h"

#include <neMathConstants.h>
/*!
\class CVector4
*/
namespace neEngineSDK {
  /*!*/
  class NE_UTILITIES_EXPORT CVector4 {
  public:
    float m_X;
    float m_Y;
    float m_Z;
    float m_W;  
             

    // Common scalar math operators
    CVector4 operator + (const CVector4& prm_Vector) const;
    CVector4 operator - (const CVector4& prm_Vector) const;
    CVector4 operator * (const float prm_Scalar) const;
    CVector4 operator / (const float prm_Scalar) const;

    CVector4 operator += (const CVector4& prm_Vector);
    CVector4 operator -= (const CVector4& prm_Vector);
    CVector4 operator *= (const float& prm_Scalar);
    CVector4 operator /= (const float& prm_Scalar);

    //! Common Geometric Functions
    float			Length() const;
    float			SqrLength() const;
    /*!*/
    float			DotProduct(const CVector4& prm_Vector) const;
    /*!*/
    float			Angle(const CVector4& prm_Vector) const;
    /*!*/
    CVector4			Normalize();

    //! Unique Geometric Functions
    /*!
    \fn Perpendicular
    \brief Calculates a perpendicular vector
    \details Calculation made from determinant i(1, 0) and j(0, 1) resulting in: 
              i(y) - j(x) = (y, -x)
    */
    CVector4		CrossProduct(const CVector4& prm_Vector) const;
    /*!*/
    CVector4		UnitCrossProduct(const CVector4& prm_Vector);

    //! Common comparison operators
    bool operator == (const CVector4& prm_Vector) const;
    bool operator != (const CVector4& prm_Vector) const;
    bool operator <= (const CVector4& prm_Vector) const;
    bool operator >= (const CVector4& prm_Vector) const;
    bool operator < (const CVector4& prm_Vector) const;
    bool operator > (const CVector4& prm_Vector) const;

    CVector4();
    CVector4(float prm_x, float prm_y, float prm_z, float prm_w);
    ~CVector4();

  };
}