#ifndef SERIALPORTMODE_HPP
#define SERIALPORTMODE_HPP

#include <stdint.h>
#include <string_view>

namespace Domain
{
    namespace Communication
    {
        namespace Core 
        {
            namespace Models
            {
                enum class BaudRate : uint32_t {
                    B_0 = 0,
                    B_50 = 50,
                    B_75 = 75,
                    B_110 = 110,
                    B_134 = 134,
                    B_150 = 150,
                    B_200 = 200,
                    B_300 = 300,
                    B_600 = 600,
                    B_1200 = 1200,
                    B_1800 = 1800,
                    B_2400 = 2400,
                    B_4800 = 4800,
                    B_9600 = 9600,
                    B_19200 = 19200,
                    B_38400 = 38400,
                    B_57600 = 57600,
                    B_115200 = 115200,
                    B_230400 = 230400,
                    B_460800 = 460800
                };

                 enum class NumDataBits : uint8_t {
                    FIVE = 0,
                    SIX,
                    SEVEN,
                    EIGHT,
                };

                enum class Parity : uint8_t {
                    NONE = 0,
                    EVEN,
                    ODD,
                };

                enum class NumStopBits : uint8_t {
                    ONE = 0,
                    TWO,
                };

                enum class HardwareFlowControl : uint8_t {
                    OFF = 0,
                    ON,
                };
                
                enum class SoftwareFlowControl : uint8_t {
                    OFF = 0,
                    ON,
                };

                struct SerialPortMode final
                {                    
                    BaudRate baudRate {BaudRate::B_9600};
                    NumDataBits numDataBits { NumDataBits::SEVEN };
                    HardwareFlowControl hardwareFlowControl { HardwareFlowControl::OFF };
                    SoftwareFlowControl softwareFlowControl { SoftwareFlowControl::OFF };
                    std::string_view port {};
                };
            }
        }
    }
}

#endif