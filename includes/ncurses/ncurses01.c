#include <ncurses.h>

int main(int argc, char const *argv[])
{
    initscr();
    printw("Hello, World!");
    refresh();
    getch();
    endwin();

    return 0;
} // From https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/helloworld.html
