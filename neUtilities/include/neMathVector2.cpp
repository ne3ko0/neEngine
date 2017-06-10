#include "neMathVector2.h"

using namespace neEngineSDK;

CVector2::CVector2()
{
  m_X = 0;
  m_Y = 0;
}

CVector2::CVector2(float prm_x, float prm_y)
{
  m_X = prm_x;
  m_Y = prm_y;

}

CVector2::~CVector2()
{

}
CVector2 CVector2::operator+(const CVector2 & prm_Vector) const
 { return CVector2(m_X + prm_Vector.m_X, m_Y + prm_Vector.m_Y); 
}

CVector2 CVector2::operator-(const CVector2 & prm_Vector) const
{
  return CVector2(m_X - prm_Vector.m_X, m_Y - prm_Vector.m_Y);
}

CVector2 CVector2::operator*(const float prm_Scalar) const
{
  return CVector2(m_X * prm_Scalar, m_Y * prm_Scalar);
}

CVector2 neEngineSDK::CVector2::operator/(const float prm_Scalar) const
{
  return CVector2(m_X / prm_Scalar, m_Y / prm_Scalar);
}

CVector2 neEngineSDK::CVector2::operator+=(const CVector2 & prm_Vector)
{
  return (*this + prm_Vector);
}

CVector2 neEngineSDK::CVector2::operator-=(const CVector2 & prm_Vector)
{
  return (*this - prm_Vector);
}

CVector2 neEngineSDK::CVector2::operator*=(const float & prm_Scalar)
{
  return (*this * prm_Scalar);
}

CVector2 neEngineSDK::CVector2::operator/=(const float & prm_Scalar)
{
  return (*this / prm_Scalar);
}

float neEngineSDK::CVector2::Length() const
{
  return CMath::Sqrt(CMath::Power(m_X, 2.0f) +
    CMath::Power(m_Y, 2.0f));
}

float neEngineSDK::CVector2::SqrLength() const
{
  return (CMath::Power(m_X, 2.0f) +
    CMath::Power(m_Y, 2.0f));
}

float neEngineSDK::CVector2::DotProduct(const CVector2 & prm_Vector) const
{
  return ((m_X *
    prm_Vector.m_X) +
    (m_Y * prm_Vector.m_Y));
}

float neEngineSDK::CVector2::Direction() const
{
  return (std::atanf(m_Y / m_X));
}

void neEngineSDK::CVector2::Normalize()
{
  *this *= 1.0f / Length();
}

CVector2 neEngineSDK::CVector2::Perpendicular() const
{
  return CVector2(m_Y, -m_X);
}

CVector2 neEngineSDK::CVector2::UnitPerpendicular()
{
  return (Perpendicular() /= Length());
}

float neEngineSDK::CVector2::DotPerpendicular(const CVector2 & prm_Vector)
{
  return((m_X*prm_Vector.m_Y) -
    (m_Y*prm_Vector.m_X));
}

bool neEngineSDK::CVector2::operator==(const CVector2 & prm_Vector) const
{
  return (m_X == prm_Vector.m_X) &&
    (m_Y == prm_Vector.m_Y);
}

bool neEngineSDK::CVector2::operator!=(const CVector2 & prm_Vector) const
{
  return (m_X != prm_Vector.m_X) ||
    (m_Y != prm_Vector.m_Y);
}

bool neEngineSDK::CVector2::operator<=(const CVector2 & prm_Vector) const
{
  return Length() <= prm_Vector.Length();
}

bool neEngineSDK::CVector2::operator>=(const CVector2 & prm_Vector) const
{
  return Length() >= prm_Vector.Length();
}

bool neEngineSDK::CVector2::operator<(const CVector2 & prm_Vector) const
{
  return Length() < prm_Vector.Length();
}

bool neEngineSDK::CVector2::operator>(const CVector2 & prm_Vector) const
{
  return Length() <= prm_Vector.Length();
}