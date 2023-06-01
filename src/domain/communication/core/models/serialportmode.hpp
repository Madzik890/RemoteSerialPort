#ifndef SERIALPORTMODE_HPP
#define SERIALPORTMODE_HPP

#include <string_view>

namespace Domain
{
    namespace Communication
    {
        namespace Core 
        {
            namespace Models
            {
                struct SerialPortMode final
                {
                    public:
                        std::string_view port {};
                };
            }
        }
    }
}

#endif