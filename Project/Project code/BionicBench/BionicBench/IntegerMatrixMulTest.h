#pragma once
#include <vector>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QProgressBar>

using namespace std;

class IntegerMatrixMulTest
{
public:
	IntegerMatrixMulTest(QTextEdit *textEdit, QProgressBar *progressBar);
	IntegerMatrixMulTest(QTextEdit *textEdit, QProgressBar *progressBar,int min_dim, int max_dim, int step, int nr_tests_per_run);


	int min_dim;
	int max_dim;
	int step;
	int nr_tests_per_run;

	QTextEdit *textEdit;
	QProgressBar *progressBar;

	vector<float> results;

	void runTest();
	float MatrixMultiply(int **A, int **B, int dim);
	int** AllocateMatrix(int dim);
	void DeallocateMatrix(int **arr, int dim);

	~IntegerMatrixMulTest();
};

