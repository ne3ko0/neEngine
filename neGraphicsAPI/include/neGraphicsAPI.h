#pragma once

#include "neGraphicsPrerequisites.h"
#include <neModule.h>
#include "neGraphicsDevice.h"
#include "neGraphicsDeviceContext.h"
#include "neGraphicsSwapChain.h"
#include "neGraphicsRenderTargetView.h"
#include "neGraphicsVertexShader.h"

namespace neEngineSDK {

  class NE_GRAPHICS_EXPORT neGraphicsAPI : public Module<neGraphicsAPI>
  {
  public:
    CGraphicsDevice         m_Device;
    CGraphicsDeviceContext  m_DeviceContext;
    CSwapChain              m_SwapChain;
    CRenderTargetView       m_pBBUfferRTV;

    neGraphicsAPI() {}
    ~neGraphicsAPI();
  };

  NE_GRAPHICS_EXPORT neGraphicsAPI& g_GraphicsAPI();
}
