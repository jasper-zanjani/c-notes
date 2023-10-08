```sh
# Compile main.c, displaying all warnings
gcc main.c -Wall -o hello
```


**pkg-config** returns directory names, which **gcc** uses to ensure all header files are available.

Here, pkg-config appends options to the command-line used by the linker including library directory path extensions and a list of libraries needed for linking to the executable.

```sh
# Compiling a GTK program written in C
gcc -Wall -g helloworld.c -o helloworld $(pkg-config --cflags gtk+-3.0) $(pkg-config --libs gtk+-3.0)
```

