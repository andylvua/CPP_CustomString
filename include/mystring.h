#ifndef LAB1_CSTRING_ZINCHUKKRYVENYAROSHEVYCHKHARABARA_MYSTRING_H
#define LAB1_CSTRING_ZINCHUKKRYVENYAROSHEVYCHKHARABARA_MYSTRING_H

#include <iostream>
#include <cstring>

#pragma once

class my_str_t {
private:
    char *data_m;
    size_t capacity_m;
    size_t size_m;

    static size_t calculate_capacity(size_t size);

    static size_t calculate_min_capacity(size_t size);

    static size_t strlen(const char *cstr);

    static const size_t DEFAULT_CAPACITY = 15;
public:
    my_str_t();

    my_str_t(size_t size, char initial);

    explicit my_str_t(const char *cstr);

    explicit my_str_t(const std::string &str);

    my_str_t(const my_str_t &mystr);

    my_str_t &operator=(const my_str_t &mystr);

    void swap(my_str_t &other) noexcept;

    char &operator[](size_t idx);

    const char &operator[](size_t idx) const;

    char &at(size_t idx);

    const char &at(size_t idx) const;

    void reserve(size_t new_capacity);

    void shrink_to_fit();

    void resize(size_t new_size, char new_char = ' ');

    void clear();

    void insert(size_t idx, const my_str_t &str);

    void insert(size_t idx, const char *cstr);

    void append(const my_str_t &str);

    void append(char c);

    void append(const char *cstr);

    void erase(size_t begin, size_t size);

    size_t size() const noexcept;

    size_t capacity() const noexcept;

    const char *c_str() const;

    static constexpr size_t not_found = -1;

    size_t find(char c, size_t idx = 0);

    size_t find(const std::string &str, size_t idx = 0);

    size_t find(const char *cstr, size_t idx = 0);

    my_str_t substr(size_t begin, size_t size);

    ~my_str_t();
};

std::ostream &operator<<(std::ostream &stream, const my_str_t &str);

std::ostream &readline(std::ostream &stream, my_str_t &str);

std::istream &operator>>(std::istream &stream, my_str_t &str);


bool operator==(const my_str_t &str1, const my_str_t &str2);

bool operator!=(const my_str_t &str1, const my_str_t &str2);

bool operator>(const my_str_t &str1, const my_str_t &str2);

bool operator>=(const my_str_t &str1, const my_str_t &str2);

bool operator<(const my_str_t &str1, const my_str_t &str2);

bool operator<=(const my_str_t &str1, const my_str_t &str2);


bool operator==(const my_str_t &str1, const char *cstr2);

bool operator!=(const my_str_t &str1, const char *cstr2);

bool operator>(const my_str_t &str1, const char *cstr2);

bool operator>=(const my_str_t &str1, const char *cstr2);

bool operator<(const my_str_t &str1, const char *cstr2);

bool operator<=(const my_str_t &str1, const char *cstr2);


bool operator==(const char *cstr1, const my_str_t &str2);

bool operator!=(const char *cstr1, const my_str_t &str2);

bool operator>(const char *cstr1, const my_str_t &str2);

bool operator>=(const char *cstr1, const my_str_t &str2);

bool operator<(const char *cstr1, const my_str_t &str2);

bool operator<=(const char *cstr1, const my_str_t &str2);

#endif //LAB1_CSTRING_ZINCHUKKRYVENYAROSHEVYCHKHARABARA_MYSTRING_H
