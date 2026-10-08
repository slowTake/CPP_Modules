#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other)
{
    (void)other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
    (void)other;
    return *this;
}

Serializer::~Serializer() {}

// reinterpret_cast: reinterprets the bits of the pointer as an integer.
// No value is changed, the address is just seen as a number.
uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

// The reverse: reinterpret the number as an address of a Data.
Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
