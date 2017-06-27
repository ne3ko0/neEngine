#pragma once
#include "neGraphicsPrerequisites.h"

#if NE_ACTIVE_PLATFORM == NE_PLATFORM_WINDOWS
#	include "d3d11.h"
#endif


namespace neEngineSDK
{
  class NE_GRAPHICS_EXPORT CGraphicsDeviceContext
  {
  private:
#if NE_ACTIVE_PLATFORM == NE_PLATFORM_WINDOWS
    ID3D11DeviceContext* pDeviceContext;
#endif

  public:
    CGraphicsDeviceContext();
    ~CGraphicsDeviceContext();
    void    create();
    void    destroy();
    void*   getObject();
    void**  getReference();
  };
}
