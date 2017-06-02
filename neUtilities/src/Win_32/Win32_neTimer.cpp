#include "neTimer.h"

#ifdef WIN32_LEAN_AND_MEAN
# define WIN32_LEAN_AND_MEAN
#endif
#if !defined(NOMINMAX) && defined(_MESC_VER)
# define NOMINMAX // Required to stop windows.h messing up std::min
#endif
#include <windows.h>
#include <time.h>

namespace neEngineSDK
{
  struct neTimer::Data
  {
    clock_t zeroClock;

    LARGE_INTEGER startTime;
    LARGE_INTEGER frequency;
  };

  neTimer::neTimer() {
    m_pData = new Data();
    reset();
  }

  neTimer::~neTimer() {
    delete m_pData;
  }

  void
    neTimer::reset() {
    QueryPerformanceFrequency(&m_pData->frequency);
    QueryPerformanceCounter(&m_pData->startTime);
    m_pData->zeroClock = clock();
  }
  unsigned long
    neTimer::getMicroseconds(){
    LARGE_INTEGER curTime;
    QueryPerformanceCounter(&curTime);

    LONGLONG newTime = curTime.QuadPart - m_pData->startTime.QuadPart;

    //Scale by 1000 for milliseconds
    unsigned long newTicks = static_cast<unsigned long>(1000 * newTime /
                                                        m_pData->startTime.QuadPart);
    return newTicks;
  }

  unsigned long
    neTimer::getStartMs() const {
    unsigned long newTicks =
      static_cast<unsigned long>(1000 * m_pData->startTime.QuadPart /
        m_pData->frequency.QuadPart);

    return newTicks;
  }
   unsigned long
     neTimer::getMilliseconds() {
     LARGE_INTEGER curTime;
     QueryPerformanceCounter(&curTime);

     LONGLONG newTime = curTime.QuadPart - m_pData->startTime.QuadPart;
     //Scale by 1000000 for microseconds
     unsigned long newMicro = static_cast<unsigned long>(1000000 * newTime /
       m_pData->frequency.QuadPart);

     return newMicro;
   }
   unsigned long 
     neTimer::getMillisecondsCPU(){
      clock_t newClock = clock();
      return static_cast<unsigned long>(static_cast<float>(newClock - m_pData->zeroClock) /
                                        (static_cast<float>(CLOCKS_PER_SEC) / 1000.0f));
  }

   unsigned long
     neTimer::getMicrosecondsCPU() {
     clock_t newClock = clock();
     return static_cast<unsigned long>(static_cast<float>(newClock - m_pData->zeroClock) /
                                      (static_cast<float>(CLOCKS_PER_SEC) / 1000000.0f));
   }
}