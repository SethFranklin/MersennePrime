
#pragma once

#include <string>

#include "Number.h"

number InputValue(std::string ValueName);

void OutputValue(std::string ValueName, number Value);

void OutputString(std::string StringToOutput);

bool YesNoPrompt(std::string Prompt);

void ContinuePrompt(); // Press enter to continue...