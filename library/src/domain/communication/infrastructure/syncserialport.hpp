#ifndef SERIALPORT_HPP
#define SERIALPORT_HPP

#include "domain/communication/core/adapter/iserialport.hpp"

#include <unistd.h>
#include <termios.h>

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
                        Domain::Communication::Core::Models::SerialPortData receive() override;                        

                    public:                        
                        inline void close() noexcept override { ::close(_serialPort); _serialPort = -1; }

                    private:
                        void setSerialPortAttributes();

                    private:
                        Domain::Communication::Core::Models::SerialPortMode _mode{};

                    private:
                        int _serialPort {-1};
                        termios _termios {};
                };
            }
        }
    }
}

#endif