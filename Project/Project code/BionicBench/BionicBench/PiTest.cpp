
#include "PiTest.h"
#include <chrono>
#include <iostream>

#define MICROS_TO_SECONDS 0.000001

using namespace std;

PiTest::PiTest(QTextEdit *textEdit, QProgressBar *progressBar)
{
	this->min_nr_terms = 1000000;
	this->max_nr_terms = 5000000;
	this->nr_tests_per_run = 10;

	this->textEdit = textEdit;
	this->progressBar = progressBar;

}

PiTest::PiTest(QTextEdit *textEdit, QProgressBar *progressBar,int min_nr_terms, int max_nr_terms, int nr_tests_per_run)
{
	this->min_nr_terms = min_nr_terms;
	this->max_nr_terms = max_nr_terms;
	this->nr_tests_per_run = nr_tests_per_run;

	this->textEdit = textEdit;
	this->progressBar = progressBar;

}

void PiTest::runTest() {

	this->textEdit->append("Pi Digits Calculation (Leibniz Series)\n \n");
	int progress = 50;
	this->progressBar->setValue(progress);


	for (int terms = this->min_nr_terms; terms <= this->max_nr_terms; terms += 1000000) {

		this->textEdit->append("TERMS: " + QString::number(terms) + " \n") ;

		float avg_elapsed_time = 0.0;
		int pos_elapsed_time_no = 0;

		for (int tests = 0; tests < nr_tests_per_run; tests++) {
			double pi = 0.0;

			auto beg = std::chrono::high_resolution_clock::now();

			for (int i = 0; i < terms; i++) {
				pi += (float)(pow(-1, i)) / (2 * i + 1);
			}

			auto end = std::chrono::high_resolution_clock::now();

			auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - beg);

			double elapsed_time = MICROS_TO_SECONDS * dur.count();

			cout.precision(1000);

			//cout << "Test: " << tests << " Pi: " << pi * 4 << endl << " Total seconds : " << elapsed_time << endl << endl;

			if (elapsed_time > 0.0) {
				avg_elapsed_time += elapsed_time;
				pos_elapsed_time_no++;
			}

		}

		avg_elapsed_time /= pos_elapsed_time_no;

		textEdit->append("Avg elapsed time: " + QString::number(avg_elapsed_time) + " seconds \n");
		
		this->results.push_back(avg_elapsed_time);

		progress += 10;
		this->progressBar->setValue(progress);

		textEdit->append(" \n");

	}

}


PiTest::~PiTest()
{
}
