#pragma once
#include "AnimationWindow.h"
#include "Tile.h"


using namespace std;
using namespace TDT4102;

class Tile; // hvorfor måtte jeg gjøre dette for å få kompilert ?????? Samme i Tile.h

// Minesweeper GUI
class MinesweeperWindow : public AnimationWindow 
{
public:
	// storrelsen til hver tile
	static constexpr int cellSize = 30;
	MinesweeperWindow(int x, int y, int width, int height, int mines, const string& title);
	void resoult(std::string resoultString);
	void incrementFlagedTiles() { flagedTiles++; };
	void decrementFlagedTiles() { flagedTiles--; };
private:
	const int width;		// Bredde i antall tiles
	const int height;		// Hoyde i antall tiles
	const int mines;		// Antall miner
	vector<shared_ptr<Tile>> tiles; // Vektor som inneholder alle tiles

	// hoyde og bredde i piksler
	int Height() const { return height * cellSize; } 
	int Width() const { return width * cellSize; }

	// Returnerer en vektor med nabotilene rundt en tile, der hver tile representeres som et punkt
	vector<Point> adjacentPoints(Point xy) const;

	// tell miner basert paa en liste tiles
	int countMines(vector<Point> coords) const;
	int countClosedTiles();

	// Sjekker at et punkt er paa brettet
	bool inRange(Point xy) const { return xy.x >= 0 && xy.x< Width() && xy.y >= 0 && xy.y < Height(); }

	// Returnerer en tile gitt et punkt
	shared_ptr<Tile>& at(Point xy) { return tiles[xy.x / cellSize + (xy.y / cellSize) * width]; }
	const shared_ptr<Tile>& at(Point xy) const { return tiles[xy.x / cellSize + (xy.y / cellSize) * width]; }

    //aapne og flagge rute
	void openTile(Point xy);
	void flagTile(Point xy);

	// callback funksjoner til Tile knappene
	void cb_click();
	
	TDT4102::TextInput resoultWindow;
	TDT4102::TextInput minesLeft;
	int flagedTiles = 0;
	void placeMines();
	TDT4102::Button resetButton;
	void cb_reset();

	int countMinesLeft();
};

int randomWithLimit(int upperLimit);