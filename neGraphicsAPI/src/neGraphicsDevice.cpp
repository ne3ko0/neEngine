#include "neGraphicsDevice.h"

namespace neEngineSDK
{
  CGraphicsDevice::CGraphicsDevice()
  {
      pDevice = nullptr;   
  }

  CGraphicsDevice::~CGraphicsDevice()
  {
    destroy();
  }
  void CGraphicsDevice::create()
  {

  }

  void* CGraphicsDevice::getObject()
  {
    return reinterpret_cast<void*>(pDevice);
  }

  void** CGraphicsDevice::getReference()
  {
    return reinterpret_cast<void**>(&pDevice);
  }

  void CGraphicsDevice::destroy()
  {
    if (pDevice)
    {
      pDevice->Release();
      pDevice = nullptr;
    }
  }
}
