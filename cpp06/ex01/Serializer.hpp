#pragma once

#include <stdint.h> // uintptr_t (<cstdint> does not exist in C++98)
#include "Data.hpp"

// Static-only utility class: all OCF members are private,
// so it cannot be instantiated or copied by the user.
class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data*     deserialize(uintptr_t raw);

    private:
        Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
        ~Serializer();
};
