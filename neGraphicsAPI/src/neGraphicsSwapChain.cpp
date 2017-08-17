#include "neGraphicsSwapChain.h"

namespace neEngineSDK
{
  CSwapChain::CSwapChain()
  {
    m_pSwapChain = nullptr;
  }

  CSwapChain::~CSwapChain()
  {
    destroy();
  }
  void CSwapChain::create()
  {

  }

  void* CSwapChain::getObject()
  {
    return reinterpret_cast<void*>(m_pSwapChain);
  }

  void** CSwapChain::getReference()
  {
    return reinterpret_cast<void**>(&m_pSwapChain);
  }

  void CSwapChain::destroy()
  {
    if (m_pSwapChain)
    {
      m_pSwapChain->Release();
      m_pSwapChain = nullptr;
    }
  }
}
