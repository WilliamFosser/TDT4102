#include "MinesweeperWindow.h"
#include <iostream>
#include <random>

MinesweeperWindow::MinesweeperWindow(int x, int y, int width, int height, int mines, const string &title) : 
	// Initialiser medlemsvariabler, bruker konstruktoren til AnimationWindow-klassen
	AnimationWindow{x, y, (width * cellSize)+5, (height + 6) * cellSize, title},
	width{width}, height{height}, mines{mines},
	resoultWindow(TDT4102::Point{width, (height+2) * cellSize}, 200, 25, ""),
	minesLeft(TDT4102::Point{width+450, (height+2) * cellSize}, 70, 25, std::to_string(mines)), 
	resetButton(TDT4102::Point{width, (height+4) * cellSize}, 150, 25, "Reset game")
{
	add(resoultWindow);
	add(minesLeft);
	
	this->draw_text(TDT4102::Point{width+250, (height+2) * cellSize}, "Uflaggede miner = ", TDT4102::Color::black, 25);
	

	add(resetButton); 
	resetButton.setCallback(std::bind(&MinesweeperWindow::cb_reset, this));

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tiles.emplace_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize});
			tiles.back()->setCallback(std::bind(&MinesweeperWindow::cb_click, this));
			auto temp = tiles.back().get();
			add(*temp); 
		}
	}
	this->placeMines();
}


void MinesweeperWindow::placeMines() {
	for (int i = 0; i < mines; i++) {
		int randomTileIndex = randomWithLimit(tiles.size()-1);
		shared_ptr<Tile> tile = tiles.at(randomTileIndex);
		
		if (!tile->getMineState()) {
			tile->setMineState(true);
		}
	}
}


void MinesweeperWindow::cb_reset() {
	this->flagedTiles = 0;
	this->resoultWindow.setText("");
	this->minesLeft.setText(std::to_string(this->mines));
	for (shared_ptr<Tile> t : tiles) {
		t->resetTile();
	}
	this->placeMines();
}


vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}
			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}
	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	shared_ptr<Tile>& clickedTile = at(xy);
	std::vector<Point> surroundingTiles = adjacentPoints(xy);
	
	if (clickedTile->getState() == Cell::closed) { 
		
		int mineCount = this->countMines(surroundingTiles); // samme som å skrive this->countMines(surroundingTiles);
		clickedTile->open(mineCount); 
		if (mineCount == 0) {
			for (Point p : surroundingTiles) {
				openTile(p);
			}
		}
		if (this->countMinesLeft() == this->mines && this->countClosedTiles() == this->mines) {
			std::string winnerString = "Du vant! Gratulerer";
			this->resoult(winnerString);
			for (shared_ptr<Tile> t : tiles) {
				if (t->getMineState()) {
					t->flag(*this);
				}
			}
		}
	}
	if (clickedTile->getMineState() && clickedTile->getState() != Cell::flagged) {
		std::string looserString = "Du tapte spillet";
			this->resoult(looserString);
			for (shared_ptr<Tile> t : tiles) {
				if (t->getMineState()) {
					t->openMine();
				}
			}
	}
}

void MinesweeperWindow::flagTile(Point xy) {
	shared_ptr<Tile>& clickedTile = at(xy);
	if (clickedTile->getState() != Cell::open) { 
		clickedTile->flag(*this);   // Burde jeg bruke noe annet enn rå pekere?
		int unflagedMines;                
		if ((mines - flagedTiles) > 0) { unflagedMines = mines-flagedTiles; }
		else { unflagedMines = 0; }
		minesLeft.setText(std::to_string(unflagedMines));
	}
}

//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk
void MinesweeperWindow::cb_click() {
	
	Point xy{this->get_mouse_coordinates()};	

	if (!inRange(xy)) {
		return;
	}
	if (this->is_left_mouse_button_down()) {
		openTile(xy);
	}
	else if(this->is_right_mouse_button_down()){
		flagTile(xy);
	}
}

int MinesweeperWindow::countMines(vector<Point> coords) const {
	int tilesWithMine = 0;
	for (Point xy : coords) {
		const shared_ptr<Tile>& tile = at(xy);
		if (tile->getMineState()) { tilesWithMine++; }
	}
	return tilesWithMine;
}

int MinesweeperWindow::countMinesLeft() {
	int minesLeft = 0;
	for (shared_ptr<Tile> t : this->tiles) {
		if (t->getMineState() && t->getState() == Cell::closed) {
			minesLeft++;
		}
	}
	return minesLeft; 
}

void MinesweeperWindow::resoult(std::string resoultString) {
	this->resoultWindow.setText(resoultString);
}

int MinesweeperWindow::countClosedTiles() {
	int closedTileCount = 0;
	for (shared_ptr<Tile> t : this->tiles) {
		if (t->getState() == Cell::closed) {
			closedTileCount++;
		}
	}
	return closedTileCount;
}


int randomWithLimit(int upperLimit) {
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(0, upperLimit);

    int randomNumber = distribution(generator);
    return randomNumber;    
}