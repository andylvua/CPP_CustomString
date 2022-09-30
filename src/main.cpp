//
// Created by paul on 9/29/22.
//
#include <iostream>
#include "../include/mystring.h"

using std::cout, std::cin;

int main(){
    my_str_t test1 = my_str_t(19,'c');
    cout<<test1<<" "<<test1.capacity()<<std::endl;
    test1.reserve(50);
    cout<<test1.capacity()<<std::endl;
    cout<<test1.at(5)<<std::endl;
    test1.at(5) = 'z';
    cout<<test1<<std::endl;
    cout<<test1.size()<<std::endl;
    my_str_t test2 = test1;
    cout<<test2<<std::endl;
    return 0;
}