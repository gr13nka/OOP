#include "application.h"
#include <curses.h>
#include <ncurses.h>

const char* choices[]
{
	"input 3x3 matrix row by row",
	"show matrix",
	"count matrix determinant",
	"transpose matrix",
	"count matrix rang",
	"exit"
};
int n_choices = sizeof(choices) / sizeof(char *);

int Application::exec()
{
	int key,y,x;
	enum{ key_escape = 27 };

	initscr();
	cbreak();
	keypad(stdscr, 1);
	noecho();
	curs_set(0);
	getmaxyx(stdscr, y, x);

	while ((key = getch()) != key_escape) {
		//print menu here
	
		switch (key) {
        case KEY_UP:
            break;
        case KEY_DOWN:
            break;
        case KEY_RIGHT:
		case ' ':
            break;
		}
	}
	return 0;
}
