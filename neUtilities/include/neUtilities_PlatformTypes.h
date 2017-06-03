/**********************************************************************/
/*
*@file		nePlatformTypes.h
*@author	Alberto Flores Guzmán
*date		15/05/2017
*@
*
*
*/
/**********************************************************************/
#pragma once
#include "neUtilities_PlatformDefines.h"
  

namespace neEngineSDK {

  typedef unsigned char			uint8;			//! 8-bit integer

  typedef unsigned short			uint16;			//! 16-bit integer

  typedef unsigned int			uint32;			//! 32-bit integer
#if NE_ACTIVE_COMPILER == NE_COMPILER_MSVC

  typedef unsigned __int64	uint64;			//! 64-bit integer for Microsoft Visual Compiler
#else

  typedef unsigned long		uint64;			//! 64-bit integer for any other compiler
#endif

                                      // Signed types

  typedef signed char				int8;			//! 8-bit integer

  typedef signed short			int16;			//! 16-bit integer

  typedef signed int				int32;			//! 32-bit integer
#if NE_ACTIVE_COMPILER == NE_COMPILER_MSVC

  typedef signed __int64		int64;			//! 64-bit integer for Microsoft Visual Compiler
#else

  typedef signed long			int64;			//! 64-bit integer for any other compiler
#endif

  // Size_t
#if ((NE_ACTIVE_ARCHITECTURE == NE_ARCH_x86_64) && (NE_ACTIVE_COMPILER == NE_COMPILER_MSVC))

  typedef unsigned __int64		SIZE_T;
#else

  typedef unsigned long			SIZE_T;
#endif

  /************************************************************************/
  /* 128 bits variable                                                    */
  /************************************************************************/

  MS_ALIGN(16) class QWord
  {
  public:
    uint64 m_lower;
    int64 m_upper;


    /************************************************************************/
    /*
    *@Brief The cast operator for casting/truncating to 64 bits.
    *@returns The lower 64 bits of the value
    */
    /************************************************************************/

    operator int64 () const
    {
      return m_lower;
    }


    /************************************************************************/
    /*
    *@brief   The default constructor for the QWord class
    */
    /************************************************************************/
    QWord() : m_lower(0), m_upper(0)
    {

    }

    QWord(bool from) : m_lower(from), m_upper(0)
    {

    }

    QWord(uint8 from) : m_lower(from), m_upper(0)
    {

    }


    QWord(int8 from) : m_lower(from), m_upper(0)
    {

    }

    QWord(uint16 from) : m_lower(from), m_upper(0)
    {

    }

    QWord(int16 from) : m_lower(from), m_upper(0)
    {

    }



    QWord(uint32 from) : m_lower(from), m_upper(0)
    {

    }

    QWord(int32 from) : m_lower(from), m_upper(0)
    {

    }



    QWord(uint64 from) : m_lower(from), m_upper(0)
    {

    }

    QWord(int64 from) : m_lower(from), m_upper(0)
    {

    }



    QWord(float from) : m_lower((uint64)from), m_upper(0)
    {

    }

    QWord(double from) : m_lower((uint64)from), m_upper(0)
    {

    }

  } GCC_ALIGN(16);

  typedef QWord int128;
  typedef QWord uint128;


  /************************************************************************/
  /* Character Types                                                      */
  /************************************************************************/

#if NE_ACTIVE_COMPILER == NE_COMPILER_MSVC || NE_ACTIVE_PLATFORM == NE_PLATFORM_PS4
  typedef wchar_t  WCHAR;
#else
  typedef unsigned short  WCHAR;
#endif
  typedef char	ANSICHAR;   //ANSI character type
  typedef WCHAR	UNICHAR;	//UNICODE character type 

                          /***************************************************/
                          /* Null data type                                  */
                          /***************************************************/

  typedef int32    TYPE_OF_NULL;
}