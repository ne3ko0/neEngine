#pragma once

#include "neGraphicsPrerequisites.h"
#include <neModule.h>
#include "neGraphicsDevice.h"
#include "neGraphicsDeviceContext.h"
#include "neGraphicsSwapChain.h"
#include "neGraphicsRenderTargetView.h"

namespace neEngineSDK {

  class NE_GRAPHICS_EXPORT neGraphicsAPI : public Module<neGraphicsAPI>
  {
  public:
    CGraphicsDevice         m_Device;
    CGraphicsDeviceContext  m_DeviceContext;
    CSwapChain              m_SwapChain;
    CRenderTargetView       m_pRenderTargetView;

    neGraphicsAPI() {}
    ~neGraphicsAPI();
  };

  NE_GRAPHICS_EXPORT neGraphicsAPI& g_GraphicsAPI();
}
