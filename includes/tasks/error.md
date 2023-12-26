When system calls fail, they typically set the global integer variable **errno** to a nonzero value.
This value is not reset to zero by subsequent successful calls.

Several functions exist in the standard library to provide error messaging capability:

- **perror()** (stdlib.h) print an error message
- **strerror()** (string.h) interprets the error number passed in as its argument
- **errno** (errno.h)

```c
--8<-- "includes/tlpi/error.c"
```

Library functions report errors in one of several ways:

- Return -1 with errno indicating the specific error (e.g. open())
- Return NULL with errno indicating the specific error (e.g. fopen())
- Other library functions don't use errno at all