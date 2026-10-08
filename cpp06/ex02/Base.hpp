#pragma once

// Base only needs a virtual destructor: having at least one virtual
// function makes the class polymorphic, which is what dynamic_cast needs.
class Base
{
    public:
        virtual ~Base();
};
