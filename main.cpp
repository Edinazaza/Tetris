#include <SFML/Graphics.hpp>
#include <windows.h>

#include "WindowGame.hpp"
#include "resource.h"

sf::Texture LoadTextureFromResource(const int ID)
{
	HRSRC rsrcData = FindResource(NULL, MAKEINTRESOURCE(ID), L"PNG");
	if (!rsrcData)
		throw std::runtime_error("Failed to find resource.");

	DWORD rsrcDataSize = SizeofResource(NULL, rsrcData);
	if (rsrcDataSize <= 0)
		throw std::runtime_error("Size of resource is 0.");

	HGLOBAL grsrcData = LoadResource(NULL, rsrcData);
	if (!grsrcData)
		throw std::runtime_error("Failed to load resource.");

	LPVOID firstByte = LockResource(grsrcData);
	if (!firstByte)
		throw std::runtime_error("Failed to lock resource.");

	sf::Texture texture;
	if (!texture.loadFromMemory(firstByte, rsrcDataSize))
		throw std::runtime_error("Failed to load image from memory.");

	return texture;
}

sf::Font LoadFontFromResource(const int ID)
{
	HRSRC rsrcData = FindResource(NULL, MAKEINTRESOURCE(ID), L"FONTS");
	if (!rsrcData)
		throw std::runtime_error("Failed to find resource.");

	DWORD rsrcDataSize = SizeofResource(NULL, rsrcData);
	if (rsrcDataSize <= 0)
		throw std::runtime_error("Size of resource is 0.");

	HGLOBAL grsrcData = LoadResource(NULL, rsrcData);
	if (!grsrcData)
		throw std::runtime_error("Failed to load resource.");

	LPVOID firstByte = LockResource(grsrcData);
	if (!firstByte)
		throw std::runtime_error("Failed to lock resource.");

	sf::Font font;
	if (!font.loadFromMemory(firstByte, rsrcDataSize))
		throw std::runtime_error("Failed to load font from memory.");

	return font;
}

int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	srand(static_cast<unsigned int>(time(0)));

	sf::Texture textureBackground = LoadTextureFromResource(IDB_PNG1);
	sf::Texture textureBlock = LoadTextureFromResource(IDB_PNG2);

	sf::Font font = LoadFontFromResource(IDR_FONTS1);
	WindowGame window(550, 500, "TETRIS");

	window.setTextureBlock(textureBlock);
	window.setBackground(textureBackground);
	window.setSpeed(0.35);
	window.setParametersScoreText(font, 24, 435.0, 217.0);

	window.StartGame();

	return 0;
}