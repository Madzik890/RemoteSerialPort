#ifndef SERIALPORT_HPP
#define SERIALPORT_HPP

#include "domain/communication/core/adapter/iserialport.hpp"

namespace Domain
{
    namespace Communication
    {
        namespace Infrastructure
        {
            namespace Sync 
            {
                class SerialPort final : public Core::Adapter::ISerialPort
                {
                    public:
                        SerialPort() = default;
                        ~SerialPort() = default;

                    public:
                        void open(Domain::Communication::Core::Models::SerialPortMode &&mode) override;
                        void send(const Domain::Communication::Core::Models::SerialPortData &data) override;                        
                        Domain::Communication::Core::Models::SerialPortMode receive() override;
                        void close() noexcept override;

                    private:
                        Domain::Communication::Core::Models::SerialPortMode _mode{};
                };
            }
        }
    }
}

#endif