#ifndef SERIALPORT_HPP
#define SERIALPORT_HPP

#include "domain/communication/core/adapter/iserialport.hpp"

namespace Domain
{
    namespace Communication
    {
        namespace Infrastructure
        {
            class SerialPort final : public Core::Adapter::ISerialPort
            {
                public:
                    SerialPort() = default;
                    ~SerialPort() = default;
            };
        }
    }
}

#endif