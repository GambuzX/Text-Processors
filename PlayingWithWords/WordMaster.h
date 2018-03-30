#pragma once

#include <string>
#include <vector>
#include <map>

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
	std::map<char, int> charFrequency;

	int CountTotalWordsInFile(std::string file) const;
	void StringToUpper(std::string&);

	//Word Finder
	void WordFinderIntro();
	bool isWordInWordList(std::string);

	//Word scrambler methods
	void RandomScrambleIntro();
	std::string ScrambleLetters(std::string);
	bool WasCharUsed(int, std::vector<int>) const;

	//Words with specified letters
	void WordsWithNLettersIntro();
	bool validLettersInput(std::vector<char>) const;
	void AskForLetters(std::vector<char>&);
	bool WordOnlyContainsNLetters(std::string, std::vector<char>) const;

	//Word builder
	void WordBuilderIntro();
	void BuildCharFrequencyMap();
	std::map<char, int> BuildCumulativeCharFrequencyMap();
	std::vector<char> SelectNLettersFromMajorSet(int);
	bool WordContainsAllLetters(std::string, std::vector<char>);
	
	//Wildcard matching
	void WildcardMatchIntro();
	bool wildcardMatch(const char *str, const char *strWild);
};