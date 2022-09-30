
//
// Created by Andrew on 29.09.2022.
//

#include "../include/mystring.h"
#include <cmath>
#include <cstring>

size_t my_str_t::calculate_capacity(size_t size) {
    return (size > 7) ? static_cast<size_t>
    (std::pow(2, std::ceil(std::log2(size + 1))) - 1) : DEFAULT_CAPACITY;
}

size_t my_str_t::calculate_min_capacity(size_t size) {
    return static_cast<size_t> ((16 * std::ceil(static_cast<double> (size + 1) / 16)) - 1);
}

my_str_t::my_str_t() {
    size_m = 0;

    capacity_m = DEFAULT_CAPACITY;
    data_m = new char[DEFAULT_CAPACITY + 1];

    data_m[0] = '\0';
}

my_str_t::my_str_t(size_t size, char initial) {
    size_m = size;

    capacity_m = calculate_capacity(size_m);
    data_m = new char[capacity_m + 1];

    for (int i = 0; i < size; i++) {
        data_m[i] = initial;
    }

    data_m[size] = '\0';
}

my_str_t::my_str_t(const char *cstr) {
    size_m = std::strlen(cstr);

    capacity_m = calculate_capacity(size_m);
    data_m = new char[capacity_m + 1];

    for (int i = 0; i < size_m; i++) {
        data_m[i] = cstr[i];
    }

    data_m[size_m] = '\0';
}

my_str_t::my_str_t(const std::string &str) {
    size_m = str.size();

    capacity_m = calculate_capacity(size_m);
    data_m = new char[capacity_m + 1];

    for (int i = 0; i < size_m; i++) {
        data_m[i] = str[i];
    }

    data_m[size_m] = '\0';
}

my_str_t::my_str_t(const my_str_t &mystr): size_m{mystr.size_m}, capacity_m{mystr.capacity_m} {
    data_m = new char[capacity_m + 1];

    for (int i = 0; i < size_m; i++) {
        data_m[i] = mystr.at(i);
    }

    data_m[size_m] = '\0';
}

my_str_t &my_str_t::operator=(const my_str_t &mystr) {
    my_str_t tmp(mystr);
    swap(tmp);

    return *this;
}

void my_str_t::swap(my_str_t &other) noexcept {
    std::swap(size_m, other.size_m);
    std::swap(capacity_m, other.capacity_m);
    std::swap(data_m, other.data_m);
}

char &my_str_t::at(size_t idx) {
    if (idx > size_m) {
        throw std::out_of_range("Index is out of range");
    }
    return data_m[idx];
}

const char &my_str_t::at(size_t idx) const {
    if (idx > size_m) {
        throw std::out_of_range("Index is out of range");
    }
    return data_m[idx];
}

size_t my_str_t::size() const noexcept {
    return size_m;
}

size_t my_str_t::capacity() const noexcept {
    return capacity_m;
}

const char* my_str_t::c_str() const {
    return data_m;
}

my_str_t::~my_str_t() {
    delete[] data_m;
}

void my_str_t::reserve(size_t new_capacity) {
    if (new_capacity <= capacity_m) { return; }

    capacity_m = new_capacity;

    char *new_data = new char[capacity_m + 1];
    std::memcpy(new_data, data_m, size_m + 1);

    delete[] data_m;
    data_m = new_data;
}

// May be wrong. Inplace reallocation may be a better solution
void my_str_t::shrink_to_fit() {
    if (size_m == capacity_m) {
        return;
    }

    capacity_m = calculate_min_capacity(size_m);
    std::cout << capacity_m << std::endl;
    char* new_data = new char[capacity_m + 1];

    std::memcpy(new_data, data_m, size_m + 1);

    delete[] data_m;
    data_m = new_data;
}

void my_str_t::resize(size_t new_size, char new_char) {
    if (new_size <= size_m) {
        for (int i = 0; i < size_m; i++) {
            data_m[i] = new_char;
        }
    }
    else {
        if (new_size > capacity_m) {
            reserve(calculate_capacity(new_size));
        }
        for (int i = 0; i < new_size; i++) {
            data_m[i] = new_char;
        }
        data_m[new_size] = '\0';
    }
}

std::ostream& operator<<(std::ostream& stream, const my_str_t& str) {
    stream << str.c_str();
    return stream;
}

std::istream& operator>>(std::istream& stream, my_str_t& str) {
    char *buffer = new char;
    stream >> buffer;
    str = my_str_t(buffer);
    delete buffer;
    return stream;
}
