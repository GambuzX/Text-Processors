//Extractor class declaration

#pragma once
#include <vector>
#include <string>


class Extractor
{
public:
	void ProcessDictionary(std::string dictionary);
	void SortWordList();
	void RemoveDuplicateWords();
	void SaveWordList(std::string wordListFile);
	int GetSimpleWords() const;
	int GetNonDuplicateSimpleWords() const;
	
private:

	std::vector<std::string> wordList;

	//void ExtractWordsWithLetter(std::vector<std::string> &wordList, std::string dictionaryFile, char letter);
	void VerifyAndAddValidWords(std::string line);

	char currentChar;
	int headlinesDetected = 0;

	int NumberOfNonDuplicateSimpleWords;

};