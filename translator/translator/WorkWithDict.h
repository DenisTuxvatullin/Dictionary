#pragma once
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>
void RemoveExtraSpaces(std::string& arg);
bool IsCorrectQuery(std::string& query);
void FillDict(std::map<std::string, std::string> &myDictionary, char* dictName);
void SaveChanges(std::map<std::string, std::string> myDictionary, char* dictName);
void DialogWithUser(std::map<std::string, std::string> &myDictionary);
void ToLower(std::string& arg);


