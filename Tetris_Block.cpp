#include <array>
#include <ctime>
#include "Tetris_Block.hpp"

CoordTetramino Tetramino::Create() const
{
	srand(time(NULL));
	return coordinate[rand() % 7];
}
