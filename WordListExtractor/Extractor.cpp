/* Extractor class functions definitions */

#pragma once
#include <iostream>
#include <fstream>
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


//Given a line, searches for valid headlines and adds them to the wordList
void Extractor::VerifyAndAddValidWords(vector<string> &wordList, string line)
{
	bool hasColon = false; //bool to keep track if the line has a colon or not

	for (int i = 0; i < line.length(); i ++) //for each letter in the line
	{
		if (line.at(i) == ';') hasColon = true;
		if ((int)line.at(i) > 255 || (int) line.at(i) < 0) return; //if not a valid ASCII char, return

		if (!isupper(line.at(i)) && line.at(i) != ';') //if it is not an uppercase letter or a ';'
		{
			if (line.at(i) == ' ' && line.at(i-1) == ';') //if it is a space but has a ';' before, maintain has valid
				continue;
			else
				return;
		}
	}

	//TODO Add words to vector

	cout << line << endl;

	return;
}

//Method to extract the headlines starting with the specified letter from the given dictionary, adding them to the wordList vector
void Extractor::ExtractWordsWithLetter(std::vector<std::string>& wordList, string dictionaryFile, char letter)
{
	//TODO Improve efficiency

	int wordCounter = 0; //TODO Implement word counter to add dots
	string line;

	ifstream dict(dictionaryFile); //opens the dictionary file for reading


	while (!dict.eof() )
	{
		getline(dict, line); //reads a line

		if (line.length() > 0 && line.at(0) == letter)
		{
			VerifyAndAddValidWords(wordList, line);
		}
	}

	dict.close();

	cout << endl;
	return;
}


