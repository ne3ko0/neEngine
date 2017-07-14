#include "neGraphicsTexture.h"
#include "neFileManager.h"

namespace neEngineSDK
{
  CTexture::CTexture()
  {
  }
  CTexture::~CTexture()
  {
  }

  //void CTexture::LoadFromFile(const char* FileName)
  //{
  //  SIZE_T FileSize;
  //  char* TextureInfo;
  //  CFile myFile;


  //  myFile.ReadAndSave(FileName, TextureInfo, FileSize);

  //  //	m_TextureData->myTexture1D = TextureInfo;

  //}
  void CTexture::CreateEmpty()
  {
    m_TextureData->myTexture1D;
  }
  void CTexture::Release()
  {}


}