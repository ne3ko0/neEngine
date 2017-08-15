#pragma once
#include "neGraphicsPrerequisites.h"
#include "neGraphicsDevice.h"
#include "neGraphicsDeviceContext.h"

#include <vector>

#if NE_ACTIVE_PLATFORM == NE_PLATFORM_WINDOWS
#	include <d3d11.h>
#endif


namespace neEngineSDK
{
  struct BufferData
  {
#if NE_ACTIVE_PLATFORM == NE_PLATFORM_WINDOWS
    BufferData() :
      m_Buffer(nullptr)
    {

    }

    ID3D11Buffer* m_Buffer;
#endif
  };


  class NE_GRAPHICS_EXPORT CGraphicsBuffer
  {
  public:
    CGraphicsBuffer();
    virtual	~CGraphicsBuffer();

    BufferData* m_BufferData;

    virtual	void Create(const CGraphicsDevice* pDevice, int32 flags) = 0;
    virtual	void SetBuffer(const CGraphicsDeviceContext* pDeviceContext, uint32 StarSlot = 0) = 0;
    virtual	void Release();
  };


  namespace BUFFER_USAGE_FLAGS {
    enum E {
      kDEFAULT = 0x00,
      KDYNAMIC = 0x01
    };
  }

  class NE_GRAPHICS_EXPORT CBufferBase
  {
  public:
    CBufferBase();
    virtual ~CBufferBase();

  protected:
    ID3D11Buffer* m_pBufferBase;


  };

  template<typename T>
  class NE_GRAPHICS_EXPORT CIndexBuffer : public CBufferBase
  {
  public:
    CIndexBuffer();
    ~CIndexBuffer();

    void Add(T nIndex);
    void Add(const std::vector<T>& nIndexArray);
    void Add(T* pArray, unsigned int nNumObjects);

    void Remove(unsigned int nIndex, unsigned int count = 1);
    void Clear();

    void CreateHardwareBuffer(int usageFlags = BUFFER_USAGE_FLAGS::kDEFAULT);

  private:
    std::vector<T> m_indexArray;
  };

  struct NEVERTEX
  {
    CVector4 position;
  };

  template<typename T>
  class CVertexBuffer : public CBufferBase
  {
  public:
    CVertexBuffer();
    ~CVertexBuffer();

    void Add(T nIndex);
    void Add(const std::vector<T>& nIndexArray);
    void Add(T* pArray, unsigned int nNumObjects);

    void Remove(unsigned int nIndex, unsigned int count = 1);
    void Clear();

    void CreateHardwareBuffer(int usageFlags = BUFFER_USAGE_FLAGS::kDEFAULT);
    void SetHardwareBuffer(uint32 Slot=0, uint32 offset=0);

  private:
    std::vector<T> m_vertexArray;
  };

  template<class T>
  CVertexBuffer<T>::CVertexBuffer() {

  }

  template<class T>
  CVertexBuffer<T>::~CVertexBuffer() {

  }

  template<typename T>
  void CVertexBuffer<T>::Add(T nVertex)
  {
    m_vertexArray.push_back(nVertex);
  }

  template<typename T>
  void CVertexBuffer<T>::Add(const std::vector<T>& nVertexArray)
  {
    Add(&nVertexArray[0], nVertexArray.size());
  }

  template<typename T>
  void CVertexBuffer<T>::Add(T * pArray, unsigned int nNumObjects)
  {
    for (unsigned int i = 0; i < nNumObjects; ++i) {
      m_vertexArray.push_back(pArray[i]);
    }
  }

  template<typename T>
  void CVertexBuffer<T>::Remove(unsigned int nvertex, unsigned int count)
  {
    m_vertexArray.erase(m_vertexArray.begin() + nvertex,
      (m_vertexArray.begin() + nvertex) + (count - 1));
  }

  template<typename T>
  void CVertexBuffer<T>::Clear()
  {
    m_vertexArray.clear();
  }

  template<typename T>
  void CVertexBuffer<T>::CreateHardwareBuffer(int usageFags)
  {
    if (!m_vertexArray.size()) {
      return;
    }
    D3D11_BUFFER_DESC vertexBufferDesc;
    memset(&vertexBufferDesc, 0, sizeof(D3D11_BUFFER_DESC));


    if (BUFFER_USAGE_FLAGS::kDEFAULT & usageFags) {
      vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
    }

    if (BUFFER_USAGE_FLAGS::KDYNAMIC & usageFags) {
      vertexBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
    }

    vertexBufferDesc.ByteWidth = sizeof(T) * m_vertexArray.size();
    vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    vertexBufferDesc.CPUAccessFlags = 0;
    vertexBufferDesc.MiscFlags = 0;
    vertexBufferDesc.StructureByteStride = 0;

    neGraphicsAPI* pGraphicsAPI = g_GraphicsAPI().instancePtr();
    ID3D11Device* pDevice = reinterpret_cast<ID3D11Device*>(pGraphicsAPI->m_Device.getObject());

    D3D11_SUBRESOURCE_DATA srData;
    srData.pSysMem = &m_vertexArray[0];
    srData.SysMemPitch = 0;
    srData.SysMemSlicePitch = 0;

    HRESULT result = pDevice->CreateBuffer(&vertexBufferDesc, &srData, &m_pBufferBase);
    if (FAILED(result))
    {
      return;
    }
  }

  template<typename T>
  void CVertexBuffer<T>::SetHardwareBuffer(uint32 Slot, uint32 offset)
  {
    neGraphicsAPI* pGraphicsAPI = g_GraphicsAPI().instancePtr();
    ID3D11DeviceContext* pDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(pGraphicsAPI->m_DeviceContext.getObject());

    // Set vertex buffer
    uint32 stride = sizeof(T);
    pDeviceContext->IASetVertexBuffers(Slot, 1, &m_pBufferBase, &stride, &offset);
  }
}

