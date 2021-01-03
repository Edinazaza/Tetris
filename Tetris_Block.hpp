#pragma once
#include <array>
#include <utility>

using Tetramino = std::array<short int, 4>;
using CoordinateBlock = std::array<std::pair<short int, short int>, 4>;

Tetramino RandTetramino();

class Block
{
public:
	Block(const Tetramino& coord);
	~Block() = default;
	void Restart(const Tetramino& coordinate);
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void Rotate();
	const CoordinateBlock& GetCoordinate() const;
private:
	CoordinateBlock coordinate;
};