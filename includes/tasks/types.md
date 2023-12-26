??? info "Constants and literals"

    Note that in Kernighan, **constant** is used as a synonym for **literal**.

**int** can be **short** (usually 16-bit) or **long** (32-bit).
An integer literal ending in **l** or **L** is a long integer.

Floating-point literals by default are of type **long double** or **double** unless suffixed by **f** or **F**, which indicate a **float**.
Long doubles can be explicitly defined by appending **l** or **L** to the literal.

Hexadecimal literals can be defined by prepending **0x** or **0X**, and octals can be defined by prepending **0** alone. These can also be explicitly defined as float or long by appending the appropriate letter.

Finally, literals can be appended with **u** or **U** to make them unsigned.

```c
0L      // long of value 0
0x1f    // float of value 31 in hexadecimal
0xFUL   // unsigned long of value 15
```

Single characters are provided in single quotes and are equivalent to the integer value of their ASCII code.
Some characters can be expressed by escape sequences like **\n**, **\t**, etc.
Characters can also be represented by octal or hexadecimal digits.

```c
'a'
'\n'
'\013', '\xb'   // ASCII vertical tab
'\007', '\x7'   // ASCII bell character
'\0'            // null character, used to terminate char arrays
```

**typedef** facilitates the creation of new data type names, which are conventionally capitalized.
It is similar to #define, except that it is interpreted by the compiler.
These new types are self-documenting and parameterize the program against portability problems (i.e. in the standard library, **size\_t** is a synonym of unsigned int and **ptrdiff\_t** is a synonym of int).
Most standard system data types have names ending in **\_t**, and mostly they are declared in the header file **sys/types.h** (see TLPI p. 64-65 for a selected list of system data types).

```c
// Create a complex struct definition
typedef struct student {
    char name[20];
    float midterm1;
    float midterm2;
    float final_exam;
    float final_grade;
} Student;
```

Types can be cast to other types by preceding the variable with the cast data type in parentheses, for example in this code which convertes a pid\_t (int) to a long:

```c
--8<-- "includes/tlpi/pid.c"
```