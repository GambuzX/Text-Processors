/* Entry point for the program */

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <time.h>
#include "WordMaster.h"

using namespace std;

void PlayingWithWordsIntro();
void WaitForInput();
void VerifyWordListExists(string);
void DisplayMenu();

WordMaster wordMaster;

int main()
{
	PlayingWithWordsIntro();
	string wordListName;
	cout << "What is the name of the wordlist you want to read? ";
	cin >> wordListName;
	VerifyWordListExists(wordListName);

	cout << "Opening file ";
	wordMaster.ReadAndStoreWordList(wordListName);

	srand(time(NULL));
	bool exitProgram = false;
	do
	{
		DisplayMenu();

		int input;
		cin >> input;
		cout << endl;

		if (cin.fail())
		{
			cout << "Please enter a valid option.\n\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else
		{
			switch (input)
			{
			case 1:
				wordMaster.CheckWordInWordList();
				WaitForInput();
				break;
			case 2:
				wordMaster.GuessRandomScrambledWord();
				WaitForInput();
				break;
			case 3:
				wordMaster.ShowWordsUsingNLetters();
				WaitForInput();
				break;
			case 4:
				wordMaster.AskToBuildValidWordWithNLetters();
				WaitForInput();
				break;
			case 5:
				wordMaster.WildcardMatchingWords();
				WaitForInput();
				break;
			case 9:
				exitProgram = true;
				break;
			default:
				cout << "Please enter a valid option.\n\n";
			}
			//cout << string(50, '\n'); // Clears the screen
		}

	} while (!exitProgram);	

	return 0;
}

//============================================================================================================================================

void PlayingWithWordsIntro()
{
	cout << " _______________________________________________________________________________________________________ \n";
	cout << "|    ___  _                _                           _  _    _                                _       |\n";
	cout << "|   / _ \\| |  __ _  _   _ (_) _ __    __ _  __      __(_)| |_ | |__   __      __ ___   _ __  __| | ___  |\n";
	cout << "|  / /_)/| | / _` || | | || || '_ \\  / _` | \\ \\ /\\ / /| || __|| '_ \\  \\ \\ /\\ / // _ \\ | '__|/ _` |/ __| |\n";
	cout << "| / ___/ | || (_| || |_| || || | | || (_| |  \\ V  V / | || |_ | | | |  \\ V  V /| (_) || |  | (_| |\\__ \\ |\n";
	cout << "| \\/     |_| \\__,_| \\__, ||_||_| |_| \\__, |   \\_/\\_/  |_| \\__||_| |_|   \\_/\\_/  \\___/ |_|   \\__,_||___/ |\n";
	cout << "|                   |___/            |___/                                                              |\n";
	cout << "|_______________________________________________________________________________________________________|\n\n";
}

//============================================================================================================================================

void VerifyWordListExists(string filename)
{
	ifstream wordList(filename);

	if (wordList.fail())
	{
		cout << "\nWord list does not exist!\n\n";
		exit(1);
	}
	return;		
}

//============================================================================================================================================

void DisplayMenu()
{
	cout << " ___________________________ \n";
	cout << "|   /\\/\\   ___ _ __  _      |\n";
	cout << "|  /    \\ / _ \\ '_ \\| | | | |\n";
	cout << "| / /\\/\\ \\  __/ | | | |_| | |\n";
	cout << "| \\/    \\/\\___|_| |_|\\__,_| |\n";
	cout << "|___________________________|\n";
	cout << "|                           |\n";
	cout << "| Select:                   |\n";
	cout << "| 1- Word Finder            |\n";
	cout << "| 2- Random Scramble        |\n";
	cout << "| 3- Word Finder 2.0        |\n";
	cout << "| 4- Word Builder           |\n";
	cout << "| 5- Wildcard Search        |\n";
	cout << "|                           |\n";
	cout << "| 9- Exit                   |\n";
	cout << "|___________________________|\n";
	cout << "| > "                     ;
	
}

//============================================================================================================================================

void WaitForInput()
{
	cout << "\nPress any key to continue... CTRL + Z to exit";
	char input = _getch();
	cout << endl;
	if ((int)input == 26)
		exit(0);
}

//TODO Check case insensitivity
//TODO Check buffer is cleared whenever needed