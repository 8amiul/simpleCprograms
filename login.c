#include <ncurses.h>
#include <string.h>


#define TITLE "Login Page"

char *USERNAME = "Samiul";
char *PASSWORD = "abc123";

int main()
{
	initscr();

	int max_x, max_y;
	getmaxyx(stdscr, max_y, max_x);

	int centerX = max_x / 2;
	int centerY = max_y / 2;

	char* title = TITLE;
	int titleX = centerX - strlen(title);
	int titleY = centerY;

	char user[100];
	char password[100];
	cbreak();
	nonl();

	mvprintw(titleY, titleX, title);
	mvprintw(titleY+2, titleX-strlen("Username: "), "Username: ");
	mvprintw(titleY+4, titleX-strlen("Password: "), "Password: ");

	mvscanw(titleY+2, titleX, "%s", user);

	noecho();
	mvscanw(titleY+4, titleX, "%s", password);
	echo();

	wclear(stdscr);

	if (strcmp(user, USERNAME) == 0 && strcmp(password, PASSWORD) == 0)
		mvprintw(centerY, centerX-strlen("Welcome, ")-strlen(user), "Welcome, %s\n", user);
	else
		mvprintw(centerY, centerX-strlen("Login failed"), "Login failed\n");

	curs_set(0);

	refresh();
	getch();
	endwin();
	return 0;
}
