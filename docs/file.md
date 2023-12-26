# File handling

A distinguishing feature of the I/O model on UNIX systems is the concept of universality of I/O, meaning the same system calls are used to perform I/O on files and devices.
File I/O system calls refer to open files using a **file descriptor**, a non-negative integer typically obtained by a call to **open()**.


??? info "File descriptors"

    UNIX shells conventionally associate file descriptors 0, 1, and 2 with STDIN, STDOUT, and STDERR respectively.
    However this is not a feature of the UNIX kernel.

    The symbolic constants **STDIN\_FILENO**, **STDOUT\_FILENO**, and **STDERR\_FILENO** are defined in **unistd.h**:

    ```c
    --8<-- "includes/unistd-fd.c"
    // (1)
    ```

    1. Output:
    ```
    Value of STDIN_FILENO: 0
    Value of STDOUT_FILENO: 1
    Value of STDERR_FILENO: 2
    ```


#### stdio
:   

    ```c
    --8<-- "includes/file/hwf4.c"
    ```

    A variety of techniques and functions exist to implement file handling in C, but **fopen()** appears to be the most common, defined in [**stdio**](../Libraries/stdio#fopen).


    The **FILE** macro is used to create the **file offset** (also called the file pointer), a reference to a particular position in the opened file, and is also defined in stdio.

    fopen() returns a NULL in case of an error, and error handling in C in general appears to rely on handling NULL returns in conditional statements as illustrated below.
    Here, passing **r** as the value for mode indicates that the function will return NULL if the file doesn't exist.

    ```c
    --8<-- "includes/file/file0.c"
    ```

    In fact, **perror()** is provided for printing error messages.
    Here, printf is replaced by perror (even though it won't be reached) and a mode of **w** is provided to fopen(), which will create a file even if one doesn't exist.

    ```c
    --8<-- "includes/file/file1.c"
    ```


    In this example, a file is not only opened but written to in a Hello, World!. 
    The **r+** mode indicates that the file is opened in both read and write mode, but will not be created if it doesn't exist.

    Note the use of **fclose()** which is necessary to release the memory used by the opened file before closing the program.

    ```c hl_lines="15"
    --8<-- "includes/file/hwf4.c"
    ```

    This more sophisticated example shows an implementation of how to read a file with the **fgets()** function, also defined in stdio.h, which gets the file line by line.

    ```c
    --8<-- "includes/file/cat1.c"
    ```

#### fcntl
:   

    The system calls provided in fcntl.h are older, lower-level, and more complex. But they form the basis of the higher-level calls used in other libraries like stdlib.h.

    This example illustrates how **open()** and **close()** (fcntl.h) can be used to open an existing file for reading only while properly handling error in case the file is not accessible.

    ```c hl_lines="13 19"
    --8<-- "includes/file/fcntl01.c"
    ```

    Here, a brief Hello, World! message is written to the file using **write()** (unistd.h). Notice the flag has been changed to **O\_WRONLY**, which will allow the program to write to an existing file but not to create one.

    ```c hl_lines="8 14 20"
    --8<-- "includes/file/fcntl02.c"
    ```

    A bitwise OR operator (**|**) here is provided to combine **O\_CREAT** with O\_WRONLY, which will allow the file to be created if it doesn't exist.

    ```c hl_lines="14"
    --8<-- "includes/file/fcntl03.c"
    ```

    An elaborated example shows how **strlen()** (string.h) can be incorporated into the call to write().

    ```c hl_lines="9 14 22"
    --8<-- "includes/file/fcntl04.c"
    ```

    Writes can be appended to the file by adding the **O\_APPEND** flag.

    ```c hl_lines="14"
    --8<-- "includes/file/fcntl05.c"
    ```

## Tasks

#### cat

A simple cat clone is possible using the functions provided in stdlib.

All arguments to the program are interpreted as filenames.
The fopen call returns a file pointer which is used in the rest of the file handling functions.
**fseek** is used to seek to the end of the file, then **ftell** returns the position of the seek head in number of bytes from the beginning of the file (i.e., the file size).

A buffer precisely sized to be the same number of bytes as the file is allocated from memory and the seek head is returned to the beginning.
**fread** is used to read the file contents into the buffer, and then **fwrite** is used to read from memory to stdout.

Using **fclose** and **free**, the file pointer and buffer are released before terminating the program successfully.


```c
--8<-- "includes/file/cat0.c"
```