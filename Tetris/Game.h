#include "Piece.h"

//Rows and columns
const int ROWS = 20;
const int COLS = 10;

//The actual object that the game grid is constructed of. Each has a filled atribute, an active for designating which is the current piece,
//a toBeDeleted boolean that sets whether it is to be cleared, and color designations.
struct Square {
	bool filled;
	bool isActive;
	bool toBeDeleted;
	float red, green, blue;
};

//the game class where everything takes place
class Game {
public:
	//Constructor
	Game();
	//Game methods
	void clearGrid();
	void nextPiece();
	void restart();
	void move(int dir);
	void rotateShape(int rot);
	bool canRotate(Piece p);
	bool collision(int dir);
	void updatePiece();
	void updateActive();
	void update();
	void updateActiveAfterCollision();
	bool gameOver();
	void checkLine();
	void clearLine();
	
	//the game pieces that are put onto the board
	Piece active;
	Piece next;
	Piece activeCopy;

	//The actual game board
	Square grid[ROWS][COLS];

	//Game data
	int lines;
	int shapesProc;
	bool deleteLines;
	bool killed;	// has the game ended
	bool paused;	// is the game paused
	int timer;		// timer
};

