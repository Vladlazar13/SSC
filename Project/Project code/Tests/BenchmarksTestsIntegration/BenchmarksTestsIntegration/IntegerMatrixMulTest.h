#pragma once
#include <vector>

using namespace std;

class IntegerMatrixMulTest
{
public:
	IntegerMatrixMulTest();
	IntegerMatrixMulTest(int min_dim, int max_dim, int step, int nr_tests_per_run);


	int min_dim;
	int max_dim;
	int step;
	int nr_tests_per_run;


	vector<float> results;

	void runTest();
	float MatrixMultiply(int **A, int **B, int dim);
	int** AllocateMatrix(int dim);
	void DeallocateMatrix(int **arr, int dim);

	~IntegerMatrixMulTest();
};

