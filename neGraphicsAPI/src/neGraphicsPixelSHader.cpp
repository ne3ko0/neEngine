#include "neGraphicsPixelShader.h"

#include "neGraphicsAPI.h"

#include <sstream>
#include <d3dcompiler.h>

namespace neEngineSDK
{
  CPixelShader::CPixelShader() : m_pPixelShader(nullptr)
  {

  }

  CPixelShader::~CPixelShader()
  {

  }

  int CPixelShader::create(String prmFileName, String prmEntryPoint, String prmShaderModel)
  {
    /************************************************************************/
    String fileName = "resource\\shader.hlsl";
    std::fstream myFileStream;
    myFileStream.open(fileName, std::ios::in | std::ios::out | std::ios::ate);
    unsigned int fileLeght = myFileStream.tellg();
    myFileStream.seekg(0, std::ios::beg);

    String pBuffer;
    pBuffer.resize(fileLeght + 1, 0);
    myFileStream.read(&pBuffer[0], fileLeght);

    myFileStream.close();
    /************************************************************************/
    // Compile the pixel shader
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
    hr = D3DCompile(pBuffer.c_str() /*LPCVOID pSrcData*/,
      sizeof(pBuffer.c_str())/*SIZE_T SrcDataSize*/,
      prmFileName.c_str(),
      NULL/*D3D_SHADER_MACRO *pDefines*/,
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

    // Create the pixel shader
    hr = pDevice->CreatePixelShader(m_pBlob->GetBufferPointer(), m_pBlob->GetBufferSize(), NULL, &m_pPixelShader);
    if (FAILED(hr))
    {
      m_pBlob->Release();
      return hr;
    }
  }

  void CPixelShader::destroy()
  {
    if (m_pPixelShader)
    {
      m_pPixelShader->Release();
      m_pPixelShader = nullptr;
    }
  }

  void* CPixelShader::getObject()
  {
    return reinterpret_cast<int*>(m_pPixelShader);
  }

  void** CPixelShader::getReference()
  {
    return reinterpret_cast<void**>(&m_pPixelShader);
  }

  void CPixelShader::Set(CGraphicsDeviceContext* pDeviceContext)
  {
  }

  }
