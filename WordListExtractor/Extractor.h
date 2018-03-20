//Extractor class declaration

#pragma once
#include <vector>
#include <string>


class Extractor
{
public:
	std::vector<std::string> ProcessDictionary(std::string dictionary);
	void SortWordList(std::vector<std::string> &WordList);
	void RemoveDuplicateWords(std::vector<std::string> &WordList);
	void SaveWordList(std::vector<std::string> &WordList, std::string wordListFile);
	int GetSimpleWords() const;
	int GetNonDuplicateSimpleWords() const;
	
private:

	//void ExtractWordsWithLetter(std::vector<std::string> &wordList, std::string dictionaryFile, char letter);
	void VerifyAndAddValidWords(std::vector<std::string> &wordList, std::string line, char &currentChar, int &validWords);

	int NumberOfSimpleWords;
	int NumberOfNonDuplicateSimpleWords;

};