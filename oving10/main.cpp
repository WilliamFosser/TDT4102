#include "MinesweeperWindow.h"
#include <iostream>


int main()
{
	constexpr int width = 20;
	constexpr int height = 20;
	constexpr int mines = 40;

	Point startPoint{ 200, 300 };
	MinesweeperWindow mw{startPoint.x, startPoint.y, width, height, mines, "Minesweeper" };
	mw.wait_for_close();

	return 0;
}
 