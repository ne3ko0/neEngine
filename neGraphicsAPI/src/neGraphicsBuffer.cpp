#include "neGraphicsBuffer.h"


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
    
  }
}