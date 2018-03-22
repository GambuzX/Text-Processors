/* Entry point for the program */

#pragma once
#include <iostream>
#include <fstream>
#include "Extractor.h"

using namespace std;

Extractor extractor;
string AskDictionaryFile();
string AskWordListFile();
void VerifyInputFileExists(string);
void CheckIfOutputFileExists(string);

int main()
{
	cout << "EXTRACTION OF WORD LIST FROM DICTIONARY\n";
	cout << "=======================================\n";

	string dictionary = AskDictionaryFile();
	VerifyInputFileExists(dictionary);

	string wordListFile = AskWordListFile();
	CheckIfOutputFileExists(wordListFile);
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

//===================================================================================================================================================================================================
//Asks for the dictionary file name

string AskDictionaryFile()
{
	string dictionary;
	cout << "Dictionary file ? ";
	cin >> dictionary;

	return dictionary;
}

//===================================================================================================================================================================================================
//Asks what the word list file name should be

string AskWordListFile()
{
	string wordList;
	cout << "Word list file ? ";
	cin >> wordList;

	return wordList;
}

//===================================================================================================================================================================================================.
//Verifies the dictionary file exists

void VerifyInputFileExists(string name)
{
	ifstream file(name);
	if (file.fail())
	{
		cerr << "File does not exist. Exiting process...\n";
		exit(1);
	}
	file.close();
	return;
}

//===================================================================================================================================================================================================
//Checks if the specified output file name already is in use. If it is, asks if the user wants to overwrite it

void CheckIfOutputFileExists(string name)
{
	ifstream file(name);
	if (file.is_open())
	{
		char answer;
		cout << "A file with that name already exists. Do you wish to overwrite it? ";
		cin >> answer;

		if (toupper(answer) == 'N')
			exit(1);
	}
	return;
}

	