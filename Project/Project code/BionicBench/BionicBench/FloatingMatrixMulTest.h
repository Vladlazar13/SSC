#pragma once
#include <vector>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QProgressBar>

using namespace std;

class FloatingMatrixMulTest


{
public:
	FloatingMatrixMulTest(QTextEdit *textEdit, QProgressBar *progressBar);
	FloatingMatrixMulTest(QTextEdit *textEdit, QProgressBar *progressBar,int min_dim, int max_dim, int step, int nr_tests_per_run);


	int min_dim;
	int max_dim;
	int step;
	int nr_tests_per_run;

	QTextEdit *textEdit;
	QProgressBar *progressBar;

	vector<float> results;

	void runTest();
	float MatrixMultiply(float **A, float **B, int dim);
	void DeallocateMatrix(float **arr, int dim);
	float** AllocateMatrix(int dim);

	~FloatingMatrixMulTest();
};

