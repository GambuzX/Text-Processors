/* Entry point for the program */

#pragma once
#include <iostream>
#include "Extractor.h"
#include "procdic.h"

using namespace std;

Extractor extractor;
string AskDictionaryFile();
string AskWordListFile();

int main()
{
	cout << "EXTRACTION OF WORD LIST FROM DICTIONARY\n";
	cout << "=======================================\n";

	string dictionary = AskDictionaryFile();
	string wordList = AskWordListFile();
	cout << endl;

	cout << "Extracting simple words from file " << dictionary << ",\n";
	cout << "beginning with letter ...\n";

	cout << endl;
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

	