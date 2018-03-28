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

	//General use
	std::vector<std::string> wordList;
	int wordCount;

	int CountTotalWordsInFile(std::string file);

	//Word scrambler methods
	void RandomScrambleIntro();
	std::string ScrambleLetters(std::string);
	bool WasCharUsed(int, std::vector<int>) const;



	

};