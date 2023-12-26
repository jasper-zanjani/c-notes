```sh
--8<-- "includes/gcc/gcc-cstd.sh"

--8<-- "includes/gcc/gcc-wall.sh"

--8<-- "includes/gcc/gcc-ncurses.sh"

--8<-- "includes/gcc/gcc-pthread.sh"
```

**pkg-config** returns directory names, which **gcc** uses to ensure all header files are available.

Here, pkg-config appends options to the command-line used by the linker including library directory path extensions and a list of libraries needed for linking to the executable.

```sh
--8<-- "includes/gcc/gcc-gtk.sh"
```


```sh title="Various options"
# Output extra information for use by a debugger with -g
gcc -g

# Skip linking entirely with -c
gcc -c
```