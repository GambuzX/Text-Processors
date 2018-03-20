/* Extractor class functions definitions */

#pragma once
#include <iostream>
#include "Extractor.h"

using namespace std;

//Extracts all the headlines from the dictionary, returning a vector with the resulting strings
std::vector<std::string> Extractor::ProcessDictionary(string dictionary)
{
	vector<string> WordList;

	for (char letter = 'A'; letter < 'Z'; letter++) //for each letter from A to Z
	{
		cout << letter << endl;
		ExtractWordsWithLetter(WordList, dictionary, letter);
		//Missing the dots count -> One dot per 100 headlines
	}



	return WordList;
}

//Sorts the wordList vector
void Extractor::SortWordList(vector<string>& WordList)
{
	return;
}

//Removes duplicate words from the vector (assuming it is sorted)
void Extractor::RemoveDuplicateWords(vector<string>& WordList)
{
	return;
}

//Saves the word list vector to a file
void Extractor::SaveWordList(vector<string>& WordList, string wordListFile)
{
	return;
}

//Getter for the number of simple words
int Extractor::GetSimpleWords() const {	return NumberOfSimpleWords;}

//Getter for the number of non duplicate simple words
int Extractor::GetNonDuplicateSimpleWords() const {	return NumberOfNonDuplicateSimpleWords;}

//Method to extract the headlines starting with the specified letter from the given dictionary, adding them to the wordList vector
void Extractor::ExtractWordsWithLetter(std::vector<std::string>& wordList, string dictionaryFile, char letter)
{
	return;
}
