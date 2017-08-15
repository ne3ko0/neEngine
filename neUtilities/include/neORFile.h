#pragma once

#include "neUtilities_Prerequisites.h"
//#include "string"

namespace neEngineSDK
{
  void ORFile()
  {
    String fileName = "shader.hlsl";
    std::ifstream myFileStream(fileName, std::ios::binary & std::ios::ate);

    if (!myFileStream.is_open())
    {
      std::cout << "Error";

      return;
    }

    unsigned int fileLeght = myFileStream.tellg();
    myFileStream.seekg(std::fstream::beg);

    std::vector<char> pBuffer(fileLeght);
    myFileStream.read(&pBuffer[0], fileLeght);

    std::string myfileContent;
    myfileContent.reserve(fileLeght);
    myfileContent.insert(myfileContent.begin(), pBuffer.begin(), pBuffer.end());

    std::cout << "El Archivo pesa: " << fileLeght << " bytes" << std::endl;
    std::cout << "GG" << std::endl;

    std::ofstream fileOut("exitFile.txt", std::ios::binary);
    fileOut.write(reinterpret_cast<char*> (&myfileContent), sizeof(myfileContent));
    fileOut.close();

  }
}
