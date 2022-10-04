//
// Created by Andrew Yaroshevych on 29.09.2022.
//

#include "../include/mystring.h"
#include <cmath>
#include <cstring>

const size_t my_str_t::not_found;

size_t my_str_t::calculate_capacity(size_t size) {
    return (size > 7) ? static_cast<size_t>
    (std::pow(2, std::ceil(std::log2(size + 1))) - 1) : DEFAULT_CAPACITY;
}

size_t my_str_t::calculate_min_capacity(size_t size) {
    return static_cast<size_t> ((16 * std::ceil(static_cast<double> (size + 1) / 16)) - 1);
}

size_t my_str_t::strlen(const char *cstr) {
    const char *s;

    for (s = cstr; *s; ++s);
    return (s - cstr);
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

    for (int i = 0; i < size_m; i++) {
        data_m[i] = initial;
    }

    data_m[size_m] = '\0';
}

my_str_t::my_str_t(const char *cstr) {
    size_m = strlen(cstr);

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

my_str_t::my_str_t(const my_str_t &mystr) : size_m{mystr.size_m}, capacity_m{mystr.capacity_m} {
    data_m = new char[capacity_m + 1];

    for (int i = 0; i < size_m; i++) {
        data_m[i] = mystr[i];
    }

    data_m[size_m] = '\0';
}

my_str_t &my_str_t::operator=(const my_str_t &mystr) {
    my_str_t tmp(mystr);
    swap(tmp);

    return *this;
}

void my_str_t::swap(my_str_t &other) noexcept {
    size_t tmp_size = size_m;
    size_m = other.size_m;
    other.size_m = tmp_size;

    size_t tmp_capacity = capacity_m;
    capacity_m = other.capacity_m;
    other.capacity_m = tmp_capacity;

    char *tmp_data = data_m;
    data_m = other.data_m;
    other.data_m = tmp_data;
}

char &my_str_t::operator[](size_t idx) {
    if (idx >= size_m) {
        throw std::out_of_range("Index is out of range");
    }

    return data_m[idx];
}

const char &my_str_t::operator[](size_t idx) const {
    if (idx >= size_m) {
        throw std::out_of_range("Index is out of range");
    }

    return data_m[idx];
}

char &my_str_t::at(size_t idx) {
    if (idx >= size_m) {
        throw std::out_of_range("Index is out of range");
    }

    return data_m[idx];
}

const char &my_str_t::at(size_t idx) const {
    if (idx >= size_m) {
        throw std::out_of_range("Index is out of range");
    }

    return data_m[idx];
}

void my_str_t::reserve(size_t new_capacity) {
    if (new_capacity <= capacity_m) {
        return;
    }

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
    char *new_data = new char[capacity_m + 1];

    std::memcpy(new_data, data_m, size_m + 1);

    delete[] data_m;
    data_m = new_data;
}

//Implementation may be wrong
void my_str_t::resize(size_t new_size, char new_char) {
    if (new_size == size_m) {
        return;
    }

    if (new_size > capacity_m) {
        reserve(calculate_capacity(new_size));

        for (size_t i = 0; i < new_size - size_m; ++i) {
            data_m[size_m + i] = new_char;
        }

        data_m[new_size] = '\0';
        size_m = new_size;

        return;
    }

    if (new_size > size_m) {
        for (size_t i = 0; i < new_size - size_m; ++i) {
            data_m[size_m + i] = new_char;
        }

        data_m[new_size] = '\0';
        size_m = new_size;

        return;
    } else {
        size_m = new_size;
        data_m[size_m] = '\0';
    }
}

//Not how was described in doc
void my_str_t::clear() {
    delete[] data_m;

    capacity_m = DEFAULT_CAPACITY;
    size_m = 0;
    data_m = new char[capacity_m + 1];
}

void my_str_t::insert(size_t idx, const my_str_t &str) {
    if (idx >= size_m) {
        throw std::out_of_range("Index is out of range");
    }

    size_t new_size = size_m + str.size_m;

    if (new_size > capacity_m) {
        reserve(calculate_capacity(new_size));
    }

    size_m = new_size;

    std::memmove(data_m + idx + str.size_m, data_m + idx, size_m - idx - str.size_m);
    std::memcpy(data_m + idx, str.data_m, str.size_m);

    data_m[size_m] = '\0';
}

void my_str_t::insert(size_t idx, const char *cstr) {
    if (idx >= size_m) {
        throw std::out_of_range("Index is out of range");
    }

    size_t cstr_size = strlen(cstr);

    size_t new_size = size_m + cstr_size;

    if (new_size > capacity_m) {
        reserve(calculate_capacity(new_size));
    }

    size_m = new_size;

    std::memmove(data_m + idx + cstr_size, data_m + idx, size_m - idx - cstr_size);
    std::memcpy(data_m + idx, cstr, cstr_size);

    data_m[size_m] = '\0';
}

void my_str_t::append(const my_str_t &str) {
    size_t new_size = size_m + str.size_m;

    if (new_size > capacity_m) {
        reserve(calculate_capacity(new_size));
    }

    size_m = new_size;

    std::memcpy(data_m + size_m - str.size_m, str.data_m, str.size_m);

    data_m[size_m] = '\0';
}

void my_str_t::append(char c) {
    if (size_m + 1 > capacity_m) {
        reserve(calculate_capacity(size_m + 1));
    }

    data_m[size_m] = c;

    size_m++;
    data_m[size_m] = '\0';
}

void my_str_t::append(const char *cstr) {
    size_t cstr_size = strlen(cstr);

    size_t new_size = size_m + cstr_size;

    if (new_size > capacity_m) {
        reserve(calculate_capacity(new_size));
    }

    size_m = new_size;

    std::memcpy(data_m + size_m - cstr_size, cstr, cstr_size);

    data_m[size_m] = '\0';
}

void my_str_t::erase(size_t begin, size_t size) {
    if (begin >= size_m) {
        throw std::out_of_range("Begin index is out of range");
    }

    size_t new_size = size_m - std::min(size, size_m - begin);
    char *new_data = new char[calculate_capacity(new_size) + 1];

    std::memmove(new_data, data_m, begin);

    if (size + begin < size_m) {
        std::memmove(new_data + begin, data_m + begin + size, size_m - size - begin);
    }

    size_m = new_size;
    new_data[size_m] = '\0';

    delete[] data_m;
    data_m = new_data;

    this->shrink_to_fit();
}

size_t my_str_t::size() const noexcept {
    return size_m;
}

size_t my_str_t::capacity() const noexcept {
    return capacity_m;
}

const char *my_str_t::c_str() const {
    return data_m;
}

size_t my_str_t::find(char c, size_t idx) {
    if (idx >= size_m) {
        throw std::out_of_range("Index out of range");
    }

    for (size_t i = idx; i < size_m; ++i) {
        if (c == data_m[i]) {
            return i;
        }
    }

    return not_found;
}

size_t my_str_t::find(const std::string &str, size_t idx) {
    size_t str_size = str.size();

    if (idx >= size_m) {
        throw std::out_of_range("Index out of range");
    }

    if (size_m - idx < str_size || str_size == 0) {
        return not_found;
    }

    for (size_t i = idx; i < size_m - str_size + 1; ++i) {
        if (data_m[i] == str.at(0)) {
            for (size_t j = 0; j < str_size; ++j) {
                if (data_m[i + j] != str.at(j)) {
                    break;
                }
                if (j == str_size - 1) {
                    return i;
                }
            }
        }
    }

    return not_found;
}

size_t my_str_t::find(const char *cstr, size_t idx) {
    size_t str_size = strlen(cstr);

    if (idx >= size_m) {
        throw std::out_of_range("Index out of range");
    }

    if (size_m - idx < str_size || str_size == 0) {
        return not_found;
    }

    for (size_t i = idx; i < size_m - str_size + 1; i++) {
        if (data_m[i] == cstr[0]) {
            for (size_t j = 0; j < str_size; ++j) {
                if (data_m[i + j] != cstr[j]) {
                    break;
                }
                if (j == str_size - 1) {
                    return i;
                }
            }
        }
    }

    return not_found;
}

my_str_t my_str_t::substr(size_t begin, size_t size) {
    if (begin >= size_m) {
        throw std::out_of_range("Begin index is out of range");
    }

    if (size == 0) {
        return {};
    }

    size_t new_size = std::min(size, size_m - begin);
    char *new_data = new char[new_size + 1];

    std::memcpy(new_data, data_m + begin, new_size);
    new_data[new_size] = '\0';

    my_str_t new_str(new_data);
    delete[] new_data;

    return new_str;
}

my_str_t::~my_str_t() {
    delete[] data_m;
}


std::ostream &operator<<(std::ostream &stream, const my_str_t &str) {
    stream << str.c_str();
    return stream;
}

std::istream &operator>>(std::istream &stream, my_str_t &str) {
    char *buffer = new char;
    stream >> buffer;
    str = my_str_t(buffer);
    delete buffer;
    return stream;
}

std::ostream &readline(std::ostream &stream, my_str_t &str) {
    return stream;
}

bool operator==(const my_str_t &str1, const my_str_t &str2) {
    size_t str1_size = str1.size();
    size_t str2_size = str2.size();

    if (str1_size != str2_size) {
        return false;
    }

    for (int i = 0; i < str1_size; ++i) {
        if (str1.at(i) != str2.at(i)) {
            return false;
        }
    }

    return true;
}

bool operator!=(const my_str_t &str1, const my_str_t &str2) {
    if (str1 == str2) {
        return false;
    }

    return true;
}

bool operator>(const my_str_t &str1, const my_str_t &str2) {
    size_t str1_size = str1.size();
    size_t str2_size = str2.size();

    if (str1 == str2) {
        return false;
    }

    if (str1_size >= str2_size) {
        for (int i = 0; i < str2_size; ++i) {
            if (str1.at(i) < str2.at(i)) {
                return false;
            }
        }

        return true;
    } else if (str1_size < str2_size) {
        for (int i = 0; i < str1_size; ++i) {
            if (str1.at(i) < str2.at(i)) {
                return false;
            } else if (str1.at(i) > str2.at(i)) {
                return true;
            }
        }
    }

    return false;
}

bool operator>=(const my_str_t &str1, const my_str_t &str2) {
    if (str1 == str2 || str1 > str2) {
        return true;
    }

    return false;
}

bool operator<(const my_str_t &str1, const my_str_t &str2) {
    if (str1 >= str2) {
        return false;
    }

    return true;
}

bool operator<=(const my_str_t &str1, const my_str_t &str2) {
    if (str1 > str2) {
        return false;
    }

    return true;
}

bool operator==(const my_str_t &str1, const char *cstr) {
    size_t str1_size = str1.size();
    size_t cstr_size = strlen(cstr);

    if (str1_size != cstr_size) {
        return false;
    }

    for (int i = 0; i < str1_size; ++i) {
        if (str1.at(i) != cstr[i]) {
            return false;
        }
    }

    return true;
}

bool operator!=(const my_str_t &str1, const char *cstr) {
    if (str1 == cstr) {
        return false;
    }

    return true;
}

bool operator>(const my_str_t &str1, const char *cstr) {
    size_t str1_size = str1.size();
    size_t cstr_size = strlen(cstr);

    if (str1 == cstr) {
        return false;
    }

    if (str1_size >= cstr_size) {
        for (int i = 0; i < cstr_size; ++i) {
            if (str1.at(i) < cstr[i]) {
                return false;
            }
        }

        return true;
    } else if (str1_size < cstr_size) {
        for (int i = 0; i < str1_size; ++i) {
            if (str1.at(i) < cstr[i]) {
                return false;
            } else if (str1.at(i) > cstr[i]) {
                return true;
            }
        }
    }
    return false;
}

bool operator>=(const my_str_t &str1, const char *cstr) {
    if (str1 == cstr || str1 > cstr) {
        return true;
    }

    return false;
}

bool operator<(const my_str_t &str1, const char *cstr) {
    if (str1 >= cstr) {
        return false;
    }

    return true;
}

bool operator<=(const my_str_t &str1, const char *cstr) {
    if (str1 > cstr) {
        return false;
    }

    return true;
}

bool operator==(const char *cstr1, const my_str_t &str2) {
    size_t str1_size = strlen(cstr1);
    size_t str2_size = str2.size();

    if (str1_size != str2_size) {
        return false;
    }

    for (int i = 0; i < str1_size; ++i) {
        if (cstr1[i] != str2.at(i)) {
            return false;
        }
    }

    return true;
}

bool operator!=(const char *cstr1, const my_str_t &str2) {
    if (cstr1 == str2) {
        return false;
    }

    return true;
}

bool operator>(const char *cstr1, const my_str_t &str2) {
    size_t str1_size = strlen(cstr1);
    size_t str2_size = str2.size();

    if (cstr1 == str2) {
        return false;
    }

    if (str1_size >= str2_size) {
        for (int i = 0; i < str2_size; ++i) {
            if (cstr1[i] < str2.at(i)) {
                return false;
            }
        }

        return true;
    } else if (str1_size < str2_size) {
        for (int i = 0; i < str1_size; ++i) {
            if (cstr1[i] < str2.at(i)) {
                return false;
            } else if (cstr1[i] > str2.at(i)) {
                return true;
            }
        }
    }

    return false;
}

bool operator>=(const char *cstr1, const my_str_t &str2) {
    if (cstr1 == str2 || cstr1 > str2) {
        return true;
    }

    return false;
}

bool operator<(const char *cstr1, const my_str_t &str2) {
    if (cstr1 >= str2) {
        return false;
    }

    return true;
}

bool operator<=(const char *cstr1, const my_str_t &str2) {
    if (cstr1 > str2) {
        return false;
    }

    return true;
}
