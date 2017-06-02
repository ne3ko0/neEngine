#pragma once

#if NE_ACTIVE_PLATFORM == NE_PLATFORM_WINDOWS
#if defined (NE_CORE_STATIC_LIBRARY)
#define NE_CORE_EXPORT
#else
#if defined (NE_CORE_EXPORTS)
#define NE_CORE_EXPORT __declspec(dllexport)
#else
#if defined (__MINGW32__)
#define NE_CORE_EXPORT
#else
#define NE_CORE_EXPORT __declspec(dllimport)
#endif
#endif
#endif
#endif
