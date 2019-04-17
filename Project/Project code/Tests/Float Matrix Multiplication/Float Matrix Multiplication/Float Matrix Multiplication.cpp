// Integer Matrix Multiplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
#include <cmath>


using namespace std;

#define MICROS_TO_SECONDS 0.000001

#define M_PI acos(-1.0)

float** AllocateMatrix(int dim);
void DeallocateMatrix(float **arr, int dim);
void PrintMatrix(float **arr, int dim);

float **MatrixMultiply(float **A, float **B, int n);

int dim = 1000;

int test;
int nr_tests = 10;

float min_elem = FLT_MIN;
float max_elem = FLT_MAX;

ofstream file;

default_random_engine gen;
uniform_real_distribution<float> d(min_elem, max_elem);

int main(void)
{


	file.open("float-operations-multiple-divisions-test.txt");

	int i = 0;
	int j = 0;

	file << "Min element: " << min_elem << "  Max element: " << max_elem << endl << endl;

	for (int dimension = 500; dimension <= dim; dimension += 100) {
		file << "DIMENSION: " << dimension << endl << endl;

		for (test = 1; test <= nr_tests; test++) {

			float **A = AllocateMatrix(dimension);
			//file << "A: " << endl;
			//PrintMatrix(A, dimension);

			float **B = AllocateMatrix(dimension);
			//file << "B: " << endl;
			//PrintMatrix(B, dimension);


			
			float **C = MatrixMultiply(A, B, dimension);
			//file << "C: " << endl;
			//PrintMatrix(C, dimension);

			DeallocateMatrix(A, dimension);
			DeallocateMatrix(B, dimension);
			DeallocateMatrix(C, dimension);
		}

		file << endl << endl << endl;
	}

	file.close();

	return (0);
}

float **MatrixMultiply(float **A, float **B, int dim)
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
				sum += A[i][k] * B[k][j] / M_PI ;
			}
			C[i][j] = sum ;

		}
	}

	//clock_t end = clock();

	auto end = std::chrono::high_resolution_clock::now();

	auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - beg);

	//file <<  "Total time " << (1.0 * dur.count())  << " seconds" << endl;

	double elapsed_time = MICROS_TO_SECONDS * dur.count();

	file << "Dimension " << dim << " Test: " << test << " Total seconds : " << elapsed_time << endl;

	return(C);
}

void PrintMatrix(float **arr, int dim)
{
	int i, j;
	for (i = 0; i < dim; i++)
	{
		file << "[ ";
		for (j = 0; j < dim; j++)
		{
			printf("%f  ", arr[i][j]);
		}
		file << "]\n";
	}

	file << endl << endl;
}

void DeallocateMatrix(float **arr, int dim) {

	for (int i = 0; i < dim; i++) {
		free(arr[i]);
	}
	free(arr);
}


float** AllocateMatrix(int dim) {

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