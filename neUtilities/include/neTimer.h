#pragma once

namespace neEngineSDK
{
  class neTimer
  {
  public:
    neTimer();
    ~neTimer();

    /**Reset the timer to zero */
    void reset();

    /**Returns time in milliseconds since timer was initialized or last reset.*/
    unsigned long getMilliseconds();

    /**Returns time in milliseconds since timer was initialized or last reset.*/
    unsigned long getMicroseconds();

    /**
    *Returns time in milliseconds since timer was initialized or last reset.
    *Only CPU timer measured.
    */
    unsigned long getMillisecondsCPU();

    /**
    *Returns time in microseconds since timer was initialized or last reset.
    *Only CPU timer measured.
    */
    unsigned long getMicrosecondsCPU();

    /**
    *Returns the time at with the timer was initialized,in milliseconds.
    *@return Time in milliseconds.
    */
    unsigned long getStartMs() const;

  private:
    struct Data;
    Data* m_pData;
  };
}