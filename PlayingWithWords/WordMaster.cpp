#include "WordMaster.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int WordMaster::CountTotalWordsInFile(std::string filename)
{
	int total = 0;
	string line;
	ifstream file(filename);

	while (getline(file, line))
		total++;
	file.close();

	return total;
}

void WordMaster::ReadAndStoreWordList(std::string filename)
{
	ifstream wordListFile(filename);
	string line;
	wordCount = CountTotalWordsInFile(filename); //Stores the number of the words in the file in a variable to be used by all the other functions
	int currentCount = 0;
	int nextOutput = 25;

	cout << "0%";
	while (getline(wordListFile, line))
	{
		wordList.push_back(line);
		currentCount++	;

		int percentage = currentCount * 100 / wordCount;

		if (percentage == 25 && nextOutput == 25)
		{
			cout << "\b\b";
			cout << "25%";
			nextOutput = 50;
		}
		else if (percentage == 50 && nextOutput == 50)
		{
			cout << "\b\b\b";
			cout << "50%";
			nextOutput = 75;
		}
		else if (percentage == 75 && nextOutput == 75)
		{			
			cout << "\b\b\b";
			cout << "75%";
			nextOutput = 100;
		}
		else if (percentage == 100 && nextOutput == 100) {
			cout << "\b\b\b";
			cout << "100%\n";
		}
	}

	wordListFile.close();
	return;
}

void WordMaster::CheckWordInWordList()
{
	string userWord;
	cout << "Word to search ? ";
	cin >> userWord;

	for (int i = 0; i < userWord.length(); i++)
		userWord.at(i) = toupper(userWord.at(i));

	///////////////////
	// Binary Search //
	///////////////////

	int bottom, middle, top; 
	bottom = 0;
	top = wordCount - 1;
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


