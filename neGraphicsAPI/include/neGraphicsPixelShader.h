#pragma once

#include "neGraphicsShader.h"

namespace neEngineSDK
{
  class NE_GRAPHICS_EXPORT CPixelShader : CShaderBase
  {
    CPixelShader();
    ~CPixelShader();

  public:
    ID3D11PixelShader* m_PixelShader;

    int create(String prmFileName, String prmEntryPoint, String prmShaderModel);
    void destroy();
    void Set(CGraphicsDeviceContext* pDeviceContext);
  };
}