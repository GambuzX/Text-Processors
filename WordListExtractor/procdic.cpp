/* Entry point for the program */

#pragma once
#include <iostream>
#include <fstream>
#include "Extractor.h"

using namespace std;

Extractor extractor;
string AskDictionaryFile();
string AskWordListFile();

int main()
{
	cout << "EXTRACTION OF WORD LIST FROM DICTIONARY\n";
	cout << "=======================================\n";

	string dictionary = AskDictionaryFile();
	string wordListFile = AskWordListFile();
	cout << endl;

	cout << "Extracting simple words from file " << dictionary << ",\n";
	cout << "beginning with letter ...\n";

	extractor.ProcessDictionary(dictionary);

	cout << endl;
	cout << "Number of simple words = " << extractor.GetSimpleWords() << endl << endl;

	cout << "Sorting words ...\n\n";
	extractor.SortWordList();

	cout << "Removing duplicate words ... \n\n";
	//extractor.RemoveDuplicateWords();

	cout << "Number of non-duplicate simple words = " << extractor.GetNonDuplicateSimpleWords() << endl << endl;

	cout << "Saving words into file " << wordListFile << " ... \n\n";
	extractor.SaveWordList(wordListFile);

	cout << "End of processing.\n";
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

	