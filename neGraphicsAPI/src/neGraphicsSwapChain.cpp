#include "neGraphicsSwapChain.h"

namespace neEngineSDK
{
  CSwapChain::CSwapChain()
  {
    pSwapChain = nullptr;
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
    return reinterpret_cast<void*>(pSwapChain);
  }

  void** CSwapChain::getReference()
  {
    return reinterpret_cast<void**>(&pSwapChain);
  }

  void CSwapChain::destroy()
  {
    if (pSwapChain)
    {
      pSwapChain->Release();
      pSwapChain = nullptr;
    }
  }
}
