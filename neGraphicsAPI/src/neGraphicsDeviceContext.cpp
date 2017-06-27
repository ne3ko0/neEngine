#include "..\include\neGraphicsDeviceContext.h"

namespace neEngineSDK
{
  CGraphicsDeviceContext::CGraphicsDeviceContext()
  {
    pDeviceContext = nullptr;
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
    if (pDeviceContext)
    {
      pDeviceContext->Release();
      pDeviceContext = nullptr;
    }
  }
  void * CGraphicsDeviceContext::getObject()
  {
    return reinterpret_cast<void*>(pDeviceContext);
  }
  void ** CGraphicsDeviceContext::getReference()
  {
    return reinterpret_cast<void**>(&pDeviceContext);
  }
}