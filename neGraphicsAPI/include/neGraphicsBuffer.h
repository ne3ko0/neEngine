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
    ID3D11Buffer* pBufferBase;


  };

  template<typename T>
  class CIndexBuffer : public CBufferBase
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
}
