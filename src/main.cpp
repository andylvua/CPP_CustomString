//
// Created by paul on 9/29/22.
//
#include <iostream>
#include "../include/mystring.h"

using std::cout, std::cin;

int main(){
    my_str_t test1 = my_str_t(15,'c');
    test1.at(3) = 'a';
    const char* help {"Helperar"};
    my_str_t test2 = my_str_t(help);
    const char arr = test2.at(5);
    std::string testing;
    cin>>testing;
    cout<<testing<<std::endl;
    std::cout<<arr<<std::endl;
    std::string help2 = "asdfsadfsad";
    my_str_t test3 = my_str_t(help2);

    my_str_t test4 = my_str_t(test2);
    test4.at(1) ='C';

    std::cout<<sizeof(test1)<<" "<<sizeof(test2)<<" "<<sizeof(test3)<<" "<<sizeof(test4)<<std::endl;
    cin>>test1;
    std::cout<<test1<<std::endl;
    std::cout<<test2<<std::endl;
    std::cout<<test3<<std::endl;
    std::cout<<test4<<std::endl;
    return 0;
}