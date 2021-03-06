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

#include <neMathConstants.h>
#include "neMathVector4.h"

/*!
\class CMatrix4
*/
namespace neEngineSDK {

  MS_ALIGN(64) class NE_UTILITIES_EXPORT CMatrix4 {
  public:

    float fMatrix[4][4];


    union
    {
      CVector4 m_row[4];
      float fMatrix[4][4];
      float m_Linear[16];

      struct
      {
        float m00, m01, m02, m03,
          m10, m11, m12, m13,
          m20, m21, m22, m23,
          m30, m31, m32, m33;
      }m_Elements;

    };



    void add(const CMatrix4& fMa);//, const CMatrix4& fMb);
    void rest(const CMatrix4& fMa);//, const CMatrix4& fMb);
    CMatrix4 mult(const CMatrix4& fMa); //CMatrix4& fMb);

    void Transposed();//const C_Matrix4& fMa);
                      //C_Matrix4 Transposed(const C_Matrix4& fMa);


    CMatrix4();
    //C_Matrix4(C_Matrix4 a);
    CMatrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p);
    CMatrix4(CVector4* a, CVector4* b, CVector4* c, CVector4* d);
    ~CMatrix4();

  }GCC_ALIGN(64);


  /*!*/
}