#pragma once

#include "neGraphicsShader.h"

namespace neEngineSDK
{
  class CGraphicsDeviceContext;

  class NE_GRAPHICS_EXPORT CPixelShader : CShaderBase
  {
  public:
    CPixelShader();
    ~CPixelShader();

  public:
    ID3D11PixelShader* m_pPixelShader;

    bool create(const String& prmFileName, const String& prmEntryPoint, const String& prmShaderModel);
    void destroy();
    void Set();
    void* getObject();
    void** getReference();
  };
}