
//Values for how many pieces, how many rotations for each piece, and how much memory is needed to store each piece
const int numPieces    = 7;
const int numRotations = 4;
const int numSpaces = 8;

//The piece class
class Piece {
public:
	//Constructor and with taking piece type as param
	Piece();
	Piece(int newPiece);
	//rotates the piece
	void rotatePiece(int rotate);
	//sets the color of the piece to be the red green and blue values
	void color(float r, float b, float g);

	//x and y positin of the piece
	int x;
	int y;

	//color values
	float redVal, blueVal, greenVal;

	//type of piece (0-6) and rotation (0-3)
	int type;
	int rotation;

	//values for the piece rotations
	const int* rotations();
};

//Stores the all 7 pieces and each of their rotations in a 3-dimensional grid

const int gamePiece[numPieces][numRotations][8] =
{
	{
		{0, 0, 1, 0, 0, 1, 1, 1}, //Square and its rotations 
		{0, 0, 1, 0, 0, 1, 1, 1},
		{0, 0, 1, 0, 0, 1, 1, 1},
		{0, 0, 1, 0, 0, 1, 1, 1},
	},
	{
		{0, 0, 0, 1, 0, 2, 0, 3}, //Line piece straight up
		{0, 0, 1, 0, 2, 0, 3, 0}, //sideways
		{0, 0, 0, 1, 0, 2, 0, 3},
		{0, 0, 1, 0, 2, 0, 3, 0},
	},
	{
		{0, 0, 0, 1, 1, 1, 0, 2}, //t-shape
		{1, 0, 0, 1, 1, 1, 2, 1},
		{0, 1, 1, 0, 1, 1, 1, 2}, 
		{0, 0, 1, 0, 2, 0, 1, 1}
	},
	{	{0, 0, 1, 0, 0, 1, 0, 2},// X
		{0, 0, 0, 1, 1, 1, 2, 1},// XXX
		{1, 0, 1, 1, 0, 2, 1, 2},
		{0, 0, 1, 0, 2, 0, 2, 1}
	},
	{	{0, 0, 1, 0, 1, 1, 1, 2},// XXX
		{0, 0, 1, 0, 2, 0, 0, 1},// X
		{0, 0, 0, 1, 0, 2, 1, 2},
		{2, 0, 0, 1, 1, 1, 2, 1}
	},
	{	{0, 0, 0, 1, 1, 1, 1, 2}, //backwards z-shape
		{1, 0, 2, 0, 0, 1, 1, 1},
		{0, 0, 0, 1, 1, 1, 1, 2},
		{1, 0, 2, 0, 0, 1, 1, 1}
	},
	{	{1, 0, 0, 1, 1, 1, 0, 2}, //z-shape
		{0, 0, 1, 0, 1, 1, 2, 1},
		{1, 0, 0, 1, 1, 1, 0, 2},
		{0, 0, 1, 0, 1, 1, 2, 1}
	}
};

