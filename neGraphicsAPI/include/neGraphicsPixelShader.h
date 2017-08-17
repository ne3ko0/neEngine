#pragma once

#include "neGraphicsShader.h"

namespace neEngineSDK
{
  class CGraphicsDeviceContext;

  class NE_GRAPHICS_EXPORT CPixelShader : CShaderBase
  {

    CPixelShader();
    ~CPixelShader();

  public:
    ID3D11PixelShader* m_pPixelShader;

    int create(String prmFileName, String prmEntryPoint, String prmShaderModel);
    void destroy();
    void Set(CGraphicsDeviceContext* pDeviceContext);
    void* getObject();
    void** getReference();
  };
}