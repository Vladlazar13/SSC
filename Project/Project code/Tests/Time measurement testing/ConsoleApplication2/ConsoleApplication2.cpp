
#include "stdlib.h"
#include "time.h"
#include <windows.h>
#include "stdio.h"
#include "pch.h"
#include <iostream>
#include <chrono>

using namespace std;


clock_t start_t, end_t, total_t;

unsigned long* numbers;

typedef struct MyData {
	unsigned long start;
	unsigned long len;
} MYDATA, *PMYDATA;

DWORD WINAPI MyThreadFunction(LPVOID lpParam);

int is_prime(unsigned long n)
{

	for (unsigned long i = 2; i < n; i++)
	{
		if (n%i == 0) return 0;
	}
	return 1;
}

int main(int argc, char* argv[])

{
	unsigned long lEnd, failure, mult, len, nThreads;
	unsigned long i;

	HANDLE*  hThreadArray;
	DWORD*   dwThreadIdArray;
	PMYDATA* pDataArray;

	int nr_tests = 10;

	for (int k = 0; k < nr_tests; k ++) {

		cout << "TEST: " << k + 1 << endl;

		for (long upperBound = 10000; upperBound <= 1000000; upperBound *= 5) {
			for (long nrThreads = 1; nrThreads <= 64; nrThreads *= 2) {

				//start_t = clock();
				auto beg = std::chrono::high_resolution_clock::now();

				lEnd = upperBound;
				nThreads = nrThreads;

				hThreadArray = new HANDLE[nThreads];
				dwThreadIdArray = new DWORD[nThreads];
				pDataArray = new PMYDATA[nThreads];

				len = lEnd - 1;

				numbers = new unsigned long[len];

				for (i = 0; i < len; i++)
				{
					numbers[i] = i + 2;
				}

				for (i = 0; i < nThreads; i++)
				{

					pDataArray[i] = (PMYDATA)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(MYDATA));
					pDataArray[i]->len = len / nThreads;
					pDataArray[i]->start = i * len / nThreads;

					if (i == nThreads - 1)
					{
						pDataArray[i]->len += len - (len / nThreads + i * len / nThreads);
					}
					hThreadArray[i] = CreateThread(NULL, 0, MyThreadFunction, pDataArray[i], 0, &dwThreadIdArray[i]);
				}


				WaitForMultipleObjects(nThreads, hThreadArray, TRUE, INFINITE);
				for (int i = 0; i < nThreads; i++)
				{
					CloseHandle(hThreadArray[i]);
					if (pDataArray[i] != NULL)
					{
						HeapFree(GetProcessHeap(), 0, pDataArray[i]);
						pDataArray[i] = NULL;
					}
				}


				//for (i = 0; i < len; i++)
				//{
				//	if (numbers[i] > 0)
				//	{
				//		printf("%d\n", numbers[i]);
				//	}
				//}

				delete[] numbers;
				delete[] hThreadArray;
				delete[] dwThreadIdArray;
				delete[] pDataArray;

				failure = 0;

				auto end = std::chrono::high_resolution_clock::now();

				//end_t = clock();

				// total_t = (end_t - start_t);

				//cout << "Upper bound : " << upperBound << " Number of Threads: " << nrThreads << "Total time " << (float)total_t / CLOCKS_PER_SEC << " seconds" << endl;
				auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - beg);
				cout << "Upper bound : " << upperBound << " Number of Threads: " << nrThreads << "Total time " << (1.0 * dur.count()) * 0.000001  << " seconds" << endl;
			}
		}
	}

	return failure;
}

DWORD WINAPI MyThreadFunction(LPVOID lpParam)
{
	PMYDATA pDataArray;
	pDataArray = (PMYDATA)lpParam;


	unsigned long k, mult, j;

	for (k = pDataArray->start; k < pDataArray->start + pDataArray->len; k++)
	{
		if (is_prime(numbers[k]) == 1)
		{

			for (j = 2 * numbers[k] - 2; j < pDataArray->len; j += numbers[k])
			{
				numbers[j] = 0;

			}

		}
		else { numbers[k] = 0; }
	}
	return 0;
}