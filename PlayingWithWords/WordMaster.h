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
	void WordBuilder();
	void WordBuilderV2();
	void WildcardMatchingWords();

private:

	//General use
	std::vector<std::string> wordList;
	int wordCount;
	std::map<char, int> charFrequency;

	int CountTotalWordsInFile(std::string file) const;
	void StringToUpper(std::string&);
	long long int GenerateRandomNumber();
	//void ClearBuffer();

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
	bool WordOnlyContainsGivenLetters(std::string, std::vector<char>);

	//Word builder 2.0
	void WordBuilderIntroV2();
	void BuildCharFrequencyMap();
	std::map<char, int> BuildCumulativeCharFrequencyMap();
	std::vector<char> SelectNLettersFromMajorSet(int);
	bool WordContainsAllLetters(std::string, std::vector<char>);
	bool LettersOcurrencesMatch(std::string, std::vector<char>);
	
	//Wildcard matching
	void WildcardMatchIntro();
	bool wildcardMatch(const char *str, const char *strWild);
};