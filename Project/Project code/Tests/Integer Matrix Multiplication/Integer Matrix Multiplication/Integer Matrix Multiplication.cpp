// Integer Matrix Multiplication.cpp : This cout contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <chrono>
#include <time.h>
#include <random>
#include <limits.h>
#include <fstream>
#include<ctime> 


using namespace std;

#define MICROS_TO_SECONDS 0.000001
#define DIVISION_FACTOR 3

int** AllocateMatrix(int dim);
void DeallocateMatrix(int **arr, int dim);
void PrintMatrix(int **arr, int dim);

int **MatrixMultiply(int **A, int **B, int n);

int dim = 500;

int test;
int nr_tests = 10;

int min_elem = 1000000000;
int max_elem = INT_MAX;

//ofstream cout;

default_random_engine gen;
uniform_int_distribution<int> d(min_elem, max_elem);

int main(void)
{

	// get curent date time of the test

	// Some computation here
	
	/*cout.open("integer-operations-multiple-divisions-test.txt");*/

	int i = 0;
	int j = 0;

	cout << "INTEGER OPERATIONS TESTING " << endl;

	cout << "Min element: " << min_elem << "  Max element: " << max_elem << endl << endl;

	for (int dimension = 100; dimension <= dim; dimension += 100) {
		cout << "DIMENSION: " << dimension << endl << endl;

		for (test = 1; test <= nr_tests; test++) {

			int **A = AllocateMatrix(dimension);
			//PrintMatrix(A, dimension);

			int **B = AllocateMatrix(dimension);
			//PrintMatrix(B, dimension);

			int **C = MatrixMultiply(A, B, dimension);
			//PrintMatrix(C, dimension);

			DeallocateMatrix(A, dimension);
			DeallocateMatrix(B, dimension);
			DeallocateMatrix(C, dimension);
		}

		cout << endl << endl << endl;
	}

	/*cout.close();
	*/
	return (0);
}

int **MatrixMultiply(int **A, int **B, int dim)
{
	int i;
	int j;
	int k;
	int sum;
	int **C;

	C = (int**)malloc(dim * sizeof(int*));

	for (i = 0; i < dim; i++)
	{
		C[i] = (int*)malloc(dim * sizeof(int));
	}

	auto beg = std::chrono::high_resolution_clock::now();
	//clock_t start = clock();

	for (i = 0; i < dim; i++)
	{
		for (j = 0; j < dim; j++)
		{
			sum = 0;
			for (k = 0; k < dim; k++)
			{
				sum += A[i][k] * B[k][j] ;
			}
			C[i][j] = sum / DIVISION_FACTOR;

		}
	}

	//clock_t end = clock();

	auto end = std::chrono::high_resolution_clock::now();

	auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - beg);

	//cout <<  "Total time " << (1.0 * dur.count())  << " seconds" << endl;

	double elapsed_time = MICROS_TO_SECONDS * dur.count();

	cout << "Dimension " << dim << " Test: " << test << " Total seconds : " << elapsed_time << endl;

	return(C);
}

void PrintMatrix(int **arr, int dim)
{
	int i, j;
	for (i = 0; i < dim; i++)
	{
		cout << "[ ";
		for (j = 0; j < dim; j++)
		{
			printf("%5d ", arr[i][j]);
		}
		cout << "]\n";
	}
}

void DeallocateMatrix(int **arr, int dim) {

	for (int i = 0; i < dim; i++) {
		free(arr[i]);
	}
	free(arr);
}


int** AllocateMatrix(int dim) {

	int** arr;

	arr = (int**)malloc(dim * sizeof(int*));

	for (int i = 0; i < dim; i++) {
		arr[i] = (int*)malloc(dim * sizeof(int));
		for (int j = 0; j < dim; j++) {
			arr[i][j] = d(gen);
		}
		// elemente
	}

	return arr;
}