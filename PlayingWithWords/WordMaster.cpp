#include "WordMaster.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

//============================================================================================================================================
//Reads the file containing the word list and stores the words in a vector

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

//============================================================================================================================================
//Checking if user given word is in the word List or not

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

//============================================================================================================================================
//Selects random word, scrambles it and asks user to guess it. Has more than one try.

void WordMaster::GuessRandomScrambledWord()
{
	srand(time(NULL));
	int randomNumber = rand() % wordCount; //from 0 up to wordCount-1
	string randomWord = wordList.at(randomNumber);

	RandomScrambleIntro();
	string scrambledWord = ScrambleLetters(randomWord);
	cout << "The scrambled word is " << randomWord;
}

void WordMaster::RandomScrambleIntro()
{
	cout << "   __                 _                   __                          _     _      \n";
	cout << "  /__\\ __ _ _ __   __| | ___  _ __ ___   / _\\ ___ _ __ __ _ _ __ ___ | |__ | | ___ \n";
	cout << " / \\/// _` | '_ \\ / _` |/ _ \\| '_ ` _ \\  \\ \\ / __| '__/ _` | '_ ` _ \\| '_ \\| |/ _ \\ \n";
	cout << "/ _  \\ (_| | | | | (_| | (_) | | | | | | _\\ \\ (__| | | (_| | | | | | | |_) | |  __/\n";
	cout << "\\/ \\_/\\__,_|_| |_|\\__,_|\\___/|_| |_| |_| \\__/\\___|_|  \\__,_|_| |_| |_|_.__/|_|\\___|\n";
	cout << "___________________________________________________________________________________\n";
	return;
}

string WordMaster::ScrambleLetters(string originalWord)
{
	unsigned length = originalWord.length();
	string scrambledWord = originalWord;
	vector<char> availableChars;
	vector<int> usedIndexes;
	srand(time(NULL));

	//Fills the chars vector
	for (unsigned i = 0; i < length; i++)
		availableChars.push_back(originalWord.at(i));

	//Scrambles the word
	for (unsigned i = 0; i < length; i++)
	{
		int randomNumber = rand() % length;
		char randomChar = availableChars.at(randomNumber);
		if (!WasCharUsed(randomNumber, usedIndexes)) //Checks if the random char was already used
		{
			scrambledWord.at(i) = randomChar;
			usedIndexes.push_back(randomNumber); //adds the char to the usedChars
		}
		else //if char was already used
		{
			bool foundChar = false;
			randomNumber = rand() % length;
			while (!foundChar)
			{
				randomChar = availableChars.at(randomNumber);
				if (!WasCharUsed(randomNumber, usedIndexes))
				{
					scrambledWord.at(i) = randomChar;
					usedIndexes.push_back(randomNumber);
					foundChar = true;
				}
				else //increments the random number
				{
					if (randomNumber < length - 1)
						randomNumber++;
					else
						randomNumber = 0;
				}
			}
		}
	}
	return;
}

bool WordMaster::WasCharUsed(int index, vector<int> usedIndexes) const
{
	for (unsigned i = 0; i < usedIndexes.size(); i++)
		if (usedIndexes.at(i) == index)
			return true;
	return false;
}

//============================================================================================================================================
//Ask the user a set of N letters and show all the words present in the dictionary that can be built using the set of the given letters 
//(Improvement: or any subset of them)

void WordMaster::ShowWordsUsingNLetters()
{
}

//============================================================================================================================================
//Randomly choose a set of N letters and ask the user to build a valid word, then verify if the word belongs to the word list or not.

void WordMaster::AskToBuildValidWordWithNLetters()
{
}

//============================================================================================================================================
//Read a string containing one or more wildcard characters ('*' or '?') and show all the words in the dictionary that match the given string

void WordMaster::WildcardMatchingWords()
{
}


