#ifndef ISERIALPORT_HPP
#define ISERIALPORT_HPP

#include "domain/communication/core/models/serialportmode.hpp"
#include "domain/communication/core/models/serialportdata.hpp"

#include <functional>

namespace Domain
{
    namespace Communication
    {
        namespace Core 
        {
            namespace Adapter
            {
                class ISerialPort 
                {
                    public:
                        ISerialPort() = default;
                        virtual ~ISerialPort() = default;

                    public:
                        virtual void open(Domain::Communication::Core::Models::SerialPortMode &&mode) = 0;
                        virtual void send(const Domain::Communication::Core::Models::SerialPortData &data) = 0;                        
                        virtual Domain::Communication::Core::Models::SerialPortMode receive() = 0;
                        virtual void close() noexcept = 0;          

                    public:
                        inline virtual void onConnected(std::function<void()> &&cb) { throw std::runtime_error("This class is synchronised module"); };
                        inline virtual void onDisconnected(std::function<void()> &&cb) { throw std::runtime_error("This class is synchronised module"); };
                        inline virtual void onReceivedData(std::function<void(Domain::Communication::Core::Models::SerialPortData data)> &&cb) { throw std::runtime_error("This class is synchronised module"); };
                        inline virtual void onError(std::function<void(std::string error)> &cb) { throw std::runtime_error("This class is synchronised module"); };

                    public:
                        inline void setSendTimeout(const int timeout) { _sendTimeout = timeout; }
                        inline void setRecvTimeout(const int timeout) { _recvTimeout = timeout; }
                    public:
                        inline int getSendTimeout() const { return _sendTimeout; }
                        inline int getRecvTimeout() const { return _recvTimeout; }

                    private:              
                        int _sendTimeout = 0;
                        int _recvTimeout = 0;
                };
            }
        }
    }
}

#endif