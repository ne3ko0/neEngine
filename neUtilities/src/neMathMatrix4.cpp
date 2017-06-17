#include "neMathMatrix4.h"

using namespace neEngineSDK;

  CMatrix4::CMatrix4()
  {
  }


  CMatrix4::CMatrix4(float a, float b, float c, float d, float e, float f, float g, 
                     float h, float i, float j, float k, float l, float m, float n, 
                     float o, float p)
  {
    fMatrix[0][0] = a;
    fMatrix[0][1] = b;
    fMatrix[0][2] = c;
    fMatrix[0][3] = d;

    fMatrix[1][0] = e;
    fMatrix[1][1] = f;
    fMatrix[1][2] = g;
    fMatrix[1][3] = h;

    fMatrix[2][0] = i;
    fMatrix[2][1] = j;
    fMatrix[2][2] = k;
    fMatrix[2][3] = l;

    fMatrix[3][0] = m;
    fMatrix[3][1] = n;
    fMatrix[3][2] = o;
    fMatrix[3][3] = p;
  }

  CMatrix4::CMatrix4(CVector4* a, CVector4* b, CVector4* c, CVector4* d)
  {
    fMatrix[0][0] = a->m_X;
    fMatrix[0][1] = a->m_Y;
    fMatrix[0][2] = a->m_Z;
    fMatrix[0][3] = a->m_W;

    fMatrix[1][0] = b->m_X;
    fMatrix[1][1] = b->m_Y;
    fMatrix[1][2] = b->m_Z;
    fMatrix[1][3] = b->m_W;

    fMatrix[2][0] = c->m_X;
    fMatrix[2][1] = c->m_Y;
    fMatrix[2][2] = c->m_Z;
    fMatrix[2][3] = c->m_W;

    fMatrix[3][0] = d->m_X;
    fMatrix[3][1] = d->m_Y;
    fMatrix[3][2] = d->m_Z;
    fMatrix[3][3] = d->m_W;
  }


  CMatrix4::~CMatrix4()
  {
  }


  void  CMatrix4::add(const CMatrix4& fMa)
  {


    for (int i = 0; i < 4; i++)
    {

      for (int j = 0; i < 4; i++)
      {
        fMatrix[i][j] = fMatrix[i][j] + fMa.fMatrix[i][j];
      }

    }


  }
  void CMatrix4::rest(const CMatrix4& fMa)
  {


    for (int i = 0; i < 4; i++)
    {

      for (int j = 0; i < 4; i++)
      {
        fMatrix[i][j] = fMatrix[i][j] - fMa.fMatrix[i][j];
      }

    }


  }
  CMatrix4 CMatrix4::mult(const CMatrix4& fMa)
  {

    CMatrix4 Result;

    Result.fMatrix[0][0] = (fMatrix[0][0] * fMa.fMatrix[0][0]) + (fMatrix[0][1] + 
                            fMa.fMatrix[1][0]) + (fMatrix[0][2] * fMa.fMatrix[2][0]);
    Result.fMatrix[0][1] = (fMatrix[0][0] * fMa.fMatrix[0][1]) + (fMatrix[0][1] * 
                             fMa.fMatrix[1][1]) + (fMatrix[0][2] * fMa.fMatrix[2][1]);
    Result.fMatrix[0][2] = (fMatrix[0][0] * fMa.fMatrix[0][2]) + (fMatrix[0][1] * 
                            fMa.fMatrix[1][2]) + (fMatrix[0][2] * fMa.fMatrix[2][2]);
    Result.fMatrix[0][3] = (fMatrix[0][0] * fMa.fMatrix[0][3]) + (fMatrix[0][1] * 
                            fMa.fMatrix[1][3]) + (fMatrix[0][2] * fMa.fMatrix[2][3]);


    Result.fMatrix[1][0] = (fMatrix[1][0] * fMa.fMatrix[0][0]) + (fMatrix[1][1] + 
                            fMa.fMatrix[1][0]) + (fMatrix[1][2] * fMa.fMatrix[2][0]);
    Result.fMatrix[1][1] = (fMatrix[1][0] * fMa.fMatrix[0][1]) + (fMatrix[1][1] * 
                            fMa.fMatrix[1][1]) + (fMatrix[1][2] * fMa.fMatrix[2][1]);
    Result.fMatrix[1][2] = (fMatrix[1][0] * fMa.fMatrix[0][2]) + (fMatrix[1][1] * 
                            fMa.fMatrix[1][2]) + (fMatrix[1][2] * fMa.fMatrix[2][2]);
    Result.fMatrix[1][3] = (fMatrix[1][0] * fMa.fMatrix[0][3]) + (fMatrix[1][1] * 
                            fMa.fMatrix[1][3]) + (fMatrix[1][2] * fMa.fMatrix[2][3]);


    Result.fMatrix[2][0] = (fMatrix[2][0] * fMa.fMatrix[0][0]) + (fMatrix[2][1] + 
                            fMa.fMatrix[1][0]) + (fMatrix[2][2] * fMa.fMatrix[2][0]);
    Result.fMatrix[2][1] = (fMatrix[2][0] * fMa.fMatrix[0][1]) + (fMatrix[2][1] * 
                            fMa.fMatrix[1][1]) + (fMatrix[2][2] * fMa.fMatrix[2][1]);
    Result.fMatrix[2][2] = (fMatrix[2][0] * fMa.fMatrix[0][2]) + (fMatrix[2][1] * 
                            fMa.fMatrix[1][2]) + (fMatrix[2][2] * fMa.fMatrix[2][2]);
    Result.fMatrix[2][3] = (fMatrix[2][0] * fMa.fMatrix[0][3]) + (fMatrix[2][1] * 
                            fMa.fMatrix[1][3]) + (fMatrix[2][2] * fMa.fMatrix[2][3]);


    return Result;

  }



  void CMatrix4::Transposed()
  {
    CMatrix4 Temp;


    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        Temp.fMatrix[i][j] = fMatrix[i][j];
      }
    }




    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        fMatrix[j][i] = Temp.fMatrix[i][j];
      }
    }
  }

  /*
  C_Matrix4 C_Matrix4::Transposed(const C_Matrix4& fMa)
  {
  C_Matrix4 Result;

  for (int i = 0; i < 4; i++)
  {
  for (int j = 0; j < 4; j++)
  {
  Result.fMatrix[j][i] = fMa.fMatrix[i][j];
  }
  }


  return Result;
  }*/
