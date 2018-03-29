#include "WordMaster.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <time.h>
#include <map>

using namespace std;

//=============//
// GENERAL USE //
//=============//

// Converts a word to uppercase
void WordMaster::StringToUpper(string & word)
{
	for (int i = 0; i < word.length(); i++)
		word.at(i) = toupper(word.at(i));
	return;
}

//============================================================================================================================================
// Counts the number of words in the file and stores it in a variable

int WordMaster::CountTotalWordsInFile(std::string filename) const
{
	int total = 0;
	string line;
	ifstream file(filename);

	while (getline(file, line))
		total++;
	file.close();

	return total;
}

//======================//
// INITIALIZE WORD LIST //
//======================//

//Reads the file containing the word list and stores the words in a vector
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

//=========================//
// CHECK WORD IN WORD LIST //
//=========================//

void WordMaster::CheckWordInWordList()
{
	string userWord;
	cout << "Word to search ? ";
	cin >> userWord;

	StringToUpper(userWord);

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

//=================//
// RANDOM SCRAMBLE //
//=================//

//Selects random word, scrambles it and asks user to guess it. Has more than one try.
void WordMaster::GuessRandomScrambledWord()
{
	const int NUMBER_OF_GUESSES = 3;
	srand(time(NULL));
	int randomNumber = rand() % wordCount; //from 0 up to wordCount-1
	string randomWord = wordList.at(randomNumber);

	RandomScrambleIntro();
	string scrambledWord = ScrambleLetters(randomWord);
	cout << "The scrambled word is " << scrambledWord << ".\n";
	cout << "Can you guess what the original word was? \n\n";

	int currentGuess = 1;
	bool correctGuess = false;
	while (currentGuess <= NUMBER_OF_GUESSES && !correctGuess)
	{
		string guess;
		cout << "Guess " << currentGuess << "? ";
		cin >> guess;
		StringToUpper(guess);

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}

		if (guess == randomWord)
			correctGuess = true;
		else
			currentGuess++;
	}
	cout << endl;
	if (correctGuess)
		cout << "Good job! You guessed the word!\n";
	else
		cout << "Too bad... None of your guesses were correct.\n";
	return;
}

//============================================================================================================================================

void WordMaster::RandomScrambleIntro()
{
	cout << "   __                 _                   __                          _     _      \n";
	cout << "  /__\\ __ _ _ __   __| | ___  _ __ ___   / _\\ ___ _ __ __ _ _ __ ___ | |__ | | ___ \n";
	cout << " / \\/// _` | '_ \\ / _` |/ _ \\| '_ ` _ \\  \\ \\ / __| '__/ _` | '_ ` _ \\| '_ \\| |/ _ \\ \n";
	cout << "/ _  \\ (_| | | | | (_| | (_) | | | | | | _\\ \\ (__| | | (_| | | | | | | |_) | |  __/\n";
	cout << "\\/ \\_/\\__,_|_| |_|\\__,_|\\___/|_| |_| |_| \\__/\\___|_|  \\__,_|_| |_| |_|_.__/|_|\\___|\n";
	cout << "___________________________________________________________________________________\n\n";
	return;
}

//============================================================================================================================================

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
	return scrambledWord;
}

//============================================================================================================================================

bool WordMaster::WasCharUsed(int index, vector<int> usedIndexes) const
{
	for (unsigned i = 0; i < usedIndexes.size(); i++)
		if (usedIndexes.at(i) == index)
			return true;
	return false;
}

//==============================//
// WORDS WITH SPECIFIED LETTERS //
//==============================//

//Ask the user a set of N letters and show all the words present in the dictionary that can be built using the set of the given letters 
void WordMaster::ShowWordsUsingNLetters()
{
	//TODO add Intro
	vector<char> letters;
	do
	{
		letters.clear(); //reset vector
		AskForLetters(letters); //fill vector	
	} while (!validLettersInput(letters));

	cout << "Words Found: \n";
	for (int i = 0; i < wordCount; i++)
	{
		string currentWord = wordList.at(i);
		if (WordOnlyContainsNLetters(currentWord, letters))
		{
			cout << currentWord << endl;
		}
	}
	return;
}

//============================================================================================================================================
// Asks for the letters to be used and fills the letters vector with it

void WordMaster::AskForLetters(vector<char>& letters)
{
	int nLetters;
	do
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
		cout << "Number of letters? ";
		cin >> nLetters;
	} while (cin.fail());

	int lettersAdded = 0;
	cout << "Letters to include? ";
	while (lettersAdded < nLetters)
	{
		char letter;
		cin >> letter;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else
		{
			letters.push_back(toupper(letter)); //Adds the letter in uppercase
			lettersAdded++;
		}
	}
}

//============================================================================================================================================
// Verifies if all the letters given by the user are alphabetic

bool WordMaster::validLettersInput(vector<char> letters) const
{
	for (int i = 0; i < letters.size(); i++)
	{
		if (!isupper(letters.at(i)))
		{
			cout << "Please enter only alphabetical characters.\n\n";
			return false;
		}
	}
	return true;
}

//============================================================================================================================================
// Verifies if the given word only contains letters from the specified list of letters

bool WordMaster::WordOnlyContainsNLetters(string word, vector<char> letters) const
{
	for (int i = 0; i < word.length(); i++) //loop for each letter in the word
	{
		char currentLetter = word.at(i);
		bool letterFound = false;
		for (int j = 0; j < letters.size(); j++) //loop for each char in the vector and compare it against the current letter
		{
			if (currentLetter == letters.at(j))
				letterFound = true;
		}
		if (!letterFound)
			return false;
	}
	return true;
}

//==============//
// WORD BUILDER //
//==============//

//Randomly choose a set of N letters and ask the user to build a valid word, then verify if the word belongs to the word list or not.
//The set of letters must be chosen by a larger set, built according to the number of each letter in the word list

void WordMaster::AskToBuildValidWordWithNLetters()
{
	//TODO add intro

	//TODO Calculate only once. Verify if it is initialized or not
	BuildCharFrequencyMap(); 	

	//Ask for the number of letters
	int nLetters;
	do
	{
		cout << "Number of letters? ";
		cin >> nLetters;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
	} while (!cin.fail());

	//Select set of n letters from the major set
	vector<char> letters = SelectNLettersFromMajorSet(nLetters);

	//Ask to build word

	//Check if word is in dictionary
}

void WordMaster::BuildCharFrequencyMap()
{
	for (char letter = 'A'; letter <= 'Z'; letter++) //initializes the map with 0 for each letter
		charFrequency[letter] = 0;

	cout << "Calculating the number of ocurrences of each letter ... \n\n";
	for (int i = 0; i < wordCount; i++) // for each word
	{
		string currentWord = wordList.at(i);
		for (int j = 0; j < currentWord.length(); j++) //for each letter in the word
		{
			charFrequency[currentWord.at(j)] ++; //increments the frequence of the letter
		}
	}
	return;
}

map<char, int> WordMaster::BuildCumulativeCharFrequencyMap()
{
	map<char, int> cumulativeMap;
	int total = 0;
	for (char letter = 'A'; letter <= 'Z'; letter++)
	{
		total += charFrequency[letter];
		cumulativeMap[letter] = total;
	}
	return cumulativeMap;
}

vector<char> WordMaster::SelectNLettersFromMajorSet(int nLetters)
{
	vector<char> letters;

	map<char, int> cumulativeMap = BuildCumulativeCharFrequencyMap();
	srand(time(NULL));
	for (int i = 1; i <= nLetters; i++)
	{
		int randomNumber = rand() % cumulativeMap['Z'] + 1; //random number modulus the total number of chars
		for (char letter = 'A'; letter <= 'Z'; letter++)
		{
			if (randomNumber <= cumulativeMap[letter])
			{
				letters.push_back(letter);
				break;
			}
		}
	}
	return letters;
}

//=========================//
// WILDCARD MATCHING WORDS //
//=========================//

//Read a string containing one or more wildcard characters ('*' or '?') and show all the words in the dictionary that match the given string

void WordMaster::WildcardMatchingWords()
{
}


