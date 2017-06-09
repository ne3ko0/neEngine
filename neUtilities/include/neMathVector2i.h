#pragma once

#include "neUtilities_Prerequisites.h"

namespace neEngineSDK
{
  class NE_UTILITIES_EXPORT CVector2i
  {
  public:

    int32 m_X;
    int32 m_Y;

    CVector2i operator|(const CVector2i& RHV);
	
    CVector2i operator+(const CVector2i& RHV);
				
    CVector2i operator-(const CVector2i& RHV);
   
    CVector2i operator*(int32 fEscalar);


    int32 VProduct(CVector2i vfA, CVector2i vfB);
    int32 Vmagnitude();
    CVector2i Normalize(CVector2i a);

    CVector2i();
    CVector2i(int32 iX, int32 iY);
    ~CVector2i();


  };
}