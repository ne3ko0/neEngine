#pragma once

#include "neGraphicsShader.h"

namespace neEngineSDK
{
  class NE_GRAPHICS_EXPORT CVertextShader : public CShaderBase
  {
  public:
    CVertextShader();
    ~CVertextShader();

  public:
    ID3D11VertexShader* m_pVertexShader;

    int create(String prmFileName, String prmEntryPoint, String prmShaderModel);
    void destroy();
    void Set(CGraphicsDeviceContext* pDeviceContext);
  };
}
