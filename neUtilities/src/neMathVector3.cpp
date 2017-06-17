#include "neMathVector3.h"

using namespace neEngineSDK;

CVector3::CVector3()
{
  m_X = 0;
  m_Y = 0;
  m_Z = 0;
}

CVector3::CVector3(float prm_x, float prm_y, float prm_z)
{
  m_X = prm_x;
  m_Y = prm_y;
  m_Z = prm_z;

}

CVector3::~CVector3()
{
}

CVector3 CVector3::operator+(const CVector3 & prm_Vector) const
{
  return CVector3(m_X + prm_Vector.m_X,
    m_Y + prm_Vector.m_Y,
    m_Z + prm_Vector.m_Z);
}

CVector3 CVector3::operator-(const CVector3 & prm_Vector) const
{
  return CVector3(m_X - prm_Vector.m_X,
    m_Y - prm_Vector.m_Y,
    m_Z - prm_Vector.m_Z);
}

CVector3 CVector3::operator*(const float prm_Scalar) const
{
  return CVector3(m_X * prm_Scalar,
    m_Y * prm_Scalar,
    m_Z * prm_Scalar);
}

CVector3 neEngineSDK::CVector3::operator/(const float prm_Scalar) const
{
  return CVector3(m_X / prm_Scalar,
    m_Y / prm_Scalar,
    m_Z / prm_Scalar);
}

CVector3 CVector3::operator^(const CVector3 & RHV)
{
  return CVector3();
}

float CVector3::operator|(const CVector3 & RHV)
{
  return 0.0f;
}

CVector3 CVector3::operator+=(const CVector3 & prm_Vector)
{
  return (*this + prm_Vector);
}

CVector3 CVector3::operator-=(const CVector3 & prm_Vector)
{
  return (*this - prm_Vector);
}

CVector3 CVector3::operator*=(const float & prm_Scalar)
{
  return (*this * prm_Scalar);
}

CVector3 CVector3::operator/=(const float & prm_Scalar)
{
  return (*this / prm_Scalar);
}

float CVector3::Length() const
{
  return CMath::Sqrt(CMath::Power(m_X, 2.0f) +
    CMath::Power(m_Y, 2.0f) +
    CMath::Power(m_Z, 2.0f));
}

float CVector3::SqrLength() const
{
  return (CMath::Power(m_X, 2.0f) +
    CMath::Power(m_Y, 2.0f) +
    CMath::Power(m_Z, 2.0f));
}

float CVector3::DotProduct(const CVector3 & prm_Vector) const
{
  return ((m_X * prm_Vector.m_X) +
          (m_Y * prm_Vector.m_Y) +
          (m_Z * prm_Vector.m_Z));
}

float CVector3::Angle(const CVector3 & prm_Vector) const
{
  return (std::acosf(DotProduct(prm_Vector) *
                    (1.0f / Length() *
                    prm_Vector.Length())));
}

void CVector3::Normalize()
{
  *this *= 1.0f / Length();
}

CVector3 CVector3::CrossProduct(const CVector3 & prm_Vector) const
{
  return CVector3(((m_Y*prm_Vector.m_Z) - (prm_Vector.m_Y*m_Z)),
                  ((m_X*prm_Vector.m_Z) - (prm_Vector.m_X*m_Z)),
                  ((m_X*prm_Vector.m_Y) - (prm_Vector.m_X*m_Y)));
}

CVector3 CVector3::UnitCrossProduct(const CVector3 & prm_Vector)
{
  return (CrossProduct(prm_Vector) /= Length());
}

bool CVector3::operator==(const CVector3 & prm_Vector) const
{
  return (m_X == prm_Vector.m_X) && (m_Y == prm_Vector.m_Y) && (m_Z == prm_Vector.m_Z);
}

bool CVector3::operator!=(const CVector3 & prm_Vector) const
{
  return (m_X != prm_Vector.m_X) || (m_Y != prm_Vector.m_Y) || (m_Z == prm_Vector.m_Z);
}

bool CVector3::operator<=(const CVector3 & prm_Vector) const
{
  return Length() <= prm_Vector.Length();
}

bool CVector3::operator>=(const CVector3 & prm_Vector) const
{
  return Length() >= prm_Vector.Length();
}

bool CVector3::operator<(const CVector3 & prm_Vector) const
{
  return Length() < prm_Vector.Length();
}

bool CVector3::operator>(const CVector3 & prm_Vector) const
{
  return Length() <= prm_Vector.Length();
}
