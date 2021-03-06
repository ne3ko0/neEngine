#pragma once
#include "neGraphicsPrerequisites.h"

#if NE_ACTIVE_PLATFORM == NE_PLATFORM_WINDOWS
#	include "d3d11.h"
#endif

namespace neEngineSDK
{
  class NE_GRAPHICS_EXPORT CSwapChain
  {
  private:
#if NE_ACTIVE_PLATFORM == NE_PLATFORM_WINDOWS
    IDXGISwapChain* m_pSwapChain;
#endif

  public:


    CSwapChain();
    ~CSwapChain();
    void create();
    void destroy();
    void* getObject();
    void** getReference();
  };
}