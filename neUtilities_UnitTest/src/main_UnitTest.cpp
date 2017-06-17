#include "neUtilities_Prerequisites.h"
#include "neMathConstants.h"
#include "neMathVector2i.h"
#include "neMathMatrix3.h"
#include "neMathVector2.h"
#include "neMathVector3.h"

#include <gtest/gtest.h>
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <d3d11.h>
#include <directxMath.h>

using namespace neEngineSDK;
using std::numeric_limits;

  TEST(Utilities, types) {
    EXPECT_TRUE(sizeof(uint8) == 1);
    EXPECT_TRUE(sizeof(uint16) == 2);
    EXPECT_TRUE(sizeof(uint32) == 4);
    EXPECT_TRUE(sizeof(uint64) == 8);
    EXPECT_TRUE(sizeof(int8) == 1);
    EXPECT_TRUE(sizeof(int16) == 2);
    EXPECT_TRUE(sizeof(int32) == 4);
    EXPECT_TRUE(sizeof(int64) == 8);
    EXPECT_TRUE(sizeof(QWord) == 16);
    EXPECT_TRUE(sizeof(neEngineSDK::SIZE_T) == 8);
  }

  TEST(Utilities, Math) {
    EXPECT_TRUE(CMath::PI == atanf(1.f)* (4.f));
    EXPECT_TRUE(CMath::PIBYTWO == CMath::PI/2);
    EXPECT_TRUE(CMath::INVERSEPI == 1.f / CMath::PI);
    EXPECT_TRUE(CMath::TWOPI == CMath::PI * 2);
    EXPECT_TRUE(CMath::MIN_UINT8 == numeric_limits<uint8>::min());
    EXPECT_TRUE(CMath::MIN_UINT16 == numeric_limits <uint16>::min());
    EXPECT_TRUE(CMath::MIN_UINT32 == numeric_limits<uint32>::min());
    EXPECT_TRUE(CMath::MIN_INT8 == -CMath::Power(2, 8) / 2);
    EXPECT_TRUE(CMath::MIN_INT16 == -CMath::Power(2, 16) / 2);
    EXPECT_TRUE(CMath::MIN_INT32 == -CMath::Power(2, 32) / 2);
    EXPECT_FALSE(CMath::IsNan(CMath::MIN_FLOAT));
    EXPECT_TRUE(CMath::MAX_UINT8 == std::numeric_limits<uint8>::max());
    EXPECT_TRUE(CMath::MAX_UINT16 == std::numeric_limits<uint16>::max());
    EXPECT_TRUE(CMath::MAX_UINT32 == std::numeric_limits<uint32>::max());
    EXPECT_TRUE(CMath::MAX_INT8 == std::numeric_limits<int8>::max());
    EXPECT_TRUE(CMath::MAX_INT16 == std::numeric_limits<int16>::max());
    EXPECT_TRUE(CMath::MAX_INT32 == std::numeric_limits<int32>::max());
    EXPECT_TRUE(CMath::MAX_FLOAT == std::numeric_limits<float>::max());
    EXPECT_TRUE(CMath::F_INFINITE >= std::numeric_limits<float>::infinity());
    EXPECT_TRUE(CMath::Log2(2) == 1);
    EXPECT_TRUE(CMath::LogX(10,10) == 1);
    ASSERT_TRUE(CMath::Ceil(5.6f) == 6);
    EXPECT_TRUE(CMath::Floor(5.6) == 5);
    EXPECT_TRUE(CMath::Round(5.6) == 6);
    ASSERT_TRUE(CMath::Sqrt(9) == 3);
    EXPECT_TRUE(CMath::IsNegativeFloat(-1.f));
    EXPECT_TRUE(CMath::IsFinite(1));
    EXPECT_TRUE(CMath::IsNan(CMath::Sqrt(-1)));
    ASSERT_TRUE(CMath::Exponential(0) == 1);
    EXPECT_TRUE(CMath::Minimum(2, 5) == 2);
    EXPECT_TRUE(CMath::Maximum(5,2) == 5);

  }
    TEST(Utilities, Trigonometric) {
      EXPECT_TRUE(CMath::Sine(0) == 0);
      EXPECT_TRUE(CMath::Cosine(0) == 1);
      EXPECT_TRUE(CMath::Tangent(0) == 0);      
    }
   
    TEST(Utilities, Vector2) {

      CVector2 myVector2(2, 2);

      CVector2 myVector21(1, 1);

      CVector2 myVector22(3, 3);

      
      EXPECT_TRUE(myVector2.Length() == 2.8284271247f);

      EXPECT_TRUE(myVector2.m_X + myVector21.m_X == myVector22.m_X);
      EXPECT_TRUE(myVector2.m_Y + myVector21.m_Y == myVector22.m_Y);

      EXPECT_TRUE(myVector22.m_X - myVector21.m_X == myVector2.m_X);
      EXPECT_TRUE(myVector22.m_Y - myVector21.m_Y == myVector2.m_Y);

      EXPECT_TRUE(myVector22.m_X * 2 == 6);
      EXPECT_TRUE(myVector22.m_Y * 2 == 6);

    }

    TEST(Utilities, Vector2i) {
      CVector2i myVector2;
      myVector2.m_X = 2;
      myVector2.m_Y = 2;

      CVector2i myVector21;
      myVector21.m_X = 1;
      myVector21.m_Y = 1;

      CVector2i myVector22;
      myVector22.m_X = 3;
      myVector22.m_Y = 3;

      EXPECT_TRUE(myVector2.Vmagnitude() == 2);
      
      EXPECT_TRUE(myVector2.m_X + myVector21.m_X == myVector22.m_X);
      EXPECT_TRUE(myVector2.m_Y + myVector21.m_Y == myVector22.m_Y);

      EXPECT_TRUE(myVector22.m_X - myVector21.m_X == myVector2.m_X);
      EXPECT_TRUE(myVector22.m_Y - myVector21.m_Y == myVector2.m_Y);

      EXPECT_TRUE(myVector22.m_X | myVector21.m_X == myVector2.m_X);
      EXPECT_TRUE(myVector22.m_Y | myVector21.m_Y == myVector2.m_Y);

      EXPECT_TRUE(myVector22.m_X * 2 == 6);
      EXPECT_TRUE(myVector22.m_Y * 2 == 6);
     
    }

    TEST(Utilities, Vector3) {

      CVector3 myVector3(1, 2, 2);

      CVector3 myVector31(1, 1, 1);

      CVector3 myVector32(2, 3, 3);


      EXPECT_TRUE(myVector3.Length() == 3);
      EXPECT_TRUE(myVector3.SqrLength() == 9);
      EXPECT_TRUE(myVector3.DotProduct(myVector31) == 5);

      EXPECT_TRUE(myVector3.m_X + myVector31.m_X == myVector32.m_X);
      EXPECT_TRUE(myVector3.m_Y + myVector31.m_Y == myVector32.m_Y);
      EXPECT_TRUE(myVector3.m_Z + myVector31.m_Z == myVector32.m_Z);

      EXPECT_TRUE(myVector32.m_X - myVector31.m_X == myVector3.m_X);
      EXPECT_TRUE(myVector32.m_Y - myVector31.m_Y == myVector3.m_Y);
      EXPECT_TRUE(myVector32.m_Z - myVector31.m_Z == myVector3.m_Z);

      EXPECT_TRUE(myVector32.m_X * 2 == 4);
      EXPECT_TRUE(myVector32.m_Y * 2 == 6);

    }

    TEST(Utilities, Matrix3) {
      /*CMatrix3 Matrix;
      Matrix.m_Elements.m00 = 1; Matrix.m_Elements.m10 = 4; Matrix.m_Elements.m20 = 7;
      Matrix.m_Elements.m01 = 2; Matrix.m_Elements.m11 = 5; Matrix.m_Elements.m21 = 8;
      Matrix.m_Elements.m02 = 3; Matrix.m_Elements.m12 = 6; Matrix.m_Elements.m22 = 9;

      CMatrix3 Matrix1;
      Matrix1.m_Elements.m00 = 1; Matrix1.m_Elements.m10 = 2; Matrix1.m_Elements.m20 = 3;
      Matrix1.m_Elements.m01 = 4; Matrix1.m_Elements.m11 = 5; Matrix1.m_Elements.m21 = 6;
      Matrix1.m_Elements.m02 = 7; Matrix1.m_Elements.m12 = 6; Matrix1.m_Elements.m22 = 9;

      CMatrix3 Matrix2;
      Matrix2.m_Elements.m00 = 2; Matrix2.m_Elements.m10 = 6; Matrix2.m_Elements.m20 = 10;
      Matrix2.m_Elements.m01 = 6; Matrix2.m_Elements.m11 = 10; Matrix2.m_Elements.m21 = 14;
      Matrix2.m_Elements.m02 = 10; Matrix2.m_Elements.m12 = 12; Matrix2.m_Elements.m22 = 18;*/

    //  //CMatrix3 transposedMatrix = Matrix.transposed(Matrix1);

    //  //EXPECT_TRUE(transposedMatrix == Matrix2);
    }