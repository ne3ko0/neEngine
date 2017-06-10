/*!
\file neUtilities_Vector2.h
\author Alberto Flores Guzmán
\brief Declares the vector2 operations for the engine
\date 25-05-17

\details Declares a Vector2 class, which exists inside NEEngineSDK namespace, and contains 
                                                                        vector2 operations

\version 1.0
\copyright Alberto Flores Guzmán
*/

#pragma once
#include "neUtilities_Prerequisites.h"

#include <neMathConstants.h>
/*!
\class CVector2
*/
namespace neEngineSDK {
  class NE_UTILITIES_EXPORT CVector2 {
  public:
    float m_X;
    float m_Y;
  
    // Common scalar math operators
    CVector2 operator + (const CVector2& prm_Vector) const; 
    CVector2 operator - (const CVector2& prm_Vector) const; 
    CVector2 operator * (const float prm_Scalar) const;
    CVector2 operator / (const float prm_Scalar) const;

    CVector2 operator += (const CVector2& prm_Vector);
    CVector2 operator -= (const CVector2& prm_Vector);
    CVector2 operator *= (const float& prm_Scalar);
    CVector2 operator /= (const float& prm_Scalar);

    //! Common Geometric Functions
    float			Length() const;
    /*!*/
    float			SqrLength() const;
    /*!*/
    float			DotProduct(const CVector2& prm_Vector) const;
    /*!*/
    float			Direction() const;
    /*!*/
    void			Normalize();

    //! Unique Geometric Functions
    /*!
    \fn Perpendicular
    \brief Calculates a perpendicular vector
    \details Calculation made from determinant i(1, 0) and j(0, 1) resulting in: i(y) - 
                                                                                 j(x) = 
                                                                                 (y, -x)
    */
    CVector2		Perpendicular() const;
    /*!*/
    CVector2		UnitPerpendicular();
    /*!*/
    float			DotPerpendicular(const CVector2& prm_Vector);

    //! Common comparison operators
    bool operator == (const CVector2& prm_Vector) const;
    bool operator != (const CVector2& prm_Vector) const;
    bool operator <= (const CVector2& prm_Vector) const;                                                 
    bool operator >= (const CVector2& prm_Vector) const;                                                  
    bool operator < (const CVector2& prm_Vector) const;                                           
    bool operator > (const CVector2& prm_Vector) const;
    
    CVector2();
    CVector2(float prm_x, float prm_y);
    ~CVector2();
  };
}
