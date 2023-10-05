#include "Game.h"
#include "windows.h"
using std::cout;
using std::cin;
using std::endl;

void Game::Clear()
{
	std::cout << "\033[2J\033[1;1H";
}

void Game::Explain()
{
	std::string input;

	Clear();
	cout << "Typ een woord" << endl;
	cin >> input;

	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	

}

void Game::Tutorial()
{
	std::string input;
	Clear();
	cout << "Want a tutorial? [Y/N]";
	cin >> input;
	cout << input << endl;
	if (input == "Y")
		Explain();
	else if (input == "N")
		cout << "Okay lets begin" << endl;
	else
	{
		Clear();
		cout << "Invalid characters!" << endl;
	}
}

void Game::Intro()
{
	Clear();
	cout << "Welcome to Lingo!\nThis is a dutch gameshow about guessing words." << endl;
	Tutorial();

}
