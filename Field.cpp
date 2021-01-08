#include <stdexcept>
#include <iostream>
#include "Field.hpp"


Field::Field(const Block& block) : block(block)
{
	for (size_t i = 0; i < 4; ++i) {
		this->block.MoveRight();
	}
	for (auto& i : field) {
		for (auto& j : i) {
			j = false;
		}
	}
}

void Field::NewBlock(const Block& block)
{
	this->block = block;
	for (size_t i = 0; i < 4; ++i) {
		this->block.MoveRight();
	}
	if (CheckerBlock(this->block)) {
		GameOver = true;
	}
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

void Field::BlockRotate()
{
	Block preBlock = block;
	block.Rotate();
	if (CheckerBlock(block)) {
		block = preBlock;
	}
}

void Field::Commit()
{
	field = GetField();
	DellRow();
}

void Field::DellRow()
{
	size_t moveRow = field[0].size() - 1;
	unsigned long int addScore = 0;
	short unsigned int multiple = 0;
	for (int i = field[0].size() - 1; i > 0; --i) {
		unsigned short int countBar = 0;
		for (size_t j = 0; j < field.size(); ++j) {
			if (field[j][i]) {
				++countBar;
			}
			field[j][moveRow] = field[j][i];
		}
		if (countBar < field.size()) {
			--moveRow;
		}
		else {
			addScore += countBar * 10;
			++multiple;
		}
	}
	score += addScore * multiple;
}

const GameField Field::GetField() const
{
	GameField finalField = field;
	for (const auto& coord : block.GetCoordinate()) {
		finalField[coord.first][coord.second] = true;
	}

	return finalField;
}

const bool Field::isGameOver() const
{
	return GameOver;
}

const long unsigned int Field::GetScore() const
{
	return score;
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