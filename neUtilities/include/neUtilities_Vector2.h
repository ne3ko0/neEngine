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

#include <neUtilities_MathConstants.h>
/*!
\class CVector2
*/
namespace neEngineSDK {
  class NE_UTILITIES_EXPORT CVector2 {
  public:
    float X;
    float Y;

    CVector2(float prm_x = 0.0f, float prm_y = 0.0f) : X(prm_x), Y(prm_y) {}

    // Common scalar math operators
    CVector2 operator + (const CVector2& prm_Vector) const { return CVector2(X + 
                                                                             prm_Vector.X, Y + 
                                                                             prm_Vector.Y); }
    CVector2 operator - (const CVector2& prm_Vector) const { return CVector2(X - 
                                                                             prm_Vector.X, Y - 
                                                                             prm_Vector.Y); }
    CVector2 operator * (const float prm_Scalar) const { return CVector2(X * 
                                                                         prm_Scalar, Y * 
                                                                         prm_Scalar); }
    CVector2 operator / (const float prm_Scalar) const { return CVector2(X /  
                                                                         prm_Scalar, Y / 
                                                                         prm_Scalar); }

    CVector2 operator += (const CVector2& prm_Vector) { return (*this + prm_Vector); }
    CVector2 operator -= (const CVector2& prm_Vector) { return (*this - prm_Vector); }
    CVector2 operator *= (const float& prm_Scalar) { return (*this * prm_Scalar); }
    CVector2 operator /= (const float& prm_Scalar) { return (*this / prm_Scalar); }

    //! Common Geometric Functions
    float			Length() const { return CMath::Sqrt(CMath::Power(X, 2.0f) + 
                                                  CMath::Power(Y, 2.0f)); }
    /*!*/
    float			SqrLength() const { return (CMath::Power(X, 2.0f) + 
                                          CMath::Power(Y, 2.0f)); }
    /*!*/
    float			DotProduct(const CVector2& prm_Vector) const { return ((X * 
                                                                      prm_Vector.X) + 
                                                                     (Y * prm_Vector.Y)); }
    /*!*/
    float			Direction() const { return (std::atanf(Y / X)); }
    /*!*/
    void			Normalize() { *this *= 1.0f / Length(); }

    //! Unique Geometric Functions
    /*!
    \fn Perpendicular
    \brief Calculates a perpendicular vector
    \details Calculation made from determinant i(1, 0) and j(0, 1) resulting in: i(y) - 
                                                                                 j(x) = 
                                                                                 (y, -x)
    */
    CVector2		Perpendicular() const { return CVector2(Y, -X); }
    /*!*/
    CVector2		UnitPerpendicular() { return (Perpendicular() /= Length()); }
    /*!*/
    float			DotPerpendicular(const CVector2& prm_Vector) { return((X*prm_Vector.Y) - 
                                                                    (Y*prm_Vector.X)); }

    //! Common comparison operators
    bool operator == (const CVector2& prm_Vector) const { return (X == prm_Vector.X) && 
                                                                 (Y == prm_Vector.Y); }
    bool operator != (const CVector2& prm_Vector) const { return (X != prm_Vector.X) || 
                                                                 (Y != prm_Vector.Y); }
    bool operator <= (const CVector2& prm_Vector) const 
                                                  { return Length() <= prm_Vector.Length(); }
    bool operator >= (const CVector2& prm_Vector) const 
                                                  { return Length() >= prm_Vector.Length(); }
    bool operator < (const CVector2& prm_Vector) const 
                                                  { return Length() < prm_Vector.Length(); }
    bool operator > (const CVector2& prm_Vector) const 
                                                  { return Length() <= prm_Vector.Length(); }
  };
}
