#include "neGraphicsRenderTargetView.h"

namespace neEngineSDK
{
  CRenderTargetView::CRenderTargetView()
  {
    pRenderTargetView = nullptr;
  }

  CRenderTargetView::~CRenderTargetView()
  {
    destroy();
  }
  void CRenderTargetView::create()
  {

  }

  void* CRenderTargetView::getObject()
  {
    return reinterpret_cast<void*>(pRenderTargetView);
  }

  void** CRenderTargetView::getReference()
  {
    return reinterpret_cast<void**>(&pRenderTargetView);
  }

  void CRenderTargetView::destroy()
  {
    if (pRenderTargetView)
    {
      pRenderTargetView->Release();
      pRenderTargetView = nullptr;
    }
  }
}
