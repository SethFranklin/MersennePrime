
#include "Number.h"

#include <string>
#include <iostream>
#include <ctype.h>

bool IsStringNumber(std::string StringToCheck);
void ClearCinBuffer();

number InputValue(std::string ValueName)
{

	bool GotNumber = false;
	
	while (!GotNumber)
	{

		std::string InputString;

		std::cout << ValueName << ": ";
		std::getline(std::cin, InputString);

		if (IsStringNumber(InputString))
		{

			GotNumber = true;
			return (number) std::stoi(InputString, nullptr);

		}
		else
		{

			std::cout << "Not a valid unsigned interger" << std::endl;

		}

	}

	return NULL;

}

void OutputValue(std::string ValueName, number Value)
{

	std::cout << ValueName << ": " << Value << std::endl;

}

void OutputString(std::string StringToOutput)
{

	std::cout << StringToOutput << std::endl;

}

bool YesNoPrompt(std::string Prompt)
{

	char InputChar;

	std::cout << Prompt << " [Y/n] ";
	std::cin >> InputChar;
	ClearCinBuffer();

	return (InputChar == 'y' || InputChar == 'Y') ? true : false;

}

void ContinuePrompt()
{

	std::cout << "Press enter to continue...";
	ClearCinBuffer();

}

bool IsStringNumber(std::string StringToCheck)
{

	bool IsNumber = true;

	if (StringToCheck[0] == '+' || StringToCheck[0] == '-' || StringToCheck[0] == '0') return false;

	for (char& Character : StringToCheck)
	{

		if (!isdigit(Character)) IsNumber = false;

	}

	return IsNumber;

}

void ClearCinBuffer()
{

	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');

}