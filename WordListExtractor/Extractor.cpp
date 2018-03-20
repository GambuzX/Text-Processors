/* Extractor class functions definitions */

#pragma once
#include <iostream>
#include "Extractor.h"

using namespace std;

std::vector<std::string> Extractor::ProcessDictionary(string dictionary)
{
	vector<string> WordList;

	for (char letter = 'A'; letter < 'Z'; letter++) //for each letter from A to Z
	{
		cout << letter << endl;




	}



	return WordList;
}

void Extractor::SortWordList(vector<string>& WordList)
{


	return;
}

void Extractor::RemoveDuplicateWords(vector<string>& WordList)
{

	return;
}

void Extractor::SaveWordList(vector<string>& WordList, string wordListFile)
{

	return;
}

int Extractor::GetSimpleWords() const
{
	return NumberOfSimpleWords;
}

int Extractor::GetNonDuplicateSimpleWords() const
{
	return NumberOfNonDuplicateSimpleWords;
}
