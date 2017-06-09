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
    float X;
    float Y;
    float Z;

    CVector3() {}
    CVector3(float prm_x, float prm_y, float prm_z) : X(prm_x), Y(prm_y), Z(prm_z) {}
    ~CVector3() {}

    // Common scalar math operators
    CVector3 operator + (const CVector3& prm_Vector) const {
      return CVector3(X + prm_Vector.X,
        Y + prm_Vector.Y,
        Z + prm_Vector.Z);
    }
    CVector3 operator - (const CVector3& prm_Vector) const {
      return CVector3(X - prm_Vector.X,
        Y - prm_Vector.Y,
        Z - prm_Vector.Z);
    }
    CVector3 operator * (const float prm_Scalar) const {
      return CVector3(X * prm_Scalar,
        Y * prm_Scalar,
        Z * prm_Scalar);
    }
    CVector3 operator / (const float prm_Scalar) const {
      return CVector3(X / prm_Scalar,
        Y / prm_Scalar,
        Z / prm_Scalar);
    }
    CVector3 operator ^	(const CVector3& RHV);
    float	 operator |	(const CVector3& RHV);
    CVector3 operator += (const CVector3& prm_Vector) { return (*this + prm_Vector); }
    CVector3 operator -= (const CVector3& prm_Vector) { return (*this - prm_Vector); }
    CVector3 operator *= (const float& prm_Scalar) { return (*this * prm_Scalar); }
    CVector3 operator /= (const float& prm_Scalar) { return (*this / prm_Scalar); }

    //! Common Geometric Functions
    float			Length() const { return CMath::Sqrt(CMath::Power(X, 2.0f) + 
                                                  CMath::Power(Y, 2.0f) + 
                                                  CMath::Power(Z, 2.0f)); }
    /*!*/
    float			SqrLength() const { return (CMath::Power(X, 2.0f) + 
                                          CMath::Power(Y, 2.0f) + 
                                          CMath::Power(Z, 2.0f)); }
    /*!*/
    float			DotProduct(const CVector3& prm_Vector) const { return ((X * prm_Vector.X) + 
                                                                     (Y * prm_Vector.Y) + 
                                                                     (Z * prm_Vector.Z)); }
    /*!*/
    float			Angle(const CVector3& prm_Vector) const { 
                          return (std::acosf(DotProduct(prm_Vector) * 
                                                       (1.0f / Length() * 
                                                        prm_Vector.Length()))); }
    /*!*/
    void			Normalize() { *this *= 1.0f / Length(); }
    /*!*/
    void Negate();

    //! Unique Geometric Functions
    /*!
    \fn Perpendicular
    \brief Calculates a perpendicular vector
    \details Calculation made from determinant i(1, 0) and j(0, 1) resulting in: 
        i(y) - j(x) = (y, -x)
    */
    CVector3		CrossProduct(const CVector3& prm_Vector) const {
      return CVector3(((Y*prm_Vector.Z) - (prm_Vector.Y*Z)), 
                      ((X*prm_Vector.Z) - (prm_Vector.X*Z)), 
                      ((X*prm_Vector.Y) - (prm_Vector.X*Y))); }
    /*!*/
    CVector3		UnitCrossProduct(const CVector3& prm_Vector) 
                { return (CrossProduct(prm_Vector) /= Length()); }

    //! Common comparison operators
    bool operator == (const CVector3& prm_Vector) const { 
         return (X == prm_Vector.X) && (Y == prm_Vector.Y) && (Z == prm_Vector.Z); }
    bool operator != (const CVector3& prm_Vector) const {
         return (X != prm_Vector.X) || (Y != prm_Vector.Y) || (Z == prm_Vector.Z); }
    bool operator <= (const CVector3& prm_Vector) const { 
         return Length() <= prm_Vector.Length(); }
    bool operator >= (const CVector3& prm_Vector) const { 
         return Length() >= prm_Vector.Length(); }
    bool operator < (const CVector3& prm_Vector) const { 
         return Length() < prm_Vector.Length(); }
    bool operator > (const CVector3& prm_Vector) const { 
         return Length() <= prm_Vector.Length(); }

  };
}