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
	std::vector<std::string> wordList;
	int CountTotalWordsInFile(std::string file);

	int wordCount;

};