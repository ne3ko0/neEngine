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

  bool CPixelShader::create(const String& prmFileName, const String& prmEntryPoint, const String& prmShaderModel)
  {
    /************************************************************************/
    std::fstream myFileStream;
    myFileStream.open(prmFileName, std::ios::in | std::ios::out | std::ios::ate);
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
    hr = D3DCompile(pBuffer.c_str(),
      pBuffer.size(),
      prmFileName.c_str(),
      NULL,
      NULL,
      prmEntryPoint.c_str(),
      prmShaderModel.c_str(),
      dwShaderFlags,
      0,
      &m_pBlob,
      &pErrorBlob);
    if (FAILED(hr))
    {
      if (pErrorBlob != NULL)
        OutputDebugStringA((char*)pErrorBlob->GetBufferPointer());
      if (pErrorBlob) pErrorBlob->Release();
      return false;
    }
    if (pErrorBlob) pErrorBlob->Release();

    ID3D11Device** pRefDevice = reinterpret_cast<ID3D11Device**>(g_GraphicsAPI().m_Device.getReference());
    ID3D11Device* pDevice = *pRefDevice;

    // Create the pixel shader
    hr = pDevice->CreatePixelShader(m_pBlob->GetBufferPointer(), m_pBlob->GetBufferSize(), NULL, &m_pPixelShader);
    if (FAILED(hr))
    {
      m_pBlob->Release();
      return false;
    }

    return true;
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

  void CPixelShader::Set()
  {
    ID3D11DeviceContext* pD3DDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(g_GraphicsAPI().m_DeviceContext.getObject());
    pD3DDeviceContext->PSSetShader(m_pPixelShader, NULL, 0);
  }

}
