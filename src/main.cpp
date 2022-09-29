//
// Created by paul on 9/29/22.
//
# include "../include/mystring.h"

int main(){
    my_str_t test = my_str_t(16, 'a');
    const char* cstr = "Hello";
    my_str_t test2 = my_str_t(cstr);
    std::string str = "Hello";
    my_str_t test3 = my_str_t(str);
    my_str_t test4 = my_str_t(test);

    test2.at(2) = 'q';
    std::cout << test.at(15) << std::endl;
    std::cout << test2.at(4) << std::endl;
    std::cout << test3.at(4) << std::endl;
    std::cout << test4.at(4) << std::endl;

    return 0;
}