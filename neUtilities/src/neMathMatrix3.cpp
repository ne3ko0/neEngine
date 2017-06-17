#include "neMathMatrix3.h"



using namespace neEngineSDK;


  CMatrix3::CMatrix3()
  {
  }

  CMatrix3::~CMatrix3()
  {
  }

  void CMatrix3::add(const CMatrix3& fMa)
  {

    for (int i = 0; i < 3; i++)
    {

      for (int j = 0; i < 3; i++)
      {
        fMatrix[i][j] = fMatrix[i][j] + fMa.fMatrix[i][j];
      }

    }

  }
  void CMatrix3::rest(const CMatrix3& fMa)
  {
    for (int i = 0; i < 3; i++)
    {

      for (int j = 0; i < 3; i++)
      {
        fMatrix[i][j] = fMatrix[i][j] - fMa.fMatrix[i][j];
      }

    }
  }
  CMatrix3 CMatrix3::mult(const CMatrix3& fMa)
  {

    CMatrix3 Result;

    Result.fMatrix[0][0] = (fMatrix[0][0] * fMa.fMatrix[0][0]) +
      (fMatrix[0][1] + fMa.fMatrix[1][0]) +
      (fMatrix[0][2] * fMa.fMatrix[2][0]);
    Result.fMatrix[0][1] = (fMatrix[0][0] * fMa.fMatrix[0][1]) +
      (fMatrix[0][1] * fMa.fMatrix[1][1]) +
      (fMatrix[0][2] * fMa.fMatrix[2][1]);
    Result.fMatrix[0][2] = (fMatrix[0][0] * fMa.fMatrix[0][2]) +
      (fMatrix[0][1] * fMa.fMatrix[1][2]) +
      (fMatrix[0][2] * fMa.fMatrix[2][2]);


    Result.fMatrix[1][0] = (fMatrix[1][0] * fMa.fMatrix[0][0]) +
      (fMatrix[1][1] + fMa.fMatrix[1][0]) +
      (fMatrix[1][2] * fMa.fMatrix[2][0]);
    Result.fMatrix[1][1] = (fMatrix[1][0] * fMa.fMatrix[0][1]) +
      (fMatrix[1][1] * fMa.fMatrix[1][1]) +
      (fMatrix[1][2] * fMa.fMatrix[2][1]);
    Result.fMatrix[1][2] = (fMatrix[1][0] * fMa.fMatrix[0][2]) +
      (fMatrix[1][1] * fMa.fMatrix[1][2]) +
      (fMatrix[1][2] * fMa.fMatrix[2][2]);


    Result.fMatrix[2][0] = (fMatrix[2][0] * fMa.fMatrix[0][0]) +
      (fMatrix[2][1] + fMa.fMatrix[1][0]) +
      (fMatrix[2][2] * fMa.fMatrix[2][0]);
    Result.fMatrix[2][1] = (fMatrix[2][0] * fMa.fMatrix[0][1]) +
      (fMatrix[2][1] * fMa.fMatrix[1][1]) +
      (fMatrix[2][2] * fMa.fMatrix[2][1]);
    Result.fMatrix[2][2] = (fMatrix[2][0] * fMa.fMatrix[0][2]) +
      (fMatrix[2][1] * fMa.fMatrix[1][2]) +
      (fMatrix[2][2] * fMa.fMatrix[2][2]);

    return Result;
  }

  CMatrix3 CMatrix3::transposed(const CMatrix3& fMa)
  {

    CMatrix3 Result;

    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        Result.fMatrix[j][i] = fMa.fMatrix[i][j];
      }
    }
    return Result;
  }

  bool CMatrix3::operator==(CMatrix3 &MatrizA)
  {
    bool bIsTrue = false;
    int i, j;

    if ((m_iRows != MatrizA.m_iRows) || (m_iColumns != MatrizA.m_iColumns))
      return 0;
    else
    {
      for (i = 0; i < m_iRows; i++)
      {
        for (j = 0; i < m_iColumns; j++)
        {
          if (fMatrix[i][j] != MatrizA.fMatrix[i][j])
            return 0;
          else
            bIsTrue = true;
        }
      }
    }
    if (bIsTrue == true)
      return 1;
  }

  bool neEngineSDK::CMatrix3::operator&(CMatrix3 & MatrizA)
  {
    return false;
  }
