/* Entry point for the program */

#include <iostream>
#include <fstream>
#include <string>
#include "WordMaster.h"

using namespace std;

void VerifyWordListExists(string);

WordMaster wordMaster;

int main()
{

	cout << "   ___  _                _                           _  _    _                                _      \n";
	cout << "  / _ \\| |  __ _  _   _ (_) _ __    __ _  __      __(_)| |_ | |__   __      __ ___   _ __  __| | ___ \n";
	cout << " / /_)/| | / _` || | | || || '_ \\  / _` | \\ \\ /\\ / /| || __|| '_ \\  \\ \\ /\\ / // _ \\ | '__|/ _` |/ __|\n";
	cout << "/ ___/ | || (_| || |_| || || | | || (_| |  \\ V  V / | || |_ | | | |  \\ V  V /| (_) || |  | (_| |\\__ \\\n";
	cout << "\\/     |_| \\__,_| \\__, ||_||_| |_| \\__, |   \\_/\\_/  |_| \\__||_| |_|   \\_/\\_/  \\___/ |_|   \\__,_||___/\n";
	cout << "                  |___/            |___/                                                             \n";
	cout << "=====================================================================================================\n\n";

	string wordListName;
	cout << "What is the name of the wordlist you want to read? ";
	cin >> wordListName;
	VerifyWordListExists(wordListName);

	cout << "Opening file ";
	wordMaster.ReadAndStoreWordList(wordListName);
	cout << endl << endl;

	wordMaster.GuessRandomScrambledWord();



	//Ask for wordlist
	//Check if it exists
	//if it exists, call wordMaster.ReadAndStoreWordList(file)
	//otherwise, end



	return 0;
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

