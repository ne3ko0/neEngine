#pragma once
#include "neGraphicsPrerequisites.h"
#include "neGraphicsDevice.h"
#include "neGraphicsDeviceContext.h"
//#include "neGraphicsShaders.h"

#if NE_ACTIVE_PLATFORM == NE_PLATFORM_WINDOWS
#	include <d3d11.h>
#endif


namespace neEngineSDK
{

  struct InputLayoutData
  {
#if NE_ACTIVE_PLATFORM == NE_PLATFORM_WINDOWS
    ID3D11InputLayout* m_VertexLayout;
   // Vector<D3D11_INPUT_ELEMENT_DESC> m_LayOutElement;
#endif
  };

  class NE_GRAPHICS_EXPORT CInputLayout
  {
  public:
    CInputLayout();
    ~CInputLayout();

    //Variables
    InputLayoutData* m_InputLayoutData;

    //M�todos
    //void create(const CGraphicsDevice* prmDevice, const CGraphicsShaders* prmShader, CGraphicsDeviceContext* prmInmediateContext);
    void AddInputElement(const char* prmSemanticName, uint32 prmSemanticIndex, DXGI_FORMAT prmFormat, uint32 prmInputSlot,
      uint32 prmAlignedByteOffset, D3D11_INPUT_CLASSIFICATION prmInputSlotClass, uint32 prmInstanceDataStepRate);
    void Set(CGraphicsDeviceContext* prmInmediateContext);
  };

}