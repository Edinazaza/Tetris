#include <array>
#include <utility>
#include <ctime>
#include "Tetris_Block.hpp"


Tetramino RandTetramino()
{
	static std::array<Tetramino, 7> figureForTetris
	{ {
		{1, 3, 5, 7},
		{2, 3, 4, 5},
		{2, 3, 5, 7},
		{2, 4, 5, 7},
		{3, 5, 4, 6},
		{3, 5, 4, 7},
		{3, 5, 7, 6}
	} };

	return figureForTetris[rand() % 7];
}

Block::Block(const Tetramino& coordinate)
{
	for (size_t i = 0; i < 4; ++i) {
		this->coordinate[i] = std::make_pair(coordinate[i] % 2, coordinate[i] / 2);
	}
}

void Block::Restart(const Tetramino& coordinate)
{
	for (size_t i = 0; i < 4; ++i) {
		this->coordinate[i] = std::make_pair(coordinate[i] % 2, coordinate[i] / 2);
	}
}

void Block::MoveDown()
{
	for (auto& i : coordinate) {
		++i.second;
	}
}

void Block::MoveLeft()
{
	for (auto& i : coordinate) {
		--i.first;
	}
}

void Block::MoveRight()
{
	for (auto& i : coordinate) {
		++i.first;
	}
}

void Block::Rotate()
{
	// X = x0 + (x − x0) * cos⁡(a) −(y − y0) * sin⁡(a)
	// Y = y0 + (y − y0) * cos⁡(a) + (x − x0 ) * sin⁡(a)
	// a = 90
	// X = x0 - (y - y0)
	// Y = y0 + (x - x0)
	// x0, y0 - coordinate point rotate
	std::pair<short int, short int> rotatePoint = coordinate[1];
	for (auto& i : coordinate) {
		short int dX = i.second - rotatePoint.second;
		short int dY = i.first - rotatePoint.first;
		i.first = rotatePoint.first - dX;
		i.second = rotatePoint.second + dY;
	}
}

const CoordinateBlock& Block::GetCoordinate() const
{
	return coordinate;
}
