# stdio.h

```c
// Open a file
FILE*   fopen(const char *file_name, const char *access_mode);

// Print a system error
void    perror(const char *msg);

// Print to STDOUT
int     printf(const char* restrict format, ...);
```

#### printf

The placeholders within the string that are replaced by variable values are called **specifiers**.

```c
printf("%-20s", var); // Left-justified string at a width of 20 characters
```