#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;
    data.id = 42;
    data.name = "Marvin";
    data.value = 3.14;

    Data*     original = &data;
    uintptr_t raw = Serializer::serialize(original);
    Data*     restored = Serializer::deserialize(raw);

    std::cout << "original pointer : " << original << std::endl;
    std::cout << "serialized value : " << raw
              << " (hex 0x" << std::hex << raw << std::dec << ")" << std::endl;
    std::cout << "restored pointer : " << restored << std::endl;

    if (restored == original)
        std::cout << "OK: pointers are equal" << std::endl;
    else
        std::cout << "KO: pointers differ" << std::endl;

    std::cout << "restored data    : id=" << restored->id
              << " name=" << restored->name
              << " value=" << restored->value << std::endl;
    return 0;
}
