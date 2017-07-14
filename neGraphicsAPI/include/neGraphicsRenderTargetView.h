#pragma once
#include "neGraphicsPrerequisites.h"

#if NE_ACTIVE_PLATFORM == NE_PLATFORM_WINDOWS
#	include "d3d11.h"
#endif

namespace neEngineSDK
{
  class NE_GRAPHICS_EXPORT CRenderTargetView
  {
  private:
#if NE_ACTIVE_PLATFORM == NE_PLATFORM_WINDOWS
    ID3D11RenderTargetView* pRenderTargetView;
#endif

  public:
    CRenderTargetView();
    ~CRenderTargetView();
    void create();
    void destroy();
    void* getObject();
    void** getReference();
  };
}
