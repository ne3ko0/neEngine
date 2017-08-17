#pragma once

#include "neGraphicsPrerequisites.h"



#if NE_ACTIVE_PLATFORM == NE_PLATFORM_WINDOWS
#	include<d3d11.h>
#endif

namespace neEngineSDK
{
  class NE_GRAPHICS_EXPORT CShaderBase
  {
    
  public: 
    CShaderBase();
    virtual ~CShaderBase();

  public:
    static const String SM_VS;
    static const String SM_PS;

  protected:
    ID3DBlob* m_pBlob;
  };
}
