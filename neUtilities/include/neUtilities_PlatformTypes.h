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
}