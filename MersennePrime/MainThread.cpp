
#include "MainThread.h"

#include <thread>
#include <vector>

#include "InputOutput.h"
#include "Number.h"
#include "Generation.h"

void MainThread();

unsigned int ThreadCount;
std::thread Threads[];

std::vector<number> Mersennes;

void StartMainThread()
{

	MainThread();

}

unsigned int GetThreadCount()
{

	return ThreadCount;

}

void MainThread()
{

	OutputString("Mersenne Prime Generator");
	OutputString("Seth Franklin");

	ThreadCount = std::thread::hardware_concurrency();

	number Min = InputValue("Minimum N");
	number Max = 10000000;

	std::vector<number> Numbers = GenerateMersennes(Min, Max);

	for (number a : Numbers) OutputValue("", a);

	ContinuePrompt();

}