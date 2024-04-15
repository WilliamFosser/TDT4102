#include "Tile.h"
#include <cassert>



// For aa sette Tilelabel i henhold til state
const std::map<Cell, std::string> cellToSymbol{{Cell::closed, ""},
									 			{Cell::open, ""},
									 	  		{Cell::flagged, "|>"}};


Tile::Tile(TDT4102::Point pos, int size) : 
	Button({pos.x, pos.y}, 1.5*size, size, "") {
		setButtonColor(TDT4102::Color::silver);
	}


void Tile::open(int mineCount) {
	if (this->state == Cell::closed) {
		this->state = Cell::open;
		this->setButtonColor(TDT4102::Color::white);
		if (this->isMine) { 
			set_label("X"); 
			set_label_color(TDT4102::Color::red);
			
		}
		else if (mineCount != 0) {
			this->set_label(std::to_string(mineCount));
			this->set_label_color(minesToColor.at(mineCount)); 
		}
	}
}

void Tile::openMine() {
	if (this->isMine) { 
		this->setButtonColor(TDT4102::Color::white);
		set_label("X"); 
		set_label_color(TDT4102::Color::red);
		this->state = Cell::open;
	}
}


void Tile::flag(MinesweeperWindow& mw) {
	if (this->state == Cell::flagged) {
		this->state = Cell::closed;
		mw.decrementFlagedTiles();
		
	}
	else {
		this->state = Cell::flagged;
		set_label_color(TDT4102::Color::black);
		mw.incrementFlagedTiles();
	}
	set_label(cellToSymbol.at(this->state));
}


void Tile::setAdjMines(int n) {
	assert(n >= 1 && n <= 8);
	set_label(std::to_string(n));
	set_label_color(minesToColor.at(n));
}


void Tile::resetTile() {
	this->state = Cell::closed; // her måtte jeg bruke this.... brukt enormt med tid på det..
	setMineState(false);
	set_label(cellToSymbol.at(this->state));
	setButtonColor(TDT4102::Color::silver);
}