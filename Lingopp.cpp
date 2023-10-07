#include <iostream>
#include "Game.h"
#include "Lingopp.h"

int main()
{
	//Game::Start();
	std::string answer = "asbak";
	std::string input = "asbbk";
	for (uint16_t i = 0; i < input.length(); i++) {
		if (Game::CheckDuplicates(input, answer, input[i]))
			std::cout << "CHECK'EM" << std::endl;
	}
}
