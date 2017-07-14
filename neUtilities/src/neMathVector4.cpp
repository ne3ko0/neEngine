#include "neMathVector4.h"

namespace neEngineSDK
{

  CVector4::CVector4()
  {
    m_X = 0;
    m_Y = 0;
    m_Z = 0;
    m_Z = 0;
  }

  CVector4::CVector4(float prm_x, float prm_y, float prm_z, float prm_w)
  {
    m_X = prm_x;
    m_Y = prm_y;
    m_Z = prm_z;
    m_W = prm_w;
  }

  CVector4::~CVector4()
  {
  }

  CVector4 CVector4::operator+(const CVector4 & prm_Vector) const
  {
    return CVector4(m_X + prm_Vector.m_X, m_Y +
      prm_Vector.m_Y, m_Z +
      prm_Vector.m_Z, m_W +
      prm_Vector.m_W);
  }

  CVector4 CVector4::operator-(const CVector4 & prm_Vector) const
  {
    return CVector4(m_X - prm_Vector.m_X,
      m_Y - prm_Vector.m_Y,
      m_Z - prm_Vector.m_Z,
      m_W - prm_Vector.m_W);
  }

  CVector4 CVector4::operator*(const float prm_Scalar) const
  {
    return CVector4(m_X * prm_Scalar,
      m_Y * prm_Scalar, m_Z * prm_Scalar,
      m_W * prm_Scalar);
  }

  CVector4 CVector4::operator/(const float prm_Scalar) const
  {
    return CVector4(m_X / prm_Scalar,
      m_Y / prm_Scalar,
      m_Z / prm_Scalar,
      m_W / prm_Scalar);
  }

  CVector4 CVector4::operator+=(const CVector4 & prm_Vector)
  {
    return (*this + prm_Vector);
  }

  CVector4 CVector4::operator-=(const CVector4 & prm_Vector)
  {
    return (*this - prm_Vector);
  }

  CVector4 CVector4::operator*=(const float & prm_Scalar)
  {
    return (*this * prm_Scalar);
  }

  CVector4 CVector4::operator/=(const float & prm_Scalar)
  {
    return (*this / prm_Scalar);
  }

  float CVector4::Length() const
  {
    return CMath::Sqrt(CMath::Power(m_X, 2.0f) +
      CMath::Power(m_Y, 2.0f) +
      CMath::Power(m_Z, 2.0f) +
      CMath::Power(m_W, 2.0f));
  }
  float CVector4::SqrLength() const
  {
    return (CMath::Power(m_X, 2.0f) +
      CMath::Power(m_Y, 2.0f) +
      CMath::Power(m_Z, 2.0f) +
      CMath::Power(m_W, 2.0f));
  }

  float CVector4::DotProduct(const CVector4 & prm_Vector) const
  {
    return ((m_X * prm_Vector.m_X) +
      (m_Y * prm_Vector.m_Y) +
      (m_Z * prm_Vector.m_Z) +
      (m_W * prm_Vector.m_W));
  }

  float CVector4::Angle(const CVector4 & prm_Vector) const
  {
    return (std::acosf(DotProduct(prm_Vector) *
      (1.0f / Length() *
        prm_Vector.Length())));
  }

  CVector4 CVector4::Normalize()
  {
    return *this *= 1.0f / Length();
  }

  CVector4 CVector4::CrossProduct(const CVector4 & prm_Vector) const
  {
    //return CVector4(((m_Y*prm_Vector.m_Z) - (prm_Vector.m_Y*m_Z)),
    //                ((m_X*prm_Vector.m_Z) - (prm_Vector.m_X*m_Z)),
    //                ((m_X*prm_Vector.m_Y) - (prm_Vector.m_X*m_Y)));
    return CVector4();
  }

  CVector4 CVector4::UnitCrossProduct(const CVector4 & prm_Vector)
  {
    return (CrossProduct(prm_Vector) /= Length());
  }

  bool CVector4::operator==(const CVector4 & prm_Vector) const
  {
    return (m_X == prm_Vector.m_X) &&
      (m_Y == prm_Vector.m_Y) &&
      (m_Z == prm_Vector.m_Z) &&
      (m_W == prm_Vector.m_W);
  }

  bool CVector4::operator!=(const CVector4 & prm_Vector) const
  {
    return (m_X != prm_Vector.m_X) ||
      (m_Y != prm_Vector.m_Y) ||
      (m_Z == prm_Vector.m_Z) ||
      (m_W != prm_Vector.m_W);
  }

  bool CVector4::operator<=(const CVector4 & prm_Vector) const
  {
    return Length() <= prm_Vector.Length();
  }

  bool CVector4::operator>=(const CVector4 & prm_Vector) const
  {
    return Length() >= prm_Vector.Length();
  }

  bool CVector4::operator<(const CVector4 & prm_Vector) const
  {
    return Length() < prm_Vector.Length();
  }

  bool CVector4::operator>(const CVector4 & prm_Vector) const
  {
    return Length() <= prm_Vector.Length();
  }

}
