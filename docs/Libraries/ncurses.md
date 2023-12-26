# ncurses

```sh
--8<-- "includes/gcc/gcc-ncurses.sh"
```

```c title="Hello, World!"
--8<-- "includes/Tasks/ncurses01.c"
```

- **initscr()** initializes the terminal in curses mode and needs to be called first before doing
any screen manipulation. The present window is called **stdscr**.
- **printw()** prints to coordinates (0,0) by default.
- **refresh()** is necessary because printw() actually prints to an imaginary window which does not
become visible until refresh() is called. Omitting refresh() is a typical mistake committed by novices.
- **endwin()** frees memory taken by the curses subsystem and returns the terminal to normal mode. Failing to call this will cause problems with the terminal.