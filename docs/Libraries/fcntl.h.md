# fcntl.h


The [**open()**](#open), [**close()**](#close), [**read()**](#read), and [**write()**](#write) syscalls form the heart of low-level file I/O in Linux.

```c
// Set an opened file's offset, returns new offset position or -1 on error
off_t   lseek   (int fd, off_t offset, int whence);

// Open an existing file or create and open a new file, returns -1 on error
int     open    (const char* path, int flags, ... /* mode_t mode */ );

int     openat  (int fd, const char* path, int oflag, ... /* mode_t mode */ );

// Returns number of bytes read, 0 on EOF, or -1 on error
ssize_t read    (int fd, void* buffer, size_t count);

```

#### open

The *flags* argument is a bit mask that specifies the access mode for the file using one of 18 symbolic constants that are bitwise ORed (**|**) together (TLPI p. 74, APUE p. 62-65).

#### openat

**openat()** is one of a class of functions aded to the latest version of POSIX.1 to allow threads a way to use relative pathnames to open files in directories other than the current working directory as well as a way to avoid **time-of-check-to-time-of-use (TOCTTOU)** errors.
These errors refer to the concern that if a second file-based function call is made that is dependent on an earlier one, the file can change between the two calls leading to an error.

#### lseek

??? info "History"

    The l in lseek was short for long integer, a relic of a period before the introduction of the off\_t type.

**lseek()** adjusts the file offset of the open file. (APUE p. 67).

The interpretation of the *offset* argument depends on the the value of *whence*, but in all cases the value is **added**:

- **SEEK\_SET** (0) from the beginning of the file
- **SEEK\_CUR** (1) from the current offset position
- **SEEK\_END** (2) size of the file (i.e. a positive offset would set the offset position beyond the current EOF)

Note that because _off\_t_ is a signed data type and only positive offsets are accepted for regular files, the maximum filesize for a 64-bit system is actually 2<sup>63</sup>-1.

