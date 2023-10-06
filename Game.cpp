#include "Game.h"
#include <conio.h>
using std::cout;
using std::cin;
using std::endl;

void Game::Clear()
{   
	//clear screen "\033[2J\033[1;1H";
	// OCTAL ESCAPE CHARACTER \033
	// CLEAR SCREEN [2J //https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797#erase-functions
	// ANOTHER ESCAPE CHARACTER \033
	// https://en.wikipedia.org/wiki/Escape_sequences_in_C
	// https://en.wikipedia.org/wiki/ANSI_escape_code
	//https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797

	//std::cout << "\033[2J\033[1;1H";
}

void Game::Explain()
{
	std::string rightWord = "asbak";
	std::string input;
	Rating rating = Good;

	Clear();
	cout << "Guess away!" << endl;
	cin >> input;	
	for (uint16_t i = 0; i < input.length(); i++)
	{
		if (input[i] == rightWord[i])
			rating = Good;
		else if (input[i] != rightWord[i])
			rating = Wrong;

		switch (rating)
		{
		case Rating::Good:
			cout << "\x1b[1;34m" << input[i];
			break;
		case Rating::Wrong:
			cout << "\x1b[1;31m" << input[i];
			break;
		case Rating::Almost:
			cout << "\x1b[1;33m" << input[i];
			break;
		}
		cout << "\x1b[1;0m";
	}
}

void Game::Tutorial()
{
	std::string input;
	Clear();
	cout << "Want a tutorial? [y/n]" << endl;
	cin >> input;
	cout << input << endl;
	if (input == "y")
		Explain();
	else if (input == "n")
	{
		Clear();
		cout << "Okay lets begin" << endl;
	}
	else
	{
		Clear();
		cout << "Invalid characters!\a" << endl;
		Clear();
		Tutorial();
	}
}

void Game::Intro()
{
	Clear();
	cout << "Welcome to Lingo!\nThis is a dutch gameshow about guessing words. (press any key)" << endl;
	Tutorial();

}
