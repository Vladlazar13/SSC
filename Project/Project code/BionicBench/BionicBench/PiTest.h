
#pragma once
#include <vector>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QProgressBar>


using namespace std;


class PiTest
{
	public:
		PiTest(QTextEdit *textEdit, QProgressBar *progressBar);
		PiTest(QTextEdit *textEdit, QProgressBar *progressBar, int min_nr_terms, int max_nr_terms, int nr_tests_per_run);
		~PiTest();

		int min_nr_terms;
		int max_nr_terms;
		int nr_tests_per_run;

		QTextEdit *textEdit;
		QProgressBar *progressBar;

		vector<float> results;

		void runTest();

};

