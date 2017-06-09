
#include "neMathVector2i.h"

namespace neEngineSDK
{
  CVector2i::CVector2i()
  {
    m_X = 0;
    m_Y = 0;
  }

  CVector2i::CVector2i(int32 fX, int32 fY)
  {
    m_X = fX;
    m_Y = fY;

  }

  CVector2i::~CVector2i()
  {

  }

  CVector2i CVector2i::operator|(const CVector2i& RHV)
  {
    return CVector2i(m_X * RHV.m_X, m_Y * RHV.m_Y);
  }
				
  CVector2i CVector2i::operator+(const CVector2i& RHV)
  {
    return CVector2i(m_X + RHV.m_X, m_Y + RHV.m_Y);
  }

		
  CVector2i CVector2i::operator-(const CVector2i& RHV)
  {
    return CVector2i(m_X - RHV.m_X, m_Y - RHV.m_Y);
  }

  CVector2i CVector2i::operator*(int32 fEscalar)
  {
    return CVector2i(m_X*fEscalar, m_Y*fEscalar);
  }


  int32 CVector2i::VProduct(CVector2i vfA, CVector2i vfB)
  {

    int32 fResult;
    int32 a, b;

    a = vfA.m_X * vfB.m_Y;
    b = vfA.m_Y * vfB.m_X;

    fResult = a - b;

    return fResult;

  }

  int32  CVector2i::Vmagnitude()
  {
    int32 a, b, c;

    int32 iMagnitude;

    a = m_X*m_X;
    b = m_Y*m_Y;

    c = a + b;

    iMagnitude = (int32)std::sqrt(c);


    return iMagnitude;
  }

  CVector2i CVector2i::Normalize(CVector2i a)
  {

    CVector2i vResult;
    int32 iMagnitude = a.Vmagnitude();

    vResult.m_X = a.m_X / iMagnitude;
    vResult.m_Y = a.m_Y / iMagnitude;

    return vResult;

  }

}