#include "WordMaster.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

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
	wordCount = CountTotalWordsInFile(filename);
	int currentCount = 0;

	cout << "    ";
	while (getline(wordListFile, line))
	{
		wordList.push_back(line);
		currentCount++	;

		/*int percentage = currentCount * 100 / wordCount;

		if (percentage < 10) //one digit only
		{
			cout << "\b\b";
			cout << percentage << "%";
		}
		else if (percentage < 100)
		{
			cout << "\b\b\b";
			cout << percentage << "%";
		}
		else
		{
			cout << "\b\b\b\b";
			cout << percentage << "%";
		}*/
	}

	wordListFile.close();
	return;
}

void WordMaster::CheckWordInWordList()
{
	string userWord;
	cout << "Word to search ? ";
	cin >> userWord;

	for (auto letter : userWord)
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


