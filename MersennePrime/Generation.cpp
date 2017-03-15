
#include "Generation.h"

#include <vector>
#include <thread>
#include <math.h>
#include <mutex>

#include "Number.h"
#include "InputOutput.h"
#include "MainThread.h"

typedef enum {composite, prime} primality;

void MersenneThread(std::vector<number> NumbersToTest);
primality LucasLehmerTest(number NumberTest);
primality BasicPrimeTest(number NumberTest);

std::vector<number> FoundMersennes;
std::mutex MersennesMutex;

std::vector<number> GenerateMersennes(number MinimumN, number MaximumN)
{

	FoundMersennes.clear();

	unsigned int ThreadCount = GetThreadCount();
	std::vector<std::thread> Threads;

	std::vector<std::vector<number>> NValues;

	if (MinimumN % 2 == 0) MinimumN++;
	if (MaximumN % 2 == 0) MaximumN--;

	for (unsigned int ThreadIndex = 0; ThreadIndex < ThreadCount; ThreadIndex++) NValues.push_back(std::vector<number>());

	unsigned int ThreadNumber = 0;

	for (number NValueIndex = MinimumN; NValueIndex <= MaximumN; NValueIndex += 2)
	{

		NValues[ThreadNumber].push_back(NValueIndex);

		ThreadNumber++;
		if (ThreadNumber >= ThreadCount) ThreadNumber = 0;

	}

	for (unsigned int ThreadIndex = 0; ThreadIndex < ThreadCount; ThreadIndex++) Threads.push_back(std::thread(MersenneThread, NValues[ThreadIndex]));
	for (unsigned int ThreadIndex = 0; ThreadIndex < ThreadCount; ThreadIndex++) Threads[ThreadIndex].join();

	return FoundMersennes;

}

void MersenneThread(std::vector<number> NumbersToTest)
{

	std::vector<number> ProcessedNumbers;

	for (number NCheck : NumbersToTest)
	{

		if (BasicPrimeTest(NCheck) == prime && LucasLehmerTest(NCheck) == prime) ProcessedNumbers.push_back(NCheck);

	}

	MersennesMutex.lock();

	FoundMersennes.insert(FoundMersennes.end(), ProcessedNumbers.begin(), ProcessedNumbers.end());

	MersennesMutex.unlock();

}

primality LucasLehmerTest(long long NumberTest)
{

	/*

	long long s = 4;
	long long m = (((long long) std::pow(2, NumberTest)) - 1);

	for (number i = 3; i <= NumberTest; i++)
	{

		if (NumberTest == 61) OutputValue("", s);

		s = ((s * s) - 2) % m;

		

	}

	return (s == 0) ? prime : composite;

	@TODO: Use GMP to avoid overflow for n values from 61 and on

	*/

	return prime;


}

primality BasicPrimeTest(number NumberTest)
{

	for (number Factor = 2; Factor < sqrt(NumberTest) + 1; Factor++)
	{

		if (NumberTest % Factor == 0) return composite;

	}

	return prime;

}