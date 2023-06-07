#include "syncserialport.hpp"

#include <fcntl.h>

using namespace Domain::Communication::Core::Models;
using namespace Domain::Communication::Infrastructure::Sync;

void SerialPort::open(Domain::Communication::Core::Models::SerialPortMode &&mode) 
{
    _mode = std::move(mode);
    _serialPort = ::open(_mode.port.data(), O_RDWR);

    if(_serialPort < 0) throw std::runtime_error("Cannot open serialport");
    if(tcgetattr(_serialPort, &_termios) != 0) throw std::runtime_error("Cannot get serial attributes");

    setSerialPortAttributes();

    if(tcsetattr(_serialPort, TCSANOW, &_termios) != 0) throw std::runtime_error("Cannot set serial attributes");
}

void SerialPort::send(const Domain::Communication::Core::Models::SerialPortData &data) 
{
    const auto dataToSend = data.dataLength;
    auto dataSent = std::size_t(0);    

    while(dataSent < dataToSend)
    {
        const auto result = write(_serialPort, data.data.get() + dataSent, data.dataLength - dataSent);
        if(result < 0)
            throw std::logic_error("Cannot send data!");

        dataSent += result;
    }
}

SerialPortData SerialPort::receive() 
{
    const auto readBufferSize = getReadBuffer();
    char readBuffer[readBufferSize];

    const auto readed = read(_serialPort, &readBuffer, readBufferSize);
    return {};
}

void SerialPort::setSerialPortAttributes() 
{
    
}