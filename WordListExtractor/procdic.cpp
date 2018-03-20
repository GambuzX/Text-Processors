/* Entry point for the program */

#pragma once
#include <iostream>
#include "Extractor.h"
#include "procdic.h"

using namespace std;

string AskDictionaryFile();
string AskWordListFile();

int main()
{
	cout << "EXTRACTION OF WORD LIST FROM DICTIONARY\n";
	cout << "=======================================\n";

	string dictionary = AskDictionaryFile();
	string wordList = AskWordListFile();

	cout << dictionary << endl << wordList << endl;
	return 0;
}

//Add functions for UI stuff

string AskDictionaryFile()
{
	string dictionary;
	cout << "Dictionary file ? ";
	cin >> dictionary;

	return dictionary;
}

string AskWordListFile()
{
	string wordList;
	cout << "Word list file ? ";
	cin >> wordList;

	return wordList;
}

	