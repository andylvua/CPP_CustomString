# Lab 1. Custom string
[![CMake](https://github.com/ucu-cs/lab1_cstring-zinchukkryvenyaroshevychkharabara/actions/workflows/cmake.yml/badge.svg)](https://github.com/ucu-cs/lab1_cstring-zinchukkryvenyaroshevychkharabara/actions/workflows/cmake.yml)
> Team members: Andrii Yaroshevych, Pavlo Kryven, Yurii Zinchuk and Yurii Kharabara

## Description
This is a simple implementation of the C++ string class.
It is a part of the first labs of the course "Principles of Computer Organization" at UCU.

## Installation

### Requirements
❯ CMake 3.24 or higher

❯ C++ compiler with C++14 support

❯ Git

❯ C++ IDE (optional). CLion is recommended.

> **Note**
>
> CMake is a mandatory requirement. If your CMake version is incompatible with the project,
> please, consider updating it. For more information, please, refer to the official CMake documentation.
> However, if you are using macOS or Linux, you can use the following command to install the latest version of CMake:
>
> ```bash
> // Mac OS
> $ sudo apt install cmake
> ```
>
> ```bash
> // Linux
> $ brew install cmake
> ```

To install the library, you need to clone the repository first:
```bash
$ mkdir ~/workspace
$ cd ~/workspace
$ git clone https://github.com/ucu-cs/lab1_cstring-zinchukkryvenyaroshevychkharabara
$ cd lab1_cstring-zinchukkryvenyaroshevychkharabara
```
> Replace `~/workspace` with the path to your workspace.
>
> Remember, if you want to change the name of the folder you clone the repository to,
> you can simply add the name of the folder after the repository URL.
> ```bash
> $ git clone https://github.com/ucu-cs/lab1_cstring-zinchukkryvenyaroshevychkharabara folder_name
> ```

### Building manually
> **Note**
>
> If you are using CLion, you can skip this step. IDE will automatically build the project for you.

Then, you can build the library using CMake:
```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
```

This will build the library and the tests.

## Usage
To use the library, you need to include the header file:
```cpp
#include "mystring.h"
```

After that, you can use the library:
```cpp
#include <iostream>
#include "mystring.h"


int main() {
    my_str_t example { "Hello, World!" };
    std::cout << example << std::endl;
    return 0;
}
```

## Testing
To run the tests, you need to build the library first.
Then, you can run the tests:
```bash
$ cd build
$ ctest -C
```

## Additional tasks implemented
- [x] Move constructor `my_str_t(my_str_t &&mystr);`
- [x] Assignment operator `my_str_t &operator=(my_str_t&& mystr);`
- [x] Concatenation operators
- [x] Multiplication operators

## License
The [MIT](https://choosealicense.com/licenses/mit/) License (MIT)

Copyright © 2022. Andrii Yaroshevych, Pavlo Kryven, Yurii Zinchuk and Yurii Kharabara
