#pragma once

#include "neUtilities_Prerequisites.h"
#include "neString.h"

namespace neEngineSDK
{
  using std::ios;

  class NE_UTILITIES_EXPORT CFile
  {
  public:
    void Open(const char* psFileName);
    void Write(const char* buffer, SIZE_T numBytes);
    void Read(char* outBuffer, SIZE_T numBytes);
    void Seek(SIZE_T position);
    SIZE_T GetIndexPos();
    SIZE_T ReadAndSave(const char * strFileName, char *& pOutData, SIZE_T & outSize);
    void Close();

  public:
    CFile();
    CFile(const char* psName);
    ~CFile();

  private:
    //FileStream m_File;
    String m_strFileName;
    SIZE_T m_Size;
    SIZE_T m_Position;
  };


}

