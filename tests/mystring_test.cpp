//
// Created by Andrew Yaroshevych on 02.10.2022.
//

#include <iostream>

#include "../include/mystring.h"
#include "gtest/gtest.h"


TEST(size, size) {
    my_str_t test1 = my_str_t("123456789");
    EXPECT_EQ(test1.size(), 9);
}

TEST(capacity, capacity) {
    my_str_t test1 = my_str_t("123456789");
    EXPECT_EQ(test1.capacity(), 15);

    my_str_t test2 = my_str_t("123456789abcdefg");
    EXPECT_EQ(test2.capacity(), 31);
}

TEST(at, at) {
    my_str_t test1 = my_str_t("123456789");
    EXPECT_EQ(test1.at(5), '6');
    EXPECT_THROW(test1.at(9), std::out_of_range);
}

TEST(at, const_at) {
    const my_str_t test1 = my_str_t("Hello");
    EXPECT_EQ(test1.at(0), 'H');
    EXPECT_EQ(test1.at(4), 'o');
    EXPECT_THROW(test1.at(5), std::out_of_range);
}

TEST(default_constructor, default_constructor) {
    my_str_t test1 = my_str_t();
    EXPECT_EQ(test1.size(), 0);
    EXPECT_EQ(test1.capacity(), 15);
}

TEST(constructor_with_size, constructor_with_size_default_case) {
    my_str_t test1 = my_str_t(15,'a');
    EXPECT_EQ(test1.size(), 15);
    EXPECT_EQ(test1.capacity(), 15);
    EXPECT_EQ(test1.at(0), 'a');
}

TEST(constructor_with_size, handles_size_zero) {
    my_str_t test2 = my_str_t(0,'a');
    EXPECT_EQ(test2.size(), 0);
    EXPECT_EQ(test2.capacity(), 15);
    EXPECT_THROW(test2.at(0), std::out_of_range);
}

TEST(constructor_with_size, handles_big_size) {
    my_str_t test3 = my_str_t(1024, 'a');
    EXPECT_EQ(test3.size(), 1024);
    EXPECT_EQ(test3.capacity(), 2047);
    EXPECT_EQ(test3.at(0), 'a');
    EXPECT_EQ(test3.at(1023), 'a');
    ASSERT_THROW(test3.at(1024), std::out_of_range);
}

TEST(cstr_constructor, cstr_constructor_default_case) {
    my_str_t test1 = my_str_t("Hello");
    EXPECT_EQ(test1.size(), 5);
    EXPECT_EQ(test1.capacity(), 15);
    EXPECT_EQ(test1.at(0), 'H');
    EXPECT_EQ(test1.at(4), 'o');
}

TEST(cstr_constructor, cstr_constructor_handles_empty_string) {
    my_str_t test2 = my_str_t("");
    EXPECT_EQ(test2.size(), 0);
    EXPECT_EQ(test2.capacity(), 15);
    ASSERT_THROW(test2.at(0), std::out_of_range);
}

TEST(string_constructor, string_constructor_default_case) {
    std::string str = "Hello, world!";
    my_str_t test1 = my_str_t(str);

    EXPECT_EQ(test1.size(), 13);
    EXPECT_EQ(test1.capacity(), 15);
    EXPECT_EQ(test1.at(0), 'H');
    EXPECT_EQ(test1.at(12), '!');
    EXPECT_THROW(test1.at(13), std::out_of_range);

    std::string str2 = "Hello. I am a string. I am not a char array.";
    my_str_t test2 = my_str_t(str2);

    EXPECT_EQ(test2.size(), 44);
    EXPECT_EQ(test2.capacity(), 63);
    EXPECT_EQ(test2.at(0), 'H');
    EXPECT_EQ(test2.at(43), '.');
    EXPECT_THROW(test2.at(44), std::out_of_range);
}

TEST(string_constructor, string_constructor_handles_empty_string) {
    std::string str = "";  // NOLINT(readability-redundant-string-init)
    my_str_t test1 = my_str_t(str);

    EXPECT_EQ(test1.size(), 0);
    EXPECT_EQ(test1.capacity(), 15);
    ASSERT_THROW(test1.at(0), std::out_of_range);
}


TEST(copy_constructor, copy_constructor) {
    my_str_t test1 = my_str_t("Hello");
    my_str_t test2 = my_str_t(test1);

    EXPECT_EQ(test1.size(), test2.size());
    EXPECT_EQ(test1.capacity(), test2.capacity());
    EXPECT_EQ(test1.at(0), test2.at(0));
    EXPECT_EQ(test1.at(4), test2.at(4));
}

TEST(assignment_operator, assignment_operator) {
    my_str_t test1 = my_str_t("Hello");
    my_str_t test2 = my_str_t("World");
    test2 = test1;

    EXPECT_EQ(test1.size(), test2.size());
    EXPECT_EQ(test1.capacity(), test2.capacity());
    EXPECT_EQ(test1.at(0), test2.at(0));
    EXPECT_EQ(test1.at(4), test2.at(4));
}

TEST(assignment_operator, assignment_oprator_handles_self_assignment) {
    my_str_t test1 = my_str_t("Hello");
    test1 = test1;

    EXPECT_EQ(test1.size(), 5);
    EXPECT_EQ(test1.capacity(), 15);
    EXPECT_EQ(test1.at(0), 'H');
    EXPECT_EQ(test1.at(4), 'o');
}


TEST(swap, swap) {
    my_str_t test1 = my_str_t("Hello, world!");
    my_str_t test2 = my_str_t("World, hello! Hello, world!");
    test1.swap(test2);

    EXPECT_EQ(test1.size(), 27);
    EXPECT_EQ(test1.capacity(), 31);
    EXPECT_EQ(test1.at(0), 'W');
    EXPECT_EQ(test1.at(26), '!');

    EXPECT_EQ(test2.size(), 13);
    EXPECT_EQ(test2.capacity(), 15);
    EXPECT_EQ(test2.at(0), 'H');
    EXPECT_EQ(test2.at(12), '!');
}

TEST(swap, swap_handles_self_swap) {
    my_str_t test1 = my_str_t("Hello, world!");
    test1.swap(test1);

    EXPECT_EQ(test1.size(), 13);
    EXPECT_EQ(test1.capacity(), 15);
    EXPECT_EQ(test1.at(0), 'H');
    EXPECT_EQ(test1.at(12), '!');
}

TEST(braces_operator, braces_operator) {
    my_str_t test1 = my_str_t("Hello, world!");
    EXPECT_EQ(test1[0], 'H');
    EXPECT_EQ(test1[12], '!');

    test1[0] = 'h';
    EXPECT_EQ(test1[0], 'h');
    EXPECT_EQ(test1[12], '!');

    test1[12] = '?';
    EXPECT_EQ(test1[0], 'h');
    EXPECT_EQ(test1[12], '?');
}

TEST(braces_operator, braces_operator_handles_out_of_range) {
    my_str_t test1 = my_str_t("Hello, world!");
    ASSERT_THROW(test1[13], std::out_of_range);
}

TEST(braces_operator, const_braces_operator) {
    const my_str_t test1 = my_str_t("Hello, world!");
    EXPECT_EQ(test1[0], 'H');
    EXPECT_EQ(test1[12], '!');
}

TEST(braces_operator, const_braces_operator_handles_out_of_range) {
    const my_str_t test1 = my_str_t("Hello, world!");
    ASSERT_THROW(test1[13], std::out_of_range);
}

TEST(reserve, reserve) {
    my_str_t test1 = my_str_t("Hello, world!");
    test1.reserve(100);

    EXPECT_EQ(test1.size(), 13);
    EXPECT_EQ(test1.capacity(), 100);
    EXPECT_EQ(test1.at(0), 'H');
    EXPECT_EQ(test1.at(12), '!');

    test1.reserve(10);

    EXPECT_EQ(test1.size(), 13);
    EXPECT_EQ(test1.capacity(), 100);

    test1.reserve(1000);

    EXPECT_EQ(test1.size(), 13);
    EXPECT_EQ(test1.capacity(), 1000);
}

TEST(shrink_to_fit, shrink_to_fit) {
    my_str_t test1 = my_str_t(300, 'a');

    EXPECT_EQ(test1.size(), 300);
    EXPECT_EQ(test1.capacity(), 511);

    test1.shrink_to_fit();

    EXPECT_EQ(test1.size(), 300);
    EXPECT_EQ(test1.capacity(), 303);
    EXPECT_EQ(test1.at(0), 'a');
    EXPECT_EQ(test1.at(299), 'a');

    EXPECT_THROW(test1.at(300), std::out_of_range);
}

TEST(resize, resize) {
    my_str_t test1 = my_str_t("Hello, world!");
    test1.resize(10, 'a');

    EXPECT_EQ(test1.size(), 13);
    EXPECT_EQ(test1.capacity(), 15);
    EXPECT_EQ(test1.at(0), 'a');

    test1.resize(15, 'b');

    EXPECT_EQ(test1.size(), 15);
    EXPECT_EQ(test1.capacity(), 15);
    EXPECT_EQ(test1.at(0), 'b');
    EXPECT_EQ(test1.at(14), 'b');
}

TEST(clear, clear) {
    my_str_t test1 = my_str_t("Hello, world!");
    test1.clear();

    EXPECT_EQ(test1.size(), 0);
    EXPECT_EQ(test1.capacity(), 15);
    EXPECT_THROW(test1.at(0), std::out_of_range);

    my_str_t test2 = my_str_t(100, 'a');
    test2.clear();

    EXPECT_EQ(test2.size(), 0);
    EXPECT_EQ(test2.capacity(), 15);
    EXPECT_THROW(test2.at(0), std::out_of_range);
}

TEST(insert, insert_string) {
    my_str_t test1 = my_str_t("Hello,world!");
    my_str_t to_insert = my_str_t(" beautiful ");

    test1.insert(6, to_insert);

    EXPECT_EQ(test1.size(), 23);
    EXPECT_EQ(test1.capacity(), 31);
    ASSERT_TRUE(test1 == "Hello, beautiful world!");
}

TEST(insert, insert_char_array) {
    my_str_t test1 = my_str_t("Hello,world!");
    const char* to_insert = " beautiful ";

    test1.insert(6, to_insert);

    EXPECT_EQ(test1.size(), 23);
    EXPECT_EQ(test1.capacity(), 31);
    ASSERT_TRUE(test1 == "Hello, beautiful world!");
}

TEST(insert, insert_handles_out_of_range) {
    my_str_t test1 = my_str_t("Hello,world!");
    my_str_t to_insert = my_str_t(" beautiful ");

    ASSERT_THROW(test1.insert(12, to_insert), std::out_of_range);
}

TEST(insert, insert_handles_empty_string) {
    my_str_t test1 = my_str_t("Hello, world!");
    my_str_t to_insert = my_str_t("");

    test1.insert(6, to_insert);

    EXPECT_EQ(test1.size(), 13);
    EXPECT_EQ(test1.capacity(), 15);
    ASSERT_TRUE(test1 == "Hello, world!");
}

TEST(append, append_string) {
    my_str_t test1 = my_str_t("Hello, ");
    my_str_t to_append = my_str_t("world!");
    test1.append(to_append);

    EXPECT_EQ(test1.size(), 13);
    EXPECT_EQ(test1.capacity(), 15);
    ASSERT_TRUE(test1 == "Hello, world!");

    my_str_t to_append2 = my_str_t(" What's about your capacity?");
    test1.append(to_append2);

    EXPECT_EQ(test1.size(), 41);
    EXPECT_EQ(test1.capacity(), 63);
    ASSERT_TRUE(test1 == "Hello, world! What's about your capacity?");
}

TEST(append, append_string_handles_empty_string) {
    my_str_t test1 = my_str_t("Hello");
    my_str_t to_append = my_str_t("");
    test1.append(to_append);

    EXPECT_EQ(test1.size(), 5);
    EXPECT_EQ(test1.capacity(), 15);
    ASSERT_TRUE(test1 == "Hello");
}

TEST(append, append_char) {
    my_str_t test1 = my_str_t("Hello");
    test1.append('!');

    EXPECT_EQ(test1.size(), 6);
    EXPECT_EQ(test1.capacity(), 15);
    ASSERT_TRUE(test1 == "Hello!");

    my_str_t test2 = my_str_t("Hello, world! What's about your capacity?");
    test2.append('!');

    EXPECT_EQ(test2.size(), 42);
    EXPECT_EQ(test2.capacity(), 63);
    ASSERT_TRUE(test2 == "Hello, world! What's about your capacity?!");
}

TEST(append, append_char_array) {
    my_str_t test1 = my_str_t("Hello, ");
    const char* to_append = "world!";
    test1.append(to_append);

    EXPECT_EQ(test1.size(), 13);
    EXPECT_EQ(test1.capacity(), 15);
    ASSERT_TRUE(test1 == "Hello, world!");

    const char* to_append2 = " What's about your capacity?";
    test1.append(to_append2);

    EXPECT_EQ(test1.size(), 41);
    EXPECT_EQ(test1.capacity(), 63);
    ASSERT_TRUE(test1 == "Hello, world! What's about your capacity?");
}

TEST(append, append_char_array_handles_empty_array) {
    my_str_t test1 = my_str_t("Hello");
    const char* to_append = "";
    test1.append(to_append);

    EXPECT_EQ(test1.size(), 5);
    EXPECT_EQ(test1.capacity(), 15);
    ASSERT_TRUE(test1 == "Hello");
}

TEST(erase, erase) {
    my_str_t test1 = my_str_t("Hello, world!");
    test1.erase(6, 1);

    EXPECT_EQ(test1.size(), 12);
    EXPECT_EQ(test1.capacity(), 15);
    std::cout << test1 << std::endl;
    ASSERT_TRUE(test1 == "Hello,world!");

    test1.erase(0, 13);

    EXPECT_EQ(test1.size(), 0);
    EXPECT_EQ(test1.capacity(), 15);
}

TEST(erase, erase_handles_out_of_range) {
    my_str_t test1 = my_str_t("Hello, world!");
    ASSERT_THROW(test1.erase(13, 1), std::out_of_range);
}

TEST(erase, erase_handles_empty_erase) {
    my_str_t test1 = my_str_t("Hello, world!");
    test1.erase(10, 0);

    EXPECT_EQ(test1.size(), 13);
    EXPECT_EQ(test1.capacity(), 15);
}

TEST(erase, erase_up_to_the_end) {
    my_str_t test1 = my_str_t("Hello, world!");
    test1.erase(10,10);
    EXPECT_EQ(test1.size(), 10);
    EXPECT_EQ(test1.capacity(), 15);
    ASSERT_TRUE(test1 == "Hello, wor");
}

TEST(cstr, cstr) {
    my_str_t test1 = my_str_t("Hello, world!");
    const char* cstr = test1.c_str();

    ASSERT_TRUE(test1 == cstr);
}

TEST(cstr, cstr_handles_empty_string) {
    my_str_t test1 = my_str_t("");
    const char* cstr = test1.c_str();

    ASSERT_TRUE(test1 == cstr);
}

TEST(find, find_char) {
    my_str_t test1 = my_str_t("Hello, world!");
    size_t pos = test1.find('o');

    EXPECT_EQ(pos, 4);

    pos = test1.find('o', 5);

    EXPECT_EQ(pos, 8);
}

TEST(find, find_char_handles_not_found) {
    my_str_t test1 = my_str_t("Hello, world!");
    size_t pos = test1.find('a');

    EXPECT_EQ(pos, my_str_t::not_found);
}

TEST(find, find_char_handles_out_of_range) {
    my_str_t test1 = my_str_t("Hello, world!");
    ASSERT_THROW(test1.find('o', 13), std::out_of_range);
}

TEST(find, find_string) {
    my_str_t test1 = my_str_t("Hello, world!");
    std::string to_find = "world";
    size_t pos = test1.find(to_find, 0);

    EXPECT_EQ(pos, 7);

    std::string to_find2 = "d!";
    pos = test1.find(to_find2, 11);

    EXPECT_EQ(pos, 11);
}

TEST(find, find_string_handles_not_found) {
    my_str_t test1 = my_str_t("Hello, world!");
    std::string to_find = "world!";
    size_t pos = test1.find(to_find, 11);

    EXPECT_EQ(pos, my_str_t::not_found);
}

TEST(find, find_string_handles_out_of_range) {
    my_str_t test1 = my_str_t("Hello, world!");
    std::string to_find = "world!";

    ASSERT_THROW(test1.find(to_find, 13), std::out_of_range);
}

TEST(find, find_string_handles_empty_string) {
    my_str_t test1 = my_str_t("Hello, world!");
    std::string to_find = ""; // NOLINT(readability-redundant-string-init)
    size_t pos = test1.find(to_find, 0);

    EXPECT_EQ(pos, my_str_t::not_found);
}

TEST(find, find_char_array) {
    my_str_t test1 = my_str_t("Hello, world!");
    const char* to_find = "world";
    size_t pos = test1.find(to_find, 0);

    EXPECT_EQ(pos, 7);

    const char* to_find2 = "d!";
    pos = test1.find(to_find2, 11);

    EXPECT_EQ(pos, 11);
}

TEST(find, find_char_array_handles_not_found) {
    my_str_t test1 = my_str_t("Hello, world!");
    const char* to_find = "world!";
    size_t pos = test1.find(to_find, 11);

    EXPECT_EQ(pos, my_str_t::not_found);
}

TEST(find, find_char_array_handles_out_of_range) {
    my_str_t test1 = my_str_t("Hello, world!");
    const char* to_find = "world!";

    ASSERT_THROW(test1.find(to_find, 13), std::out_of_range);
}

TEST(find, find_char_array_handles_empty_string) {
    my_str_t test1 = my_str_t("Hello, world!");
    const char* to_find = "";
    size_t pos = test1.find(to_find, 0);

    EXPECT_EQ(pos, my_str_t::not_found);
}
