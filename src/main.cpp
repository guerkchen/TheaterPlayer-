#include <cstdio>
#include <curses.h>
#include <ncurses.h>
#include <stdlib.h>

void quit(void)
{
  endwin();
}

int main(int argc, char const *argv[]) {
  int x, y;

  initscr();
  atexit(quit);
  start_color();
  noecho();

  curs_set(0);

  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  bkgd(COLOR_PAIR(1));

  mvprintw(3, 5, "LINES: %d", LINES);
  mvprintw(4, 5, "COLS:  %d", COLS);

  color_set(1, nullptr);

  getyx(stdscr, y, x);
  mvprintw(5, 5, "Momentane Cursorposition:  [%d, %d]", y, x);

  getbegyx(stdscr, y, x);
  mvprintw(6, 5, "Koordinatenursprung:       [%d, %d]", y, x);

  getmaxyx(stdscr, y, x);
  mvprintw(7, 5, "Fenstergroesse:            [%d, %d]", y, x);

  mvaddch(y / 2, x / 2, 'a');

  mvaddstr(11, 2, "Taste drücken -> Ende");
  refresh();

  getch();
  // getch();

  endwin();
  return 0;
}
