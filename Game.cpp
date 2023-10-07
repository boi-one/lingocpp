#include "Game.h"
#include <conio.h>
#include <vector>
using std::cout;
using std::cin;
using std::endl;

static std::string input;
static std::vector<char> correct;
static bool begin = true;
static char turns = 0;

void Game::Clear()
{   
	//clear screen "\033[2J\033[1;1H";
	// OCTAL ESCAPE CHARACTER \033
	// CLEAR SCREEN [2J //https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797#erase-functions
	// ANOTHER ESCAPE CHARACTER \033
	// https://en.wikipedia.org/wiki/Escape_sequences_in_C
	// https://en.wikipedia.org/wiki/ANSI_escape_code
	//https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797

	std::cout << "\033[2J\033[1;1H";
}
bool Game::CheckDuplicates(std::string& inputsource, std::string& answercomparison, const char& character) 
{
	bool result;
	for (uint16_t i = 0; i < inputsource.length(); i++) 
	{
		if (inputsource[i] == answercomparison[i])
		{
			correct.push_back(i);
		}
	}
	for (uint16_t i = 0; i < inputsource.length(); i++)
	{
		if (character == inputsource[i])
			result = false;
	}
	return result;
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
			rating = Good;
		else if (input[i] != answer[i] && Contains(answer, input[i]))
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
	std::string answer = "asbak";
	Rating rating = Good;
	if (begin) 
	{
		begin = false;
		cout << "Okay lets begin, guess away!" << endl;
	}
	cin >> input;
	cout << " turn: " << turns << endl;
	if (!Write(answer, rating) && turns < 4)
	{
		GameLoop();
		++turns;
	}
	else
		End();

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
