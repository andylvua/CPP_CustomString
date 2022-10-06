//
// Created by Andrew Yaroshevych on 06.10.2022.
//

// Methods to add:
/*
 * Empty constructor
 * char n constructor
 * copy constructor
 * operator =
 * []
 * at
 * reserve
 * shrink_to_fit
 * resize
 * clear
 * insert
 * append
 * erase
 * size
 * capacity
 * c_str
 * find
 * substr
 */

#include <iostream>
#include "../include/mystring.h"

int main() {
    my_str_t example("Hello world!");

    std::cout << example << std::endl;
    return 0;
}