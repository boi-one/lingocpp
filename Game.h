#pragma once
#include <iostream>

class Game
{
public:
	static void Write(std::string& output);
	static void Read(std::string& input);
	static void Clear();
	static void Intro();
	static void Tutorial();
	static void Explain();
	static void GameLoop();
	
	static enum Rating : uint16_t
	{
		Good, Wrong, Almost
	};
};

