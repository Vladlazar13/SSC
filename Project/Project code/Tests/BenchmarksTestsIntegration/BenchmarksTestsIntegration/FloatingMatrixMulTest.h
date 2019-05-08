#pragma once
#include <vector>
#include <iostream>

using namespace std;

class FloatingMatrixMulTest


{
public:
	FloatingMatrixMulTest();
	FloatingMatrixMulTest(int min_dim, int max_dim, int step, int nr_tests_per_run);


	int min_dim;
	int max_dim;
	int step;
	int nr_tests_per_run;


	vector<float> results;

	void runTest();
	float MatrixMultiply(float **A, float **B, int dim);
	void DeallocateMatrix(float **arr, int dim);
	float** AllocateMatrix(int dim);

	~FloatingMatrixMulTest();
};

