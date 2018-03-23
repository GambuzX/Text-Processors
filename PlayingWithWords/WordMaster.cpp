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
