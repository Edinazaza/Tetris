#include <stdexcept>
#include "Field.hpp"


Field::Field(const Block& block) : block(block)
{
	for (auto& i : field) {
		for (auto& j : i) {
			j = false;
		}
	}
}

void Field::NewBlock(const Block& block)
{
	this->block = block;
}

void Field::BlockMoveDown()
{
	Block preBlock = block;
	block.MoveDown();
	
	for (const auto& i : block.GetCoordinate()) {
		if (i.second >= field[0].size() || CheckerBlock(block)) {
			block = preBlock;
			Commit();
			NewBlock(RandTetramino());
		}
	}
}

void Field::BlockMoveLeft()
{
	Block preBlock = block;
	block.MoveLeft();

	for (const auto& i : block.GetCoordinate()) {
		if (i.first < 0 || CheckerBlock(block)) {
			block = preBlock;
		}
	}
}

void Field::BlockMoveRight()
{
	Block preBlock = block;
	block.MoveRight();

	for (const auto& i : block.GetCoordinate()) {
		if (i.first >= field.size() || CheckerBlock(block)) {
			block = preBlock;
		}
	}
}

void Field::Commit()
{
	field = GetField();
}

const GameField Field::GetField()
{
	GameField finalField = field;
	for (const auto& coord : block.GetCoordinate()) {
		finalField[coord.first][coord.second] = true;
	}

	return finalField;
}

bool Field::CheckerBlock(const Block& block) const
{
	try
	{
		for (const auto& coord : block.GetCoordinate()) {
			if (field.at(coord.first).at(coord.second)) {
				return true;
			}
		}
		return false;
	}
	catch (const std::out_of_range&)
	{
		return true;
	}
}
