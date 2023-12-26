# stdlib.h





#### exit
:   
    **exit()** ends the program, returning the integer provided in parentheses as the exit status of the process.


#### getpid
:   
    ```c
    pid_t getpid(pidt);
    ```

    ```c
    #include <unistd.h>

    getpid();
    ```

    ```c hl_lines="15"
    --8<-- "includes/exit-status.c"
    ```

#### getrandom
:   
    [Introduced](https://lwn.net/SubscriberLink/884875/58f88e6eb7913686/) in Linux 3.17 to allow userspace applications to request random numbers in the case of no access to random devices (i.e. containers).
    By default it will use the [/dev/urandom]() pool, which normally does not block. 
    A flag can be provided to use the /dev/random pool instead.


#### malloc
:   


#### memcpy
:   
    Used for copying stack-allocated data.

    ```c
    memcpy(
        dst,  //
        size, //
        flags //
    );
    ```

#### mmap
:   
    Maps a file into memory, allowing it to be accessed as if were an array.
    ```c
    mmap(
        addr,   // Commonly set to **NULL**, allowing the kernel to choose the address.
        length, // Length of the mapping
        prot,   // Typically a combination of **PROT\_READ** and/or **PROT\_WRITE**
        flags,  // Determines whether the mapped region is shared with other processes: **MAP\_SHARED** or **MAP\_PRIVATE**
        fd,     // File descriptor from [**open()**](#open)
        offset  // Multiple of page size, and often set to 0 to map the entire file
    );  // Return value is the address to which the file has been mapped (similar to [**malloc()**](#malloc))
    ```

    === "IPC producer"

        ```c hl_lines="26"
        --8<-- "includes/ipc-producer.c"
        ```

    === "IPC consumer"

        ```c hl_lines="16"
        --8<-- "includes/ipc-consumer.c"
        ```

#### msync
:   


#### open
:   
    A call to **open()** creates a new open file descriptor

    ```c
    fd = open("foo", O_RDWR   | // (1) 
                    O_TRUNC  | // (2) 
                    O_APPEND   // (3)
    );
    ```

    1. **Access mode** flag specifying reading and writing: **O\_RDWR**, **O\_RDONLY**, or **O\_WRONLY**.
    2. **Open-time** flag required for writing. However, calling [**ftruncate()**](#ftruncate) is recommended over use of this flag in [**open()**](#open), which is retained for backwards compatibility.
    3. **Operating mode** flag that makes all write operations write data at the end of the file, extending it, regardless of the current file position.

    ```c
    --8<-- "includes/copy1.c"
    ```

#### read
:   
    Like [**write()**](#write), calls to read() require require a pointer to the buffer as well as the count of bytes which must not exceed the buffer's actual size.
    read() will return the number of bytes actually read and 0 on end-of-file.
    ```c
    read(fd, buffer, count);
    ```

    ```c hl_lines="19"
    --8<-- "includes/copy1.c"
    ```

#### rand
:   

    ```c
    int rand(RAND_MAX);
    ```

    Generate a pseudo-random integer from 0 to **RAND_MAX**.
    A seed must first be provided to **srand**.

    ```c hl_lines="9"
    --8<-- "includes/HenrikM/random.c"
    ```

#### srand
:   

    Set a seed for a new sequence of pseud-orandom integers to be returned by **rand**.

    ```c hl_lines="7" title="Coin flip"
    --8<-- "includes/HenrikM/random.c"
    ```


#### shm_open
:   

    ```c hl_lines="20" title="Coin flip"
    --8<-- "includes/ipc-producer.c"
    ```

#### shm_unlink
:   
    Removes the shared-memory segment after the consumer has accessed it.
    ```c hl_lines="20"
    --8<-- "includes/ipc-consumer.c"
    ```

#### wait
:   
    wait() blocks until one of the process's children terminates and returns an integer.

    ```c
    int status;
    wait(&status); // (1)
    ```

    1. Passing 0 or NULL will discard the child's exit status.

    The exit status is separted into upper and lower bytes.
    If the process was killed by a signal the top bit of the lower byte is called the "Core Dumped" flag.
    There are several macros used to analyze the exit status.

    - **WIFEXITED** true if child exited normally
    - **WEXITSTATUS**
    - **WIFSIGNALED** true if child terminated by signal
    - **WTERMSIG** signal number

    ```c
    --8<-- "includes/exit-status.c"
    ```

    ```c hl_lines="16"
    --8<-- "includes/learning-fork.c"
    ```

#### write
:   
    Like [**read()**](#read), write() takes an integer file descriptor, a pointer to the buffer, as well as a count of bytes which must not exceed the buffer's size.

    ```c hl_lines="20"
    write(fd, buffer, count);
    ```

    ```c
    --8<-- "includes/copy1.c"
    ```
