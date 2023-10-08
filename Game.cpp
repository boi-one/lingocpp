#include "Game.h"
#include <conio.h>
#include <vector>
using std::cout;
using std::cin;
using std::endl;

static std::string input;
static char correct[4];
static bool begin = true;
static int turns = 0;

void Game::Clear()
{   
	//clear screen "\033[2J\033[1;1H";
	// OCTAL ESCAPE CHARACTER \033
	// CLEAR SCREEN [2J
	// ??? [1;1H
	// https://en.wikipedia.org/wiki/Escape_sequences_in_C
	// https://en.wikipedia.org/wiki/ANSI_escape_code
	//https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797

	std::cout << "\033[2J\033[1;1H";
}

bool Game::Contains(const std::string& source, const char& character)
{
	bool result = false;
	//checks if a string contains a certain character
	for (char c : source)
	{
		if (c == character)
			result = true;
	}
	return result;
}

bool Game::Write(std::string& answer, Rating& rating) 
{
	for (uint16_t i = 0; i < input.length(); i++)
	{
		if (input[i] == answer[i])
			correct[i] = input[i];

		if (input[i] == answer[i])
			rating = Good;
		else if (input[i] != answer[i] && Contains(answer, input[i]) &&  !Contains(correct, input[i]))
			rating = Almost;
		else if (input[i] != answer[i])
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
	cout << endl;
	if (input == answer)
		return true;
	return false;
}

void Game::End() 
{
	cout << "Thanks for playing, want to play again?[y/n]" << endl;
	cin >> input;
	if (input == " y")
		Tutorial();
}

void Game::Tutorial()
{
	Clear();
	cout << "Want a tutorial? [y/n]" << endl;
	cin >> input;
	cout << input << endl;
	if (input == "y")
		Explain();
	else if (input == "n")
	{
		Clear();
		GameLoop();
	}
	else
	{
		Clear();
		cout << "Invalid characters!\a" << endl;
		Clear();
		Tutorial();
	}
}

void Game::Start()
{
	Clear();
	cout << "Welcome to Lingo!\nThis is a dutch gameshow about guessing words. (press any key)" << endl;
	cin >> input;
	Tutorial();

}

void Game::GameLoop() 
{
	cout << turns;
	std::string answer = "asbak";
	Rating rating = Good;
	if (begin) 
	{
		begin = false;
		cout << "Okay lets begin, guess away!" << endl << answer[0] << "####" << endl;
	}
	cin >> input;
	cout << "turn: " << turns << endl;
	if (!Write(answer, rating) && input.length() < 4 && turns < 4)
	{
		++turns;
		cout << turns;
		GameLoop();
	}
	else if(input.length() != answer.length())
	{
		cout << "NOT a 5 letter word!\a (press any key)" << endl;
		cin >> input;
		cout << turns;
		GameLoop();
	}
}

void Game::Explain()
{
	Clear();
	cout << "You'll need to guess a 5 letter word.\nIf a letter is right it will be \x1b[1;34mblue\x1b[1;0m.\nIf the word contains the letter but it's on the wrong place it's \x1b[1;33myellow\x1b[1;0m.\n And if it's wrong it's \x1b[1;31mred\x1b[1;0m of course." << endl;
	cout << "You got it? Let's begin. (press any key)" << endl;
	cin >>  input;
	Clear();
	GameLoop();
}
