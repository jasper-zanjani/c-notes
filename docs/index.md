*[TLPI]: The Linux Programming Interface
*[APUE]: Advanced Programming in the Unix Environment, 3rd ed.

# Overview

C is a programming language closely associated with UNIX and Linux.
C was inspired by the B language, which was written by Ken Thompson in 1970 for the first UNIX system on the PDP-7.


??? info "C standards"

    For many years, the definition of C was the reference manual in the first edition of *The C Programming Language* by Brian Kernighan and Dennis Ritchie (Kernighan).

    In 1983, ANSI established a committee to provide a modern, comprehensive definition of C which was completed late in 1988, referred to as ANSI C or standard C.
    ANSI C incorporates small changes to the language, incorporating enumerations, single-precision floating-point computations, and elaborating the preprocessor.
    Additionally, a library was defined to accompany C ("the standard library") to incorporate higher-level functions to facilitate file access, etc.

    The C standard is now maintained and developed by the ISO/IEC international standardization working group for the C programming language, known as WG14 (short for ISO/IEC JTC1/SC22/WG14).
    In 1999 the ISO C standard was updated and approved (ISO/IEC 9899:1999, referred as **C99**) to improve support for applications that perform numerical processing.
    The changes don't affect POSIX interfaces relevant to system programming, except for the addition of the **restrict** keyword which tells the compiler which pointer references can be optimized by indicating that the object to which the pointer refers is accessed in the functino only via that pointer.
    Technical corrigenda have been published in 2001, 2004, and 2007.
    Successively newer versions of C have been referred to as C11, C18, and C22.

    ```c title="Inspect compiler's version of C"
    --8<-- "includes/cstd.c"
    ```

    A specific C version can be specified to the compiler with **-std**

    ```sh
    --8<-- "includes/gcc/gcc-cstd.sh"
    ```

??? info "POSIX.1"

    *[IEEE]: Institute of Electrical and electronics engineers

    **POSIX** (Portable Operating system Interface) is a family of standards initially developed by the IEEE.
    The 1988 version of POSIX, IEEE Standard 1003.1-1988, saw minor revisions and was submitted to ISO as ISO/IEC 9945-1:1990 (also IEEE 1003.1-1990), commonly referred to as **POSIX.1**.

    In 1996 the [**pthreads**](Libraries/pthreads) interfaces for multithreaded programming were added to the standard, which was published as ISO/IEC 9945-1:1996.
    Additional interfaces were added in 1999, 2000, 2001, 2004, and 2008 which was approved by ISO as ISO/IEC 9945:2009. 

    The POSIX.1 standard includes the 24 ISO C headers as well as others.

```c title="main() signature"
int main(int argc, char** argv);
```

**main()** is the canonical [entrypoint](https://opensource.com/article/19/5/how-write-good-c-main-function) for C and C++ programs.
It returns a signed integer and takes two arguments.

- **argc** argument count
- **argv** argument vector

**Header files** are included by using the **#include** C preprocessor directive.
Headers provided in angle brackets are to be found in the system-defined header path (**/usr/include**).

```c
#include <stdio.h>
```

??? info "Installing header files"

    Compiling even simple programs will fail if they include dependencies on header files that are not present.

    ```sh
    # Ubuntu
    apt install -y build-essential

    # Note that this not yet possible on WSL2 without using a custom compiled kernel.
    apt install -y linux-header-$(uname -r)
    ```

#### Text input

A trivial example showing how a character stream can be accepted and immediately echoed.

```c
--8<-- "includes/Kernighan/05.c"
```

A similarly trivial example shows how a stream of characters can be counted.
Note that the enter press is part of the character stream and cannot be omitted, even if you hit ++Ctrl+D++ to insert EOF.

```c
--8<-- "includes/Kernighan/06.c"
```

A stranger-looking but more interesting implementation is possible by declaring the index variable of the for loop outside of the loop and using it to keep track of the character stream.

```c
--8<-- "includes/Kernighan/07.c"
```

Here, lines of input are counted instead of characters.

```c
--8<-- "includes/Kernighan/08.c"
```

Here, a more elaborate example stores the longest line of all the lines typed in.
Note the example includes a **symbolic constant** and multiple function definitions, including function declarations at the top.

```c
--8<-- "includes/Kernighan/12.c"
```

#### Types

--8<-- "includes/tasks/types.md"

#### glibc

--8<-- "includes/tasks/glibc.md"

#### Error handling

--8<-- "includes/tasks/error.md"

#### Data organization

Use structs to organize data.

```c
```

#### Command-line parsing

The functions **atoi()**, **atol()**, and **atoll()** (stdlib.h) allow conversion of strings passed in from the command-line to integers, longs, and long longs.