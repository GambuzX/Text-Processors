/* Entry point for the program */

#include <iostream>
#include <fstream>
#include <string>
#include "WordMaster.h"

using namespace std;

void PlayingWithWordsIntro();
void VerifyWordListExists(string);

WordMaster wordMaster;

int main()
{
	/*PlayingWithWordsIntro();
	string wordListName;
	cout << "What is the name of the wordlist you want to read? ";
	cin >> wordListName;
	VerifyWordListExists(wordListName);

	cout << "Opening file ";
	wordMaster.ReadAndStoreWordList(wordListName);
	cout << endl << endl;*/

	wordMaster.ShowWordsUsingNLetters();
	return 0;
}

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

