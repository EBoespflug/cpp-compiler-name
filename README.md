# cpp-compiler-name

## Description

This repository is a micro-library for the C++ programming language providing simple access to the name and the version of the compiler. This library supports the following compilers : *Clang/LLVM*, *GNU G++*, *HP aC++*, *IBM XL C++*, *Intel ICPC*, *Microsoft Visual C++*, *Oracle Solaris C++*, *Portland PGCPP*.

For now, this library doesn't support the C specific information and shouldn't be used in a C project.

## Installation

This library is header-only and consists of the unique file [compiler_name.hpp](https://github.com/EBoespflug/cpp-compiler-name/blob/master/ccn.hpp).
To use it, include this header in your sources files.

## Usage

Here is an example of use of the library.

```c++
#include <iostream>
#include "ccn.hpp"

int main(int argc, char** argv)
{
    // With Preprocessor macros.
    std::cout << "Build on " __DATE__ " " __TIME__ " with [" CCN_COMPILER_COMPLETE_NAME " - " CCN_COMPILER_VERSION_NAME "]\n";

    // With compile-time values.
    std::cout << "Build on " __DATE__ " " __TIME__ " with [" << ccn::compiler_complete_name << " - " << ccn::compiler_version_name << "]\n";

    return 0;
}
```

The two lines are equivalents and print `Build on Sep 25 2016 18:09:11 with [GNU G++ - 5.3.0]` on my machine.

Please note that the compiler detection (by name or id) shouldn't be used to perform platform specific operations (`#include <unistd.h>` / `#include <Windows.h>` or `system()` calls for instance) without additional verifications (some compilers can be used on different platforms).

## Documentation

8 fields are defined for the compiler. Each field can be reached by a preprocessor macro or by a `constexpr` constant value. Macro are preceded by the prefix `CCN_` and values are contained in the namespace `ccn`. The following data are available :
- The complete name of the compiler (**CCN_COMPILER_COMPLETE_NAME** or **ccn::compiler_complete_name**) : represent an arbitrary complete name for the compiler. For instance "GNU G++" or "Microsoft Visual C++".
- The name of the compiler (**CCN_COMPILER_NAME** or **ccn::compiler_name**) : represent an arbitrary simple name for the compiler. For instance "G++" or "MSVC".
- An unique id (**CCN_COMPILER_ID** or **ccn::compiler_id**) : this `unsigned` value identify the compiler. It can be useful when working with templates or conditional compilation.

- The major version number of the compiler (**CCN_COMPILER_VERSION_MAJOR** or **ccn::compiler_version_major**) : this field may be invalid (`0u`) with some compilers (*Microsoft Visual C++*, *Oracle Solaris*, *IBM XL C++* or *HP aC++*).
- The minor version number of the compiler (**CCN_COMPILER_VERSION_MINOR** or **ccn::compiler_version_minor**) : in the same way as for the major version, the value will be `0u` for the compilers quoted previously.
- The patch level version number of the compiler (**CCN_COMPILER_VERSION_PATCH** or **ccn::compiler_version_patch**) : besides the previous compilers, old versions of *GNU G++* and *Intel ICPC* may not supply this value.

- The version name of the compiler (**CCN_COMPILER_VERSION_NAME** or **ccn::compiler_version_name**) : if the version numbers are supplied, this field is in the form "major.minor.patch_level", otherwise a supplied version name string is used. The version name is never an empty string.
- The complete version name of the compiler (**CCN_COMPILER_VERSION_COMPLETE_NAME** or **ccn::compiler_version_complete_name**) : the format of this string varies according to the used compiler.

The following additional macros are defined if the corresponding compiler is used : *CCN_CLANG*, *CCN_GPP*, *CCN_ACC*, *CCN_IBMCPP*, *CCN_ICC*, *CCN_MSVC*, *CCN_SUNCC* and *CCN_PGI*.

If you wish to be warned of an incorrect value, you can use `#define CCN_DEPRECATE` before the header inclusion which will apply the C++14 `[[deprecated]]` attribute on the field for which the value is incorrect (for the version numbers).

See [this article](http://nadeausoftware.com/articles/2012/10/c_c_tip_how_detect_compiler_name_and_version_using_compiler_predefined_macros) for more information.

## License

[![CC0](https://licensebuttons.net/p/zero/1.0/88x31.png)](http://creativecommons.org/publicdomain/zero/1.0/)

This library has no license and is free to use.
