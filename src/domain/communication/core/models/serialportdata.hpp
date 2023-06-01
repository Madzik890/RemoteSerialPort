#ifndef SERIALPORTDATA_HPP
#define SERIALPORTDATA_HPP

#include <memory>

namespace Domain
{
    namespace Communication
    {
        namespace Core 
        {
            namespace Models
            {
                struct SerialPortData final
                {
                    public:
                        std::unique_ptr<unsigned char> data {nullptr};
                        std::size_t dataLength {0};
                };
            }
        }
    }
}

#endif