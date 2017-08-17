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

  int CVertexShader::create(String prmFileName, String prmEntryPoint, String prmShaderModel)
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
    hr = D3DCompile(pFileData.c_str() /*LPCVOID pSrcData*/,
                    sizeof(pFileData.c_str())/*SIZE_T SrcDataSize*/,
                    prmFileName.c_str(),
                    NULL/*D3D_SHADER_MACRO *pDefines*/, 
                    NULL /*ID3DInclude *pInclude*/,
                    prmEntryPoint.c_str()/*LPCSTR pEntrypoint*/, 
                    prmShaderModel.c_str()/*LPCSTR pTarget*/,
                    NULL/*UINT Flags1*/,
                    NULL/*UINT Flags2*/, 
                    &m_pBlob/*ID3DBlob ppCode*/, 
                    &pErrorBlob/*ID3DBlob ppErrorMsgs*/);
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

  void CVertexShader::Set(CGraphicsDeviceContext* pDeviceContext)
  {
  }


}
