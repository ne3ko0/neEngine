#pragma once

#include "neCorePrerrequisites.h"
#include <neString.h>

namespace neEngineSDK
{
 
    class NE_CORE_EXPORT CApplicationBase
    {
    //Constructors / destructors
  public:
    CApplicationBase();
    virtual ~CApplicationBase();
    

  //Functions
     public:
      int run();

  //Accessors
      int getScreenHandle() { return m_screenHandle; }

      //Variables
      protected:
      int m_iScrWidth;
      int m_iScrHeight;

      String m_szTitle; // The title bar text

     protected:
       int m_screenHandle;
    };
}