# Hello, World!

```c title="Naive"
--8<-- "includes/hw/hw0.c"
```
```c title="Parameterized"
--8<-- "includes/hw/hw1.c"
```
```c title="Multiple arguments"
--8<-- "includes/hw/hw2.c"
```

More header files are needed for the functions necessary to write to a file.

- **fcntl.h** for **open()** and the enums **O\_WRONLY** and **O\_CREAT**
- **unistd.h** for **close()**, **write()**

```c
--8<-- "includes/file/hwf0.c"
```

Note that the **write()** functions needs an argument specifying the length of the string.

A parameterized implementation (also somewhat more graceful) is possible using **fprintf** from the standard library, which also provides **EXIT\_SUCCESS** macro.

```c
--8<-- "includes/file/hwf1.c"
```

Here the default filename is defined in **symbolic constant**, implementing good practice in not burying magic values within the body of the code.
Some error handling is incorporated in case the file is not read (i.e. fopen() returns NULL).

```c hl_lines="4"
// Need to change this into a cat clone
--8<-- "includes/file/hwf2.c"
```

Here, the example is elaborated so that **#define** is used to create a default value for the filename which is overridden by the first argument.

```c hl_lines="10-14"
--8<-- "includes/file/hwf3.c"
```