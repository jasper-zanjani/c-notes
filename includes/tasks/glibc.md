The most commonly used implementation of the standard C library on Linux is the GNU C library or **glibc** (alternatives with smaller memory requirements for use in embedded devices include uClibc and diet libc).
The glibc shared library file can be found at **/lib64/libc.so.6** or **/usr/lib/libc.so.6**, and running it as an executable from the command-line will output the glibc version.

```sh
/lib64/libc.so.6 # (1)
```

1. 
``` title="Output" hl_lines="1"
GNU C Library (GNU libc) stable release version 2.38.
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.
There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.
Compiled by GNU CC version 13.2.1 20230801.
libc ABIs: UNIQUE IFUNC ABSOLUTE
Minimum supported kernel: 4.4.0
For bug reporting instructions, please see:
<https://bugs.archlinux.org/>.
```

**ldd** can be used to find the location of the glibc shared library on a running distribution.

```sh
ldd /usr/bin/bash # (1)
```

1. 
``` title="Output" hl_lines="3"
	linux-vdso.so.1 (0x00007fff82feb000)
	libreadline.so.8 => /usr/lib/libreadline.so.8 (0x00007f2151db3000)
	libc.so.6 => /usr/lib/libc.so.6 (0x00007f2151a00000)
	libncursesw.so.6 => /usr/lib/libncursesw.so.6 (0x00007f2151d3c000)
	/lib64/ld-linux-x86-64.so.2 => /usr/lib64/ld-linux-x86-64.so.2 (0x00007f2151f4e000)
```

glibc defines the function **gnu\_get\_libc\_version()** that returns the library version as a string.
Two symbolic constants that encode the version of the library as integers are also defined: **\_\_GLIBC\_\_** and **\_\_GLIBC\_MINOR\_\_**.

```c
--8<-- "includes/tlpi/glibc-version.c"
```