# unistd.h

```c
// Get current process ID
pid_t   getpid  (void);

// Parse command-line arguments and options
int     getopt  (int argc, char* argv[], const char* optstring)

// Return a new file offset or -1 on error
off_t   lseek   (int fd, off_t offset, int whence);

// Returns number of bytes written, or -1 on error
ssize_t write   (int fd, void* buffer, size_t count);
```

- [**close**](#close) close a file descriptor
- [**exec**](#exec) create a new process
- [**fork**](#fork) create a new process
- **open**
- **read**
- **select**
- **sleep**
- **swab**
- **write**

This library also defines the symbolic constants STDIN\_FILENO, STDOUT\_FILENO, and STDERR\_FILENO.

#### close
:   

    ```c
    close(fd);
    ```

    ```c hl_lines="22-23"
    --8<-- "includes/copy1.c"
    ```

#### exec
:   
    There are seven variations of **exec()**, all of which are used to replace the current process with the contents of another thread.
    
    These variations are distinguished by:
    
    - **l**ist or **v**ector arguments
    - whether or not they create a new **e**nvironment and 
    - whether they require a full pathname or must search on the **p**ath environment variable
    
    For example, **execvpe** specifies an executable on the path, creates a new environment, and passes arguments in a vector.

    ```c hl_lines="11"
    --8<-- "includes/tinyshell.c"
    ```


#### fork
:   
    **fork()** is used to create a new process and is typically associated with [**exec()**](#exec) and [**wait()**](#wait).

    This simple example shows how the value returned by the fork() call differs between the parent and child processes.

    ```c
    --8<-- "includes/fork.c"
    ```

    ```c hl_lines="2 8"
    --8<-- "includes/learning-fork.c"
    ```

#### ftruncate
:   
    ```c hl_lines="23"
    --8<-- "includes/ipc-producer.c"
    ```


#### lseek
:   
    Repositions the file read/write offset, allowing random access to an open file descriptor.
    ```c
    #include <unistd.h>

    lseek(
        fd, 
        offset, // (1)
        whence  // (2)
    );
    ```

    1. Byte offset, positive or negative (usually negative when with respect to end-of file using **SEEK\_END** flag).
    2. Accepts one of several flags that determine where the offset is relative to: **SEEK\_SET** (beginning of file), **SEEK\_CUR** (current position), or **SEEK\_END** (end of file).

