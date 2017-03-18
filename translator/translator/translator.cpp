// translator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
#include "WorkWithDict.h"
#include <Windows.h>


int main(int argc, char* argv[])
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	if (argc != 2)
	{
		std::cout << "Incorrect input data \n";
		return 1;
	}
	std::map<std::string, std::string> myDictionary;
	FillDict(myDictionary, argv[1]);
	DialogWithUser(myDictionary);
	std::cout << "Do you want save changes?(y,n) ";
	std::string selection;
	std::cin >> selection;
	if (selection == "y")
	{
		SaveChanges(myDictionary, argv[1]);
	}
	return 0;
}

