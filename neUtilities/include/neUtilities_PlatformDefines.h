/**********************************************************************/
/*
*@file		nePlatformDefines.h
*@author	Alberto Flores Guzmán
*date		15/05/2017
*@			Definitions to describe some target platforms
*
*This definitions are meant to describe the target platform
*/
/**********************************************************************/
#pragma once


/********************************************************************************************************/
/* Initial platform/compiler-related stff to set														*/
/********************************************************************************************************/
#define NE_PLATFORM_WINDOWS		1

#define NE_PLATFORM_LINUX		2

#define NE_PLATFORM_MACOSX		3

#define NE_PLATFORM_PS4			4

#define NE_PLATFORM_PSVITA		5

// Compilers

#define NE_COMPILER_MSVC		1

#define NE_COMPILER_GCC			2

#define NE_COMPILER_CLANG		3

#define NE_COMPILER_INTEL		4

// Architectures

#define NE_ARCH_x86_32			1

#define NE_ARCH_x86_64			2

// Endians
#define NE_ENDIAN_BIG			1
#define NE_ENDIAN_LITTLE		2

#define NE_ENDIAN

// Edition build
#define NE_EDITION_BUILD

// Active compiler
#if defined _MSC_VER

#define NE_ACTIVE_COMPILER		NE_COMPILER_MSVC

#define NE_COMPILER_VERSION		_MSC_VER

#define NE_THREAD_TYPE			__declspec(thread)

#elif defined __GNUC__
#define NE_ACTIVE_COMPILER		NE_COMPILER_GCC
#define NE_COMPILER_VERSION		(((__GNUC__)*100) + (__GNUC_MINOR__*10) + __GNUC_PATCHLEVEL__)
#define NE_THREAD_TYPE			__declspec(thread)

#elif defined __clang__
#define NE_ACTIVE_COMPILER		NE_COMPILER_CLANG
#define NE_COMPILER_VERSION		__clang_major__
#define NE_THREAD_TYPE			__thread

#elif defined __INTEL_COMPILER
#define NE_ACTIVE_COMPILER		NE_COMPILER_INTEL
#define NE_COMPILER_VERSION		__INTEL_COMPILER

#else
#pragma error "No known compiler"

#endif

// Compiler settings
#if NE_ACTIVE_COMPILER == NE_COMPILER_MSVC
#if NE_COMPILER_VERSION >= 1200
#define FORCE_INLINE __forceinline
#ifndef RESTRICT
#define RESTRICT __restrict
#endif
#endif
#elif defined (__MINGW32__)
#if !defined (FORCE_INLINE)
#define FORCE_INLINE __inline
#ifndef RESTRICT
#define RESTRICT
#endif
#endif
#else
#define FORCE_INLINE __inline
#ifndef RESTRICT
#define RESTRICT __restrict
#endif
#endif

/********************************************************************************************************/
/* Find the current platform																			*/
/********************************************************************************************************/
#if defined(__WIN32__) || defined(_WIN32)
#define NE_ACTIVE_PLATFORM NE_PLATFORM_WINDOWS
#elif defined(__APPLE_CC__)
#define NE_ACTIVE_PLATFORM NE_PLATFORM_MACOSX
#elif defined (__ORBIS__)
#define NE_ACTIVE_PLATFORM NE_PLATFORM_PS4
#elif defined (__psp2__)
#define NE_ACTIVE_PLATFORM NE_PLATFORM_PSVITA
#else
#define NE_ACTIVE_PLATFORM NE_PLATFORM_LINUX
#endif

// Active Architecture
#if defined(__x86_x64__) || defined(_M_X64)
#define NE_ACTIVE_ARCHITECTURE NE_ARCH_x86_64
#else

#define NE_ACTIVE_ARCHITECTURE NE_ARCH_x86_32
#endif

// Memory alignment
#if NE_ACTIVE_COMPILER == NE_COMPILER_MSVC
#define MS_ALIGN(n) __declspec(align(n))
#ifndef GCC_PACK
#define GCC_PACK(n)
#endif
#ifndef GCC_ALIGN
#define GCC_ALIGN(n)
#endif
#elif (NE_ACTIVE_COMPILER == NE_COMPILER_GCC && NE_PLATFORM == NE_PLATFORM_PS4)
#define GCC_ALIGN(n) __attribute__((__aligned__(n)))
#define MS_ALIGN
#define GCC_PACK(n)
#else
#define MS_ALIGN
#define GCC_PACK(n) __attribute__((packed, aligned(n)))
#define GCC_ALIGN(n) __attribute__((aligned(n)))
#endif

// Throw override
#if NE_ACTIVE_COMPILER == NE_COMPILER_MSVC
#define _NOEXCEPT noexcept
#elif NE_ACTIVE_COMPILER == NE_COMPILER_INTEL
#define _NOEXCEPT noexcept
#elif NE_ACTIVE_COMPILER == NE_COMPILER_GCC
#define _NOEXCEPT noexcept
#endif


// Windows
#if NE_ACTIVE_PLATFORM == NE_PLATFORM_WINDOWS
#if defined(NE_STATIC_LIB)
#define NE_UTILITY_EXPORT
#else
#if defined(NE_UTILITIES_EXPORTS)
#define NE_UTILITIES_EXPORT __declspec(dllexport)
#else
#if defined (__MINGW32__)
#define NE_UTILITIES_EXPORT	
#else
#define	NE_UTILITIES_EXPORT __declspec(dllimport)
#endif
#endif
#endif

#if defined(_DEBUG) || defined(DEBUG)
#define NE_DEBUG_MODE 1
#else
#define NE_DEBUG_MODE 0
#endif

#if NE_ACTIVE_COMPILER == NE_COMPILER_INTEL
#define NE_THREAD_LOCAL __declspec(thread)
#endif
#endif

// Linux and Mac
#if NE_ACTIVE_PLATFORM == NE_PLATFORM_LINUX || NE_ACTIVE_PLATFORM == NE_PLATFORM_MACOSX
#if defined(NE_GCC_VISIBILTY)
#define NE_UTILITY_EXPORT __attribute__((visibility("default")))
#else
#define NE_UTILITY_EXPORT
#endif

#define stricmp strcasecmp

#if defined(_DEBUG) || defined(DEBUG)
#define NE_DEBUG_MODE 1
#else
#define NE_DEBUG_MODE 0
#endif

#if NE_ACTIVE_COMPILER == NE_COMPILER_INTEL
#define NE_THREAD_LOCAL __declspec(thread)
#endif
#endif

// PS4
#if NE_ACTIVE_PLATFORM == NE_PLATFORM_PS4
#if defined(NE_STATIC_LIB)
#define NE_UTILITY_EXPORT
#else
#if defined(NE_UTILITIES_EXPORTS)
#define NE_UTILITY_EXPORT __declspec(dllexport)
#else
#if defined (__MINGW32__)
#define NE_UTILITY_EXPORT	
#else
#define	NE_UTILITY_EXPORT __declspec(dllexport)
#endif
#endif
#endif

#if defined(_DEBUG) || defined(DEBUG)
#define NE_DEBUG_MODE 1
#else
#define NE_DEBUG_MODE 0
#endif

#if NE_ACTIVE_COMPILER == NE_COMPILER_INTEL
#define NE_THREAD_LOCAL __declspec(thread)
#endif
#endif

// Debug modes
#if NE_DEBUG_MODE
#define NE_DEBUG_ONLY(x) x
#define NE_ASSERT(x) assert(x)
#else
#define NE_DEBUG_ONLY(x)
#define NE_ASSERT(x) assert(x)
#endif