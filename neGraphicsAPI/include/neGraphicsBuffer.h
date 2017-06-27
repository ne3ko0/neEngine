#pragma once
#include "neGraphicsPrerequisites.h"
#include "neGraphicsDevice.h"
#include "neGraphicsDeviceContext.h"

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

}
