//
// Created by paul on 9/29/22.
//
#include <iostream>
#include "../include/mystring.h"


int main() {
    my_str_t example{"Hello, world!"};
    std::cout << example[1] << example.at(2) << std::endl;
    example.insert(7, "new ");
    std::cout << example << std::endl;
    example.erase(16, 1);
    my_str_t addition{};
    addition.append('!');
    addition.append(")");
    example.append(addition);
    std::cout << example << std::endl;
    std::cout << example.size() << " " << example.capacity() << std::endl;
    std::cout << example.find('!') << " " << example.substr(6, 4) << std::endl;
    return 0;
}