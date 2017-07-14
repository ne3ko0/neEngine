#include <gtest/gtest.h>
#include <neApplicationBase.h>


//g_App.m_iScrHeight = 600;
//g_App.m_iScrWidth = 800;
namespace neEngineSDK {
  class CApplicationBaseTest : public CApplicationBase
  {
  public:
    CApplicationBaseTest()
    {
      m_iScrHeight = 600;
      m_iScrWidth = 800;
      m_szTitle = "Ventanon";
    }
  };
}
neEngineSDK::CApplicationBaseTest g_App;


int
main(int /*argc*/, char /**argv[]*/) {
  return g_App.run();
}