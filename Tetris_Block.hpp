#pragma once

using CoordTetramino = std::array<short int, 4>;

class Tetramino
{
public:
	Tetramino() = default;
	~Tetramino() = default;
	CoordTetramino Create() const;
private:
	const std::array<CoordTetramino, 7> coordinate =
	{ {
		{1, 3, 5, 7},
		{2, 3, 4, 5},
		{2, 3, 5, 7},
		{2, 4, 5, 7},
		{3, 5, 4, 6},
		{3, 5, 4, 7},
		{3, 5, 7, 6}
	} };
};