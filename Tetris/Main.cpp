#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#include <time.h>
#include <glut.h>
#include "Game.h"

const int BLOCKSIZE = 30;
const int VPWIDTH = COLS * BLOCKSIZE;
const int VPHEIGHT = ROWS * BLOCKSIZE;

void BitmapText(char *str, int wcx, int wcy)
{
	glRasterPos2i(wcx, wcy);
	for (int i=0; str[i] != '\0'; i++) {
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str[i]);
	}
}

// random - return a random number in the interval [0,1]
double random()
{ 
	int r = rand();
	return double(r) / RAND_MAX;
}

// Structure to maintain the state of a game
Game game;

// timer - Callback for timers
void timer(int id)
{
	if (game.killed) {	// mode for when the user has been killed
		if (id < 10) {
			game.paused = true;
			glutTimerFunc(200, timer, id+1);
			game.clearGrid();
			glutPostRedisplay();
		}
		else {
			game.killed = false;
			game.restart();
			glutTimerFunc(game.timer, timer, 0);
		}
		glutPostRedisplay();
	} else if (!game.paused) {	// normal operation is when game
		game.update();		// is not paused
		if (game.killed) {
			glutTimerFunc(10, timer, 1);
		} else {
			glutPostRedisplay();
			glutTimerFunc(game.timer, timer, 0);
		}
	}
}

// keyboard - Callback for handling user's keyboard actions.
void keyboard(unsigned char key, int x, int y)
{
	if (key == 'p') {
		game.paused = !game.paused;
		if (!game.paused)
			glutTimerFunc(game.timer, timer, 0);
	} else if (!game.paused && !game.killed && key == ' ') {
		game.update();
	}
	glutPostRedisplay();
}

// keyboard - Callback for handling user's arrow keys.
void special(int key, int x, int y)
{
	if (!game.paused && !game.killed) {
		if (key == GLUT_KEY_LEFT) {
			game.move(-1);
			glutPostRedisplay();
		} else if (key == GLUT_KEY_RIGHT) {
			game.move(1);
			glutPostRedisplay();
		}else if (key == GLUT_KEY_UP) {
			game.rotateShape(1);
			glutPostRedisplay();
		}else if (key == GLUT_KEY_DOWN) {
			game.rotateShape(-1);
			glutPostRedisplay();
		}
	}
}

// display - Callback for displaying the grid and statistics.
void display(void)
{
	glClearColor(0.2f, 0.2f, 0.2f, 0.72);
	glClear(GL_COLOR_BUFFER_BIT);

// Draw grid
	glViewport(0, 0, VPWIDTH, VPHEIGHT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, COLS, ROWS, 0);

	if(!game.paused)
		for (int r=0; r<ROWS; r++) {
			for (int c=0; c<COLS; c++) {
				Square &square = game.grid[r][c];
				if (square.filled){
					glColor3f(square.red, square.green, square.blue);
					glRectd(c+.1, r+.1, c+.9, r+.9);
				}
				else {
					glColor3f(0.2, 0.2, 0.2);
					glRectd(c, r, c+1, r+1);
				}
				
			}
		}

// Write messages on right hand side of screen
	glViewport(VPWIDTH, 0, VPWIDTH+100, VPHEIGHT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 500);

	const int N = 100;
	char msg[N+1];
	glColor3f(1, 1, 0);
	sprintf_s(msg, N, "Player 1 Lines Cleared: %d", game.lines);
	BitmapText(msg, 10, 100);

	sprintf_s(msg, N, "Shapes Encountered: %d", game.shapesProc);
	BitmapText(msg, 10, 150);

//bar
	glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2d(1,0);
		glVertex2d(1, glutGet(GLUT_WINDOW_HEIGHT));
		glEnd();

	glutSwapBuffers();
}

void main(int argc, char *argv[])
{
	srand(time(0));
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);	

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(VPWIDTH + 400, VPHEIGHT);

	glutCreateWindow("chowap Tetris");

	glutDisplayFunc(display);
	glutSpecialFunc(special);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(game.timer, timer, 0);

	glutMainLoop();
}