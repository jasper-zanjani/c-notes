# Compiling a GTK program written in C
gcc -Wall -g $(pkg-config --cflags gtk+-3.0) $(pkg-config --libs gtk+-3.0)