#include "neGraphicsVertexShader.h"

#include "neGraphicsAPI.h"

#include <fstream>
#include <d3dcompiler.h>

namespace neEngineSDK
{
  using std::ifstream;
  using std::ios;

  CVertexShader::CVertexShader() : m_pVertexShader(nullptr)
  {

  }

  CVertexShader::~CVertexShader()
  {

  }

  bool CVertexShader::create(const String& prmFileName, const String& prmEntryPoint, const String& prmShaderModel)
  {
    /************************************************************************/
    //Carga el código del archivo especificado
    ifstream myFileShaderStream;
    myFileShaderStream.open(prmFileName, ios::in | ios::ate);
    size_t fileLeghtShader = myFileShaderStream.tellg();
    myFileShaderStream.seekg(0, ios::beg);
    String pFileData(fileLeghtShader + 1, '\0');
    myFileShaderStream.read(&pFileData[0], fileLeghtShader);
    myFileShaderStream.close();
    /************************************************************************/
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
    hr = D3DCompile(pFileData.c_str(),
                    pFileData.size(),
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

    // Create the vertex shader
    hr = pDevice->CreateVertexShader(m_pBlob->GetBufferPointer(), m_pBlob->GetBufferSize(), NULL, &m_pVertexShader);
    if (FAILED(hr))
    {
      m_pBlob->Release();
      return false;
    }

    return true;
  }

  void CVertexShader::destroy()
  {
    if (m_pVertexShader)
    {
      m_pVertexShader->Release();
      m_pVertexShader = nullptr;
    }
  }

  void* CVertexShader::getObject()
  {
    return reinterpret_cast<int*>(m_pVertexShader);
  }

  void** CVertexShader::getReference()
  {
    return reinterpret_cast<void**>(&m_pVertexShader);
  }

  void CVertexShader::Set()
  {
    ID3D11DeviceContext* pD3DDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(g_GraphicsAPI().m_DeviceContext.getObject());
    pD3DDeviceContext->VSSetShader(m_pVertexShader, NULL, 0);
  }


}
