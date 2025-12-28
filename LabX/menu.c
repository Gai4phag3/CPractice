#include <ncurses.h>

int main() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);

    int input = 0;
    
    while (true) {
        nvprintw(1, 12, "Main Menu");
        for (int i = 2; i < 9; i++) {
            mvprintw(i, 15, "Option: ");
            mvprintw(i, 23, "%d", i-1);
        }
        mvprintw(30, 100, "%i", input);
    }
}