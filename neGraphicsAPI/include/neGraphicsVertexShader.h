#pragma once

#include "neGraphicsShader.h"

namespace neEngineSDK
{
  class CGraphicsDeviceContext;

  class NE_GRAPHICS_EXPORT CVertexShader : public CShaderBase
  {
  public:
    CVertexShader();
    ~CVertexShader();

  public:
    ID3D11VertexShader* m_pVertexShader;

    bool create(const String& prmFileName, const String& prmEntryPoint, const String& prmShaderModel);
    void destroy();
    void Set();
    void* getObject();
    void** getReference();
  };
}
