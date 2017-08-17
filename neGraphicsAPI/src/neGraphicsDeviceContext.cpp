#include "..\include\neGraphicsDeviceContext.h"

namespace neEngineSDK
{
  CGraphicsDeviceContext::CGraphicsDeviceContext()
  {
    m_pDeviceContext = nullptr;
  }
  CGraphicsDeviceContext::~CGraphicsDeviceContext()
  {
    destroy();
  }
  void CGraphicsDeviceContext::create()
  {
  }
  void CGraphicsDeviceContext::destroy()
  {
    if (m_pDeviceContext)
    {
      m_pDeviceContext->Release();
      m_pDeviceContext = nullptr;
    }
  }
  void * CGraphicsDeviceContext::getObject()
  {
    return reinterpret_cast<void*>(m_pDeviceContext);
  }
  void ** CGraphicsDeviceContext::getReference()
  {
    return reinterpret_cast<void**>(&m_pDeviceContext);
  }
}