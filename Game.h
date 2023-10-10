#pragma once
#include <iostream>

class Game
{
public:
	enum Rating : uint16_t
	{
		Good, Wrong, Almost
	};

	static void Clear();
	static void ClearArray(const std::string& source);
	static bool Contains(const std::string& source, const char& character);
	static bool Write(std::string& answer, Rating& rating);
	static void Start();
	static void Tutorial();
	static void Explain();
	static std::string WordSetup();
	static void GameLoop();
	static void End();
	
	
};

