#include "stdafx.h"
#include "WorkWithDict.h"

void ToLower(std::string& arg)
{
	std::string result;
	std::transform(arg.begin(), arg.end(), back_inserter(result), [](char curCh){
		return tolower(curCh);
	});
	arg = result;
}

void RemoveExtraSpaces(std::string& arg)
{
	bool ignoreSpaces = true;
	bool wasNotSpace = false;
	std::string result;
	size_t strLen = arg.length();
	for (size_t i = 0; i < strLen; i++)
	{
		if (arg[i] == ' ')
		{
			ignoreSpaces = true;
		}
		else
		{
			if (wasNotSpace && ignoreSpaces)
			{
				result.push_back(' ');
			}
			result.push_back(arg[i]);
			wasNotSpace = true;
			ignoreSpaces = false;
		}
	}
	arg = result;
}


bool IsCorrectQuery(std::string& query)
{
	unsigned int len = query.size();
	if (len > 0)
	{
		for (size_t i = 0; i < len; ++i)
		{
			if (query[i] != ' ')
			{
				if (!((query[i] >= 'a' && query[i] <= 'z') || (query[i] <= 'Z' && query[i] >= 'A') || query[i] == ' '))
				{
					return false;
				}
			}
		}
		ToLower(query);
		return true;
	}
	return false;
}

void FillDict(std::map<std::string, std::string> &myDictionary, char* dictName)
{
	std::ifstream inpDict(dictName);
	if (!inpDict)
	{
		std::cout << "No dictionary file \n";
		std::ofstream fout(dictName);
		fout.close();
	}
	else
	{
		std::string curLine = "";		
		std::vector<std::string> VecStr;
		while (!inpDict.eof())
		{
			getline(inpDict, curLine);
			RemoveExtraSpaces(curLine);
			boost::split(VecStr, curLine, boost::is_any_of("-"));
			if (VecStr.size() != 2 || IsCorrectQuery(VecStr[1]))
			{
				continue;
			}
			myDictionary.insert(std::pair<std::string, std::string>(VecStr[0], VecStr[1]));
			VecStr.clear();
		}
	}
}

void SaveChanges(std::map<std::string, std::string> myDictionary, char* dictName)
{
	std::ofstream fout(dictName);
	for (auto& item : myDictionary)
	{
		fout << item.first << "-" << item.second << std::endl; //Вывод ключей и значений
	}
}

void DialogWithUser(std::map<std::string, std::string> &myDictionary)
{
	std::string fWord, sWord;
	while (fWord != "...")
	{
		std::cout << "Enter word -> ";
		//std::cin >> fWord;
		std::getline(std::cin, fWord);
		if (fWord == "...")
		{
			break;
		}
		if (!IsCorrectQuery(fWord))
		{
			std::cout << "Wrong data" << std::endl;
			continue;
		}
		if (myDictionary.find(fWord) != myDictionary.end())
		{
			std::cout << fWord << " -> " << myDictionary.at(fWord) << std::endl;
		}
		else
		{
			std::cout << "Enter transfer or ctr+Z Enter to exit -> ";
			std::getline(std::cin, sWord);
			if (sWord != "")
			{
				myDictionary.insert(std::pair<std::string, std::string>(fWord, sWord));
				sWord = "";
				fWord = "";
			}
			std::cin.clear();
		}
	}
}
