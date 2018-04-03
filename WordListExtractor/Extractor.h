//Extractor class declaration

#pragma once
#include <vector>
#include <string>


class Extractor
{
public:
	void ProcessDictionary(std::string dictionary);
	void SortWordList();
	void MarkDuplicateWordsAsInvalid();
	void SaveValidWords(std::string wordListFile);
	int GetSimpleWords() const;
	int GetNonDuplicateSimpleWords() const;
	
private:

	std::vector<std::string> wordList;

	void VerifyAndAddValidWords(std::string line);
	bool isValidWord(std::string);

	char currentChar = 'A'; //start with A
	int NumberOfSimpleWords = 0;
	int NumberOfNonDuplicateSimpleWords;

};