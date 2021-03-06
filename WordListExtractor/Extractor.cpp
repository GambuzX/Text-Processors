/* Extractor class functions definitions */

#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Extractor.h"


using namespace std;

//Extracts all the headlines from the dictionary, adding them to the class wordList
void Extractor::ProcessDictionary(string dictionary)
{
	string line;
	ifstream dict(dictionary);

	while (getline(dict, line))
	{
		if (line.length() > 0 && (int) line.at(0) >= 0  && (int) line.at(0) <= 255 && !islower(line.at(0))) // filtering obviously uninteresting lines
		{
			VerifyAndAddValidWords(line);
		}
	}

	dict.close();
	return;
}

//===================================================================================================================================================================================================
//Sorts the wordList vector using bubblesort method

void Extractor::SortWordList()
{
	sort(wordList.begin(), wordList.end());
	return;
}

//===================================================================================================================================================================================================
//Swaps duplicate words from the vector (assuming it is sorted) for "x"

void Extractor::MarkDuplicateWordsAsInvalid()
{
	unsigned length = wordList.size();
	NumberOfNonDuplicateSimpleWords = NumberOfSimpleWords;

	for (int i = 0; i < length - 1; i++)
	{
		if (wordList.at(i) == wordList.at(i + 1))
		{
			wordList.at(i) = "x"; //swap duplicates with "x"
			NumberOfNonDuplicateSimpleWords--;
		}
	}
	return;
}

//===================================================================================================================================================================================================
//Saves the valid words (different from "x") from the word list vector to a file

void Extractor::SaveValidWords(string wordListFile)
{
	ofstream OutputFile(wordListFile);

	unsigned length = wordList.size();
	for (int i = 0; i < length; i++)
	{
		if (wordList.at(i) != "x") //duplicate elements were changed to "x"
		{
			OutputFile << wordList.at(i); //add all the extracted headlines to a file
			if (i < length - 1) OutputFile << '\n'; //add newlines (except on the last word)
		}
	}

	OutputFile.close();
	return;
}

//===================================================================================================================================================================================================
//Erases duplicate words from the vector

void Extractor::RemoveDuplicateWords()
{
	wordList.erase(unique(wordList.begin(), wordList.end()), wordList.end());
}

//===================================================================================================================================================================================================
// Saves all the words from the wordList vector to a file

void Extractor::SaveWords(string wordListFile)
{
	ofstream OutputFile(wordListFile);

	unsigned length = wordList.size();
	for (int i = 0; i < length; i++)
	{
		OutputFile << wordList.at(i); //add all the extracted headlines to a file
		if (i < length - 1) OutputFile << '\n'; //add newlines (except on the last word)
	}

	OutputFile.close();
	return;
}

//===================================================================================================================================================================================================
//Getter for the number of simple words

int Extractor::GetSimpleWords() const {	return NumberOfSimpleWords;}

//===================================================================================================================================================================================================
//Getter for the number of non duplicate simple words

int Extractor::GetNonDuplicateSimpleWords() const {	return NumberOfNonDuplicateSimpleWords;}

//===================================================================================================================================================================================================
//Getter for the current size of the WordList

int Extractor::GetWordListLength() const { return wordList.size(); }

//===================================================================================================================================================================================================
//Given a line, searches for valid headlines and adds them to the wordList

void Extractor::VerifyAndAddValidWords(string line)
{
	bool hasColon = false;
	for (int i = 0; i < line.length(); i ++) //for each letter in the line
	{
		if (line.at(i) == ';') hasColon = true;
		if ((int)line.at(i) > 255 || (int) line.at(i) < 0) return; //if not a valid ASCII char, return

		if (islower(line.at(i))) //if it has lowercase letters return immediately
		{
			return;
		}
	}
	//If it gets to this point, its because the line only has Uppercase letters, symbols and spaces

	/////////////////////////////////////////////////////////////////
	// CODE TO DEAL WITH WORD VALIDITY AND INSERTION IN THE VECTOR //
	/////////////////////////////////////////////////////////////////

	if (!hasColon) //if line with only a word
	{
		if (!isValidWord(line)) return;//If not a valid word, end
		wordList.push_back(line);
		NumberOfSimpleWords++;
	}
	else // if line has colon
	{
		bool finishedLine = false;
		string lineCopy = line;
		do
		{
			size_t ColonPosition = lineCopy.find_first_of(';');
			if (ColonPosition == string::npos)
			{
				finishedLine = true; //if no more colons, finish the loop when it reaches the end
				if (!isValidWord(lineCopy)) return; //If not a valid word, end
				wordList.push_back(lineCopy); //adds the remaining word
				NumberOfSimpleWords++;
				
			}
			else
			{
				string substring = lineCopy.substr(0, ColonPosition); //stores a substring containing the word until the colon
				lineCopy.erase(0, ColonPosition + 2); //erases the word, colon and space
				if (substring.find(' ') != string::npos) RemoveEndSpaces(substring); //removes extra spaces in the end
				if (!isValidWord(substring)) continue; //If not a valid word, continue to the next word
				wordList.push_back(substring);
				NumberOfSimpleWords++;
			}
		} while (!finishedLine);
	}

	///////////////////////////////////////
	// CODE TO UPDATE THE USER INTERFACE //
	///////////////////////////////////////

	
	if (line.at(0) != currentChar) //When changing starting letter
	{
		if (firstIteration)
		{
			currentChar = 'A';
			cout << endl << currentChar << endl;
			firstIteration = false;
		}
		else if (line.at(0) == (int) currentChar + 1) //Guarantees that the display only changes letter if it is the next one alphabetically
		{
			currentChar = line.at(0);
			cout << endl << currentChar << endl;
		}
	}
	else //When starting letter does not change
	{
		if (NumberOfSimpleWords % 100 == 0)
			cout << '.';
	}
	return;
}

//===================================================================================================================================================================================================
//Checks if a given word is valid (if it is a headline). Assumes the word only has uppercase letters, symbols (not ';') and spaces

bool Extractor::isValidWord(std::string word)
{
	if (word.length() <= 0) return false; //if an empty string, return false

	for (int i = 0; i < word.length(); i++)
	{
		if (!isupper(word.at(i)))
			return false;
	}

	return true; //if none of the above tests fail, it's a valid word
}

void Extractor::RemoveEndSpaces(string &word)
{
	int endIndex = 0;
	for (size_t i = word.length() - 1; i >= 0; i--)
	{
		if (word.at(i) != ' ')
		{
			endIndex = i;
			break;
		}
	}
	word = word.substr(0, endIndex+1);
	return;
}