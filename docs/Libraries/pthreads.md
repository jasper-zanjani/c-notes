# pthread.h

**pthread** provides an API for multithreaded programming in C.
New threads are spawned explicitly using [**pthread\_create**](#pthread_create) passing the name of a function which the thread will run.

Notably, this function must have precisely the following signature:

```c
void* func(void *arg)
```

```sh title="Compile a program with pthread"
--8<-- "includes/gcc/gcc-pthread.sh"
```