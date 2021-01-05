#include "Field.hpp"

Field::Field(const Block& block) : block(block)
{
	for (auto& i : field) {
		for (auto& j : i) {
			j = false;
		}
	}
}

void Field::BlockMoveDown()
{
	Block preBlock = block;
	block.MoveDown();
	
	for (const auto& i : block.GetCoordinate()) {
		if (i.second >= field[0].size()) {
			block = preBlock;
		}
	}
}

void Field::BlockMoveLeft()
{
	Block preBlock = block;
	block.MoveLeft();

	for (const auto& i : block.GetCoordinate()) {
		if (i.first < 0) {
			block = preBlock;
		}
	}
}

void Field::BlockMoveRight()
{
	Block preBlock = block;
	block.MoveRight();

	for (const auto& i : block.GetCoordinate()) {
		if (i.first >= field.size()) {
			block = preBlock;
		}
	}
}

const GameField Field::GetField()
{
	GameField finalField = field;
	for (const auto& coord : block.GetCoordinate()) {
		finalField[coord.first][coord.second] = true;
	}

	return finalField;
}
