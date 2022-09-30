
#include <iostream>
#include <cmath>
#include <cstring>
#include "./../include/mystring.h"

int main(){
    std::cout<<"Hello"<<std::endl;
    const char stringa[]{"Hello"};
    my_str_t test = my_str_t(10, 'a');
    my_str_t test2 = my_str_t(stringa);
    std::cout<<test.at(3)<<std::endl;
    std::cout<<test2.at(1)<<std::endl;
    std::cout<<test<<std::endl;
    std::cout<<"Created successfully"<<std::endl;
    return 0;
}

my_str_t::my_str_t(size_t size, char initial) {
    //define memsize
    size_t memsize = 16;
    if (size>=memsize) {
        memsize = static_cast<size_t>(pow(2, ceil(log2(size+1))));
    }

    //define capacity and size
    capacity_m = memsize-1;
    size_m = size;

    //allocate memory and create string
    data_m = new char[memsize];
    for (int i = 0; i < size_m; ++i) {
        *(data_m+i) = initial;
    }
    *(data_m+size_m) = '\0';
}
my_str_t::my_str_t(const char *cstr) {
    //count size of c string
    size_t csize = strlen(cstr);

    //define memsize
    size_t memsize = 16;
    if (csize>=memsize) {
        memsize = static_cast<size_t>(pow(2, ceil(log2(csize+1))));
    }

    //define capacity and size
    capacity_m = memsize-1;
    size_m = csize;

    //allocate memory for our string and copy values
    data_m = new char[memsize];
    for (int i = 0; i < size_m; ++i) {
        *(data_m+i) = *(cstr+i);
    }
    *(data_m+size_m) = '\0';
}

my_str_t::my_str_t(const std::string &str) {
    size_t ssize = str.size();

    size_t memsize = 16;
    if (ssize>=memsize) {
        memsize = static_cast<size_t>(pow(2, ceil(log2(ssize+1))));
    }

    capacity_m = memsize-1;
    size_m = ssize;

    data_m = new char[memsize];
    for (int i = 0; i < size_m; ++i) {
        *(data_m+i) = str.at(i);
    }
    *(data_m+size_m) = '\0';
}

my_str_t::my_str_t(const my_str_t &mystr) {
    size_m = mystr.size_m;
    capacity_m = mystr.capacity_m;

    size_t memsize = capacity_m + 1;

    data_m = new char[memsize];
    for (int i = 0; i < size_m; ++i) {
        *(data_m+i) = *(mystr.data_m+i);
    }
    *(data_m+size_m) = '\0';
}

my_str_t& my_str_t::operator=(const my_str_t& mystr) {
    my_str_t temp{mystr};
    swap(temp);
    return *this;
}

char &my_str_t::at(size_t idx) {
    return *(data_m+idx);
}

my_str_t::~my_str_t() {
    delete[] data_m;
}