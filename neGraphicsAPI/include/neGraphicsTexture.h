#pragma once
#include "neGraphicsPrerequisites.h"
#if NE_ACTIVE_PLATFORM == NE_PLATFORM_WINDOWS
#	include<d3d11.h>
#endif

namespace neEngineSDK
{

  struct TextureData
  {
#if NE_ACTIVE_PLATFORM == NE_PLATFORM_WINDOWS
    ID3D11Texture1D* myTexture1D;
    ID3D11Texture2D* myTexture2D;
#endif
  };

  class NE_GRAPHICS_EXPORT CTexture
  {
  public:
    CTexture();
    virtual ~CTexture();

    TextureData* m_TextureData;

    //Load Texture from file
    //Create empty texture

    virtual void LoadFromFile(const char* FileName) = 0;
    virtual void CreateEmpty() = 0;
    virtual void Release() = 0;
  };

}