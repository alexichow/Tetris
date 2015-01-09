#include "Piece.h"
Piece::Piece() {
	Piece(0);
}

/*
Creates a new piece and sets the piece type as well as color and sets rotation to first rotation
*/
Piece::Piece(int typ) {
	type = typ;
	switch (type) {
		case 0:		color(1.0, 0.0, 1.0); break;
		case 1:		color(0.5, 0.5, 0.5); break;
		case 2:		color(0.0, 1.0, 1.0); break;
		case 3: 	color(0.0, 1.0, 0.0); break;
		case 4:		color(1.0, 0.0, 0.0); break;
		case 5:		color(1.0, 1.0, 0.0); break;
		case 6:		color(0.0, 0.0, 0.8); break; 
	}
	rotation = 0;
}

/*
Returns the array holding the specific piece's information based on the rotation
*/
const int* Piece::rotations() {
	return gamePiece[type][rotation];
}

//Sets the pieces color to be the ones designated in the constructor
void Piece::color(float r, float g, float b){
	redVal = r;
	greenVal = g;
	blueVal = b;
}

//Increments (or decrements) the game pieces rotation state
void Piece::rotatePiece(int dir){
	if(dir > 0) {
		if (rotation == 3)
			rotation = 0;
		else
			rotation += dir;
	}
	else if (rotation < 0) {
		if (rotation == 0)
			rotation = 3;
		else
			rotation -= dir;
	}
}
