#include "pch.h"
#include "FloatingMatrixMulTest.h"

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
#include <cmath>

#define MICROS_TO_SECONDS 0.000001

#define M_PI acos(-1.0)




FloatingMatrixMulTest::FloatingMatrixMulTest()
{
	this->min_dim = 100;
	this->max_dim = 500;
	this->step = 100;
	this->nr_tests_per_run = 10;
}

FloatingMatrixMulTest::FloatingMatrixMulTest(int min_dim, int max_dim, int step, int nr_tests_per_run)
{
	this->min_dim = min_dim;
	this->max_dim = max_dim;
	this->step = step;
	this->nr_tests_per_run = nr_tests_per_run;

}

void FloatingMatrixMulTest::runTest() {

	cout << "Floating Point Matrix Mul Test" << endl << endl;

	int i = 0;
	int j = 0;

	for (int dimension = this->min_dim; dimension <= this->max_dim; dimension += this->step) {
		cout << "DIMENSION: " << dimension << endl;

		float avg_elapsed_time = 0.0;
		int pos_elapsed_time_no = 0;


		for (int test = 1; test <= this->nr_tests_per_run; test++) {

			float **A = AllocateMatrix(dimension);
			//cout << "A: " << endl;
			//PrintMatrix(A, dimension);

			float **B = AllocateMatrix(dimension);
			//cout << "B: " << endl;
			//PrintMatrix(B, dimension);

			float time = MatrixMultiply(A, B, dimension);

			if (time >= 0) {
				avg_elapsed_time += time;
				pos_elapsed_time_no++;
			}

			//cout << "C: " << endl;
			//PrintMatrix(C, dimension);

			DeallocateMatrix(A, dimension);
			DeallocateMatrix(B, dimension);

		}

		avg_elapsed_time /= pos_elapsed_time_no;

		cout << "Avg elapsed time: " << avg_elapsed_time << " seconds";
		this->results.push_back(avg_elapsed_time);

		cout << endl << endl;
	}

}

float** FloatingMatrixMulTest::AllocateMatrix(int dim) {

	float min_elem = FLT_MIN;
	float max_elem = FLT_MAX;


	default_random_engine gen;
	uniform_real_distribution<float> d(min_elem, max_elem);

	float** arr;

	arr = (float**)malloc(dim * sizeof(float*));

	for (int i = 0; i < dim; i++) {
		arr[i] = (float*)malloc(dim * sizeof(float));
		for (int j = 0; j < dim; j++) {
			arr[i][j] = d(gen);
		}
		// elemente
	}

	return arr;
}

void FloatingMatrixMulTest::DeallocateMatrix(float **arr, int dim) {

	for (int i = 0; i < dim; i++) {
		free(arr[i]);
	}
	free(arr);
}

float FloatingMatrixMulTest::MatrixMultiply(float **A, float **B, int dim)
{
	int i;
	int j;
	int k;
	float sum;
	float **C;

	C = (float**)malloc(dim * sizeof(float*));

	for (i = 0; i < dim; i++)
	{
		C[i] = (float*)malloc(dim * sizeof(float));
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
			C[i][j] = sum / M_PI;

		}
	}

	//clock_t end = clock();

	auto end = std::chrono::high_resolution_clock::now();

	auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - beg);

	//cout <<  "Total time " << (1.0 * dur.count())  << " seconds" << endl;

	double elapsed_time = MICROS_TO_SECONDS * dur.count();

	return elapsed_time;
}




FloatingMatrixMulTest::~FloatingMatrixMulTest()
{
}
