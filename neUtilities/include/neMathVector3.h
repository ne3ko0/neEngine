/*!
\file neUtilities_MathVector3.h
\author Alberto Flores Guzmán
\brief Declares the vector3 operations for the engine
\date 01-06-17

\details Declares a Vector3 class, which exists inside NEEngineSDK namespace, and contains
vector3 operations

\version 1.0
\copyright Alberto Flores Guzmán
*/

#pragma once
#include "neUtilities_Prerequisites.h"

#include <neMathConstants.h>
/*!
\class CVector3
*/
namespace neEngineSDK {
  class NE_UTILITIES_EXPORT CVector3 {
  public:
    float m_X;
    float m_Y;
    float m_Z;


    // Common scalar math operators
    CVector3 operator + (const CVector3& prm_Vector) const; 
    CVector3 operator - (const CVector3& prm_Vector) const;
    CVector3 operator * (const float prm_Scalar) const;
    CVector3 operator / (const float prm_Scalar) const;
    CVector3 operator ^	(const CVector3& RHV);
    float	   operator |	(const CVector3& RHV);
    CVector3 operator += (const CVector3& prm_Vector);
    CVector3 operator -= (const CVector3& prm_Vector);
    CVector3 operator *= (const float& prm_Scalar);
    CVector3 operator /= (const float& prm_Scalar);

    //! Common Geometric Functions
    float			Length() const;
    /*!*/
    float			SqrLength() const;
    /*!*/
    float			DotProduct(const CVector3& prm_Vector) const;
    /*!*/
    float			Angle(const CVector3& prm_Vector) const;
    /*!*/
    void			Normalize();
    /*!*/
    void Negate();

    //! Unique Geometric Functions
    /*!
    \fn Perpendicular
    \brief Calculates a perpendicular vector
    \details Calculation made from determinant i(1, 0) and j(0, 1) resulting in: 
        i(y) - j(x) = (y, -x)
    */
    CVector3		CrossProduct(const CVector3& prm_Vector) const; 
    /*!*/
    CVector3		UnitCrossProduct(const CVector3& prm_Vector);
                

    //! Common comparison operators
    bool operator == (const CVector3& prm_Vector) const;
    bool operator != (const CVector3& prm_Vector) const;
    bool operator <= (const CVector3& prm_Vector) const;
    bool operator >= (const CVector3& prm_Vector) const;
    bool operator < (const CVector3& prm_Vector) const;
    bool operator > (const CVector3& prm_Vector) const;


    CVector3();
    CVector3(float prm_x, float prm_y, float prm_z);
    ~CVector3();

  };
}