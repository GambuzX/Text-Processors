#pragma once

#include <string>
#include <vector>

class WordMaster
{
public:
	void ReadAndStoreWordList(std::string filename);
	void CheckWordInWordList();
	void GuessRandomScrambledWord();
	void ShowWordsUsingNLetters();
	void AskToBuildValidWordWithNLetters();
	void WildcardMatchingWords();

private:
	vector<string> wordList;

};