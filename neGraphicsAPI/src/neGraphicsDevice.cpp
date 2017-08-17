#include "neGraphicsDevice.h"

namespace neEngineSDK
{
  CGraphicsDevice::CGraphicsDevice()
  {
      m_pDevice = nullptr;   
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
    return reinterpret_cast<void*>(m_pDevice);
  }

  void** CGraphicsDevice::getReference()
  {
    return reinterpret_cast<void**>(&m_pDevice);
  }

  void CGraphicsDevice::destroy()
  {
    if (m_pDevice)
    {
      m_pDevice->Release();
      m_pDevice = nullptr;
    }
  }
}
