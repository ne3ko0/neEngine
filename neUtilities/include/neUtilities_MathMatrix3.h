/*!
\file neUtilities_MathMatrix3.h
\author Alberto Flores Guzm�n
\brief Declares the Matrix3 operations for the engine
\date 01-06-17

\details Declares a Matrix3 class, which exists inside NEEngineSDK namespace, and contains
Matrix3 operations

\version 1.0
\copyright Alberto Flores Guzm�n
*/

#pragma once
#include "neUtilities_Prerequisites.h"

#include <neUtilities_MathConstants.h>
/*!
\class CMatrix3
*/
namespace neEngineSDK {

  class NE_UTILITIES_EXPORT CMatrix3 {

  public:
    union
    {
      CVector3 m_row[3];
      float fMatrix[3][3];
      float m_Linear[9];

      struct
      {
        float m00, m01, m02,
          m10, m11, m12,
          m20, m21, m22;

      }m_Elements;


    };

    void  add(const CMatrix3& fMa);
    void rest(const CMatrix3& fMa);
    CMatrix3 mult(const CMatrix3& fMa);
    CMatrix3 transposed(const CMatrix3& fMa);
    CMatrix3 MultVector(const CMatrix3& fMa, const CVector3& v3);


    CMatrix3();

    ~CMatrix3();

  };

  /*!*/

}