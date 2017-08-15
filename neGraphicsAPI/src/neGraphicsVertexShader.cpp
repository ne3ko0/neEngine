#include "neGraphicsVertexShader.h"


#include <sstream>
#include <d3dcompiler.h>

namespace neEngineSDK
{
  CVertextShader::CVertextShader() : m_pVertexShader(nullptr)
  {

  }

  CVertextShader::~CVertextShader()
  {

  }

  int CVertextShader::create(String prmFileName, String prmEntryPoint, String prmShaderModel)
  {
    // Compile the vertex shader
    HRESULT hr = S_OK;

    DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined( DEBUG ) || defined( _DEBUG )
    // Set the D3DCOMPILE_DEBUG flag to embed debug information in the shaders.
    // Setting this flag improves the shader debugging experience, but still allows 
    // the shaders to be optimized and to run exactly the way they will run in 
    // the release configuration of this program.
    dwShaderFlags |= D3DCOMPILE_DEBUG;
#endif

    ID3DBlob* pErrorBlob;
    hr = D3DCompile(m_pVertexShader /*LPCVOID pSrcData*/,
                    sizeof(m_pVertexShader)/*SIZE_T SrcDataSize*/,
                    prmFileName.c_str(), NULL/*D3D_SHADER_MACRO *pDefines*/, 
                    NULL /*ID3DInclude *pInclude*/,
                    prmEntryPoint.c_str()/*LPCSTR pEntrypoint*/, 
                    0/*LPCSTR pTarget*/, 
                    NULL/*UINT Flags1*/,
                    NULL/*UINT Flags2*/, 
                    &pErrorBlob/*ID3DBlob ppCode*/, 
                    NULL/*ID3DBlob ppErrorMsgs*/);
    if (FAILED(hr))
    {
      if (pErrorBlob != NULL)
        OutputDebugStringA((char*)pErrorBlob->GetBufferPointer());
      if (pErrorBlob) pErrorBlob->Release();
      return hr;
    }
    if (pErrorBlob) pErrorBlob->Release();

    ID3D11Device** pRefDevice = reinterpret_cast<ID3D11Device**>(g_GraphicsAPI().m_Device.getReference());
    ID3D11Device* pDevice = *pRefDevice;

    // Create the vertex shader
    hr = pDevice->CreateVertexShader(m_pBlob->GetBufferPointer(), m_pBlob->GetBufferSize(), NULL, &m_pVertexShader);
    if (FAILED(hr))
    {
      m_pBlob->Release();
      return hr;
    }
  }

  void CVertextShader::destroy()
  {

  }

  void CVertextShader::Set(CGraphicsDeviceContext* pDeviceContext)
  {
  }


}
