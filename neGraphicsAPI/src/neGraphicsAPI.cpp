#include "neGraphicsAPI.h"

namespace neEngineSDK {
  neGraphicsAPI::~neGraphicsAPI()
  {
    m_pBBUfferRTV.destroy();
    m_SwapChain.destroy();
    m_DeviceContext.destroy();
    m_Device.destroy();
  }

  neGraphicsAPI& g_GraphicsAPI()
  {
    return neGraphicsAPI::instance();
  }
}