/************************************************************************/
/**
* @File neGraphicsDefines.h
* @Author: Alberto Flores
* @Date:	23/06/2017
* @This file includes Platform's definition
*/
/************************************************************************/
#pragma once

#if NE_ACTIVE_PLATFORM == NE_PLATFORM_WINDOWS
  #if defined (NE_GRAPHICS_STATIC_LIBRARY)
    #define NE_GRAPHICS_EXPORT
  #else
    #if defined (NE_GRAPHICS_EXPORTS)
      #define NE_GRAPHICS_EXPORT __declspec(dllexport)
    #else
      #if defined (__MINGW32__)
       #define NE_GRAPHICS_EXPORT
      #else
        #define NE_GRAPHICS_EXPORT __declspec(dllimport)
      #endif
    #endif
  #endif
#endif