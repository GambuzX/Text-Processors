//Extractor class declaration

#pragma once
#include <vector>
#include <string>


class Extractor
{
public:
	void ProcessDictionary(std::string dictionary);
	void SortWordList();

	// Changing duplicate words to "x" - 1st approach
	void MarkDuplicateWordsAsInvalid();
	void SaveValidWords(std::string wordListFile);

	// Removing duplicate words from vector - 2nd approach
	void RemoveDuplicateWords();
	void SaveWords(std::string wordListFile);

	int GetSimpleWords() const;
	int GetNonDuplicateSimpleWords() const;
	int GetWordListLength() const;
	
private:

	std::vector<std::string> wordList;

	void VerifyAndAddValidWords(std::string line);
	bool isValidWord(std::string);

	char currentChar;
	bool firstIteration = true;
	int NumberOfSimpleWords = 0;
	int NumberOfNonDuplicateSimpleWords;

};