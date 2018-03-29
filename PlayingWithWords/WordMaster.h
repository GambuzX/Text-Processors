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

	int CountTotalWordsInFile(std::string file) const;
	void StringToUpper(std::string&);

	//Word scrambler methods
	void RandomScrambleIntro();
	std::string ScrambleLetters(std::string);
	bool WasCharUsed(int, std::vector<int>) const;

	//Words with specified letters
	bool validLettersInput(std::vector<char>) const;
	void AskForLetters(std::vector<char>&);
	bool WordOnlyContainsNLetters(std::string, std::vector<char>) const;



	

};