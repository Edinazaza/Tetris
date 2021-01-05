#pragma once
#include "Tetris_Block.hpp"

using GameField = std::array<std::array<bool, 22>, 10>;

class Field
{
public:
	Field(const Block& block);
	~Field() = default;
	void NewBlock(const Block& block);

	void BlockMoveDown();
	void BlockMoveLeft();
	void BlockMoveRight();
	void BlockRotate();

	const GameField GetField();

private:
	Block block;
	GameField field;

	void Commit();
	bool CheckerBlock(const Block& block) const;
};