#ifndef SERIALISATION_HPP
# define SERIALISATION_HPP

#include <stdint.h>
#include <iostream>

struct Data {
    std::string name;
    int age;
    char gender;

};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif