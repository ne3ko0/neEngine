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

#include <neUtilities_MathConstants.h>
/*!
\class CVector4
*/
namespace neEngineSDK {
  /*!*/
  class NE_UTILITIES_EXPORT CVector4 {
  public:
    float m_x;
    float m_y;
    float m_z;
    float m_w;

    CVector4(float prm_X = 0.0f, float prm_Y = 0.0f, float prm_Z = 0.0f, float prm_W = 0.0f) 
              :m_x(prm_X), m_y(prm_Y), m_z(prm_Z), m_w(prm_W) {}

    // Common scalar math operators
    CVector4 operator + (const CVector4& prm_Vector) const { 
             return CVector4(m_x + prm_Vector.m_x, m_y + 
                             prm_Vector.m_y, m_z + 
                             prm_Vector.m_z, m_w + 
                             prm_Vector.m_w); }
    CVector4 operator - (const CVector4& prm_Vector) const { 
             return CVector4(m_x - prm_Vector.m_x, 
                             m_y - prm_Vector.m_y, 
                             m_z - prm_Vector.m_z, 
                             m_w - prm_Vector.m_w); }
    CVector4 operator * (const float prm_Scalar) const { 
             return CVector4(m_x * prm_Scalar, 
                             m_y * prm_Scalar, m_z * prm_Scalar, 
                             m_w * prm_Scalar); }
    CVector4 operator / (const float prm_Scalar) const { 
             return CVector4(m_x / prm_Scalar,  
                             m_y / prm_Scalar, 
                             m_z / prm_Scalar, 
                             m_w / prm_Scalar); }

    CVector4 operator += (const CVector4& prm_Vector) { return (*this + prm_Vector); }
    CVector4 operator -= (const CVector4& prm_Vector) { return (*this - prm_Vector); }
    CVector4 operator *= (const float& prm_Scalar) { return (*this * prm_Scalar); }
    CVector4 operator /= (const float& prm_Scalar) { return (*this / prm_Scalar); }

    //! Common Geometric Functions
    float			Length() const { return CMath::Sqrt(CMath::Power(m_x, 2.0f) + 
                                                  CMath::Power(m_y, 2.0f) + 
                                                  CMath::Power(m_z, 2.0f) +  
                                                  CMath::Power(m_w, 2.0f)); }
    /*!*/
    float			SqrLength() const { return (CMath::Power(m_x, 2.0f) + 
                                          CMath::Power(m_y, 2.0f) + 
                                          CMath::Power(m_z, 2.0f) + 
                                          CMath::Power(m_w, 2.0f)); }
    /*!*/
    float			DotProduct(const CVector4& prm_Vector) const { 
              return ((m_x * prm_Vector.m_x) + 
                      (m_y * prm_Vector.m_y) + 
                      (m_z * prm_Vector.m_z) + 
                      (m_w * prm_Vector.m_w)); }
    /*!*/
    float			Angle(const CVector4& prm_Vector) const { 
              return (std::acosf(DotProduct(prm_Vector) * 
                                (1.0f / Length() * 
                                 prm_Vector.Length()))); }
    /*!*/
    void			Normalize() { *this *= 1.0f / Length(); }

    //! Unique Geometric Functions
    /*!
    \fn Perpendicular
    \brief Calculates a perpendicular vector
    \details Calculation made from determinant i(1, 0) and j(0, 1) resulting in: 
              i(y) - j(x) = (y, -x)
    */
    CVector4		CrossProduct(const CVector4& prm_Vector) const { 
                return CVector4(((m_y*prm_Vector.m_z) - (prm_Vector.m_y*m_z)), 
                                ((m_x*prm_Vector.m_z) - (prm_Vector.m_x*m_z)), 
                                ((m_x*prm_Vector.m_y) - (prm_Vector.m_x*m_y))); }
    /*!*/
    CVector4		UnitCrossProduct(const CVector4& prm_Vector) { 
                return (CrossProduct(prm_Vector) /= Length()); }

    //! Common comparison operators
    bool operator == (const CVector4& prm_Vector) const { return (m_x == prm_Vector.m_x) && 
                                                                 (m_y == prm_Vector.m_y) && 
                                                                 (m_z == prm_Vector.m_z) && 
                                                                 (m_w == prm_Vector.m_w); }
    bool operator != (const CVector4& prm_Vector) const { return (m_x != prm_Vector.m_x) || 
                                                                 (m_y != prm_Vector.m_y) || 
                                                                 (m_z == prm_Vector.m_z) ||
                                                                 (m_w != prm_Vector.m_w); }
    bool operator <= (const CVector4& prm_Vector) const { 
         return Length() <= prm_Vector.Length(); }
    bool operator >= (const CVector4& prm_Vector) const { 
         return Length() >= prm_Vector.Length(); }
    bool operator < (const CVector4& prm_Vector) const { 
         return Length() < prm_Vector.Length(); }
    bool operator > (const CVector4& prm_Vector) const { 
         return Length() <= prm_Vector.Length(); }
  };
}