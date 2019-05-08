#include "pch.h"
#include "IntegerMatrixMulTest.h"
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

#define MICROS_TO_SECONDS 0.000001
#define DIVISION_FACTOR 3







IntegerMatrixMulTest::IntegerMatrixMulTest()
{
	this->min_dim = 100;
	this->max_dim = 500;
	this->step = 100;
	this->nr_tests_per_run = 10;
}

IntegerMatrixMulTest::IntegerMatrixMulTest(int min_dim, int max_dim, int step, int nr_tests_per_run)
{
	this->min_dim = min_dim;
	this->max_dim = max_dim;
	this->step = step;
	this->nr_tests_per_run = nr_tests_per_run;

}

void IntegerMatrixMulTest::runTest() {
	cout << "Integer Matrix Mul Test" << endl << endl;

	int i = 0;
	int j = 0;

	for (int dimension = this-> min_dim; dimension <= this ->max_dim; dimension += this->step) {
		cout << "DIMENSION: " << dimension << endl << endl;

		float avg_elapsed_time = 0.0;
		int pos_elapsed_time_no = 0;

		for (int test = 1; test <= this->nr_tests_per_run; test++) {

			int **A = AllocateMatrix(dimension);
			//PrintMatrix(A, dimension);

			int **B = AllocateMatrix(dimension);
			//PrintMatrix(B, dimension);

			float time = MatrixMultiply(A, B, dimension);
			//PrintMatrix(C, dimension);

			if (time > 0.0) {
				avg_elapsed_time += time;
				pos_elapsed_time_no++;
			}

			DeallocateMatrix(A, dimension);
			DeallocateMatrix(B, dimension);

		}

		avg_elapsed_time /= pos_elapsed_time_no;

		cout << "Avg elapsed time: " << avg_elapsed_time  << " seconds";

		this->results.push_back(avg_elapsed_time);


		cout << endl << endl << endl;
	}


}



float IntegerMatrixMulTest::MatrixMultiply(int **A, int **B, int dim)
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
				sum += A[i][k] * B[k][j];
			}
			C[i][j] = sum / DIVISION_FACTOR;

		}
	}

	//clock_t end = clock();

	auto end = std::chrono::high_resolution_clock::now();

	auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - beg);

	//cout <<  "Total time " << (1.0 * dur.count())  << " seconds" << endl;

	double elapsed_time = MICROS_TO_SECONDS * dur.count();

	return elapsed_time;
}

int** IntegerMatrixMulTest::AllocateMatrix(int dim) {

	int min_elem = 1000000000;
	int max_elem = INT_MAX;

	default_random_engine gen;
	uniform_int_distribution<int> d(min_elem, max_elem);

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

void IntegerMatrixMulTest::DeallocateMatrix(int **arr, int dim) {

	for (int i = 0; i < dim; i++) {
		free(arr[i]);
	}
	free(arr);
}


IntegerMatrixMulTest::~IntegerMatrixMulTest()
{
}
