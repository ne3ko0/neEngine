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

    int create(String prmFileName, String prmEntryPoint, String prmShaderModel);
    void destroy();
    void Set(CGraphicsDeviceContext* pDeviceContext);
    void* getObject();
    void** getReference();
  };
}
