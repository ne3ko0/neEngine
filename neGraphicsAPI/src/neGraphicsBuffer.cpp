#include "neGraphicsBuffer.h"
#include "neGraphicsAPI.h"


namespace neEngineSDK
{
  CGraphicsBuffer::CGraphicsBuffer()
  {
    m_BufferData = new(BufferData);
  }

  CGraphicsBuffer::~CGraphicsBuffer()
  {
    Release();
  }

  void CGraphicsBuffer::Release()
  {
    if (m_BufferData)
    {
      m_BufferData->m_Buffer->Release();
    }

  }



  CBufferBase::CBufferBase() : m_pBufferBase(nullptr) {

  }

  CBufferBase::~CBufferBase()
  {
  }

  template<class T>
  CIndexBuffer<T>::CIndexBuffer() {

  }

  template<class T>
  CIndexBuffer<T>::~CIndexBuffer() {

  }

  template<typename T>
  void CIndexBuffer<T>::Add(T nIndex)
  {
    m_indexArray.push_back(nIndex);
  }

  template<typename T>
  void CIndexBuffer<T>::Add(const std::vector<T>& nIndexArray)
  {
    Add(&nIndexArray[0], nIndexArray.size());
  }

  template<typename T>
  void CIndexBuffer<T>::Add(T * pArray, unsigned int nNumObjects)
  {
    for (unsigned int i = 0; i < nNumObjects; ++i) {
      m_indexArray.push_back(pArray[i]);
    }
  }

  template<typename T>
  void CIndexBuffer<T>::Remove(unsigned int nIndex, unsigned int count)
  {
    m_indexArray.erase(m_indexArray.begin() + nIndex,
      (m_indexArray.begin() + nIndex) + (count - 1));
  }

  template<typename T>
  void CIndexBuffer<T>::Clear()
  {
    m_indexArray.clear();
  }

  template<typename T>
  void CIndexBuffer<T>::CreateHardwareBuffer(int usageFlags)
  {
    if (!m_indexArray.size()) {
      return;
    }
    D3D11_BUFFER_DESC indexBufferDesc;
    memset(&indexBufferDesc, 0; sizeof(D3D11_BUFFER_DESC));


    if (BUFFER_USAGE_FLAGS::kDEFAULT & usageFlags) {
      indexBufferDesc.Usage |= D3D11_USAGE_DEFAULT;
    }

    if (BUFFER_USAGE_FLAGS::KDYNAMIC & usageFlags) {
      indexBufferDesc |= D3D11_USAGE_DEFAULT;
    }

    indexBufferDesc.ByteWidth = sizeof(T) * m_indexArray.size();
    indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
    indexBufferDesc.CPUAccessFlags = 0;
    indexBufferDesc.MiscFlags = 0;
    indexBufferDesc.StructureByteStride = 0;

    neGraphicsAPI* pGraphicsAPI = g_GraphicsAPI().instancePtr();
    ID3D11Device* pDevice = reinterpret_cast<ID3D11Device*>(pGraphicsAPI->m_Device.getObject());

    D3D11_SUBRESOURCE_DATA srData;
    srData.pSysMem = &m_indexArray[0];
    srData.SysMemPitch = 0;
    srData.SysMemSlicePitch = 0;

    HRESULT result = pDevice->CreateBuffer(&indexBufferDesc, &srData, &m_pBufferBase);
    if (FAILED(result))
    {
      return false;
    }
  }
  typedef CIndexBuffer<unsigned short> CIndexBuffer16;
  typedef CIndexBuffer<unsigned int> CIndexBuffer32;


  //TODO: CVertexBuffer
  
}
