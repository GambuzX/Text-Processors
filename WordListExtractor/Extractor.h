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
	void StoreWordListInFile(std::vector<std::string> &WordList, std::string wordListFile);
	
private:

	int NumberOfSimpleWords;
	int NumberOfNonDuplicateSimpleWords;

};