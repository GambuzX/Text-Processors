#include "WordMaster.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void WordMaster::ReadAndStoreWordList(std::string filename)
{
	ifstream wordListFile(filename);
	string line;

	while (getline(wordListFile, line))
	{
		wordList.push_back(line);
	}	
	wordListFile.close();
	return;
}

void WordMaster::CheckWordInWordList()
{
	string userWord;
	cout << "Word to search ? ";
	cin >> userWord;

	for (char letter : userWord)
		letter = toupper(letter);

	///////////////////
	// Binary Search //
	///////////////////

	int bottom, middle, top; 
	bottom = 0;
	top = wordList.size() - 1;
	bool found = false;

	while (top > bottom && !found) {
		middle = (top + bottom) / 2;
		if (wordList.at(middle) == userWord) {
			found = true;
		}
		else {
			if (wordList.at(middle) < userWord) {
				bottom = middle + 1;
			}
			else {
				top = middle - 1;
			}
		}
	}

	if (wordList.at(bottom) == userWord)
		found = true;
	else if (wordList.at(top) == userWord)
		found = true;
	else if (wordList.at(middle) == userWord)
		found = true;

	
	if (found)
		cout << "The word " << userWord << " is in the list.\n";
	else
		cout << "The word " << userWord << " is not in the list.\n";
}

void WordMaster::GuessRandomScrambledWord()
{
}

void WordMaster::ShowWordsUsingNLetters()
{
}

void WordMaster::AskToBuildValidWordWithNLetters()
{
}

void WordMaster::WildcardMatchingWords()
{
}
