
#pragma once
#include <vector>


using namespace std;


class PiTest
{
	public:
		PiTest();
		PiTest(int min_nr_terms, int max_nr_terms, int nr_tests_per_run);
		~PiTest();

		int min_nr_terms;
		int max_nr_terms;
		int nr_tests_per_run;
		vector<float> results;

		void runTest();

		

	

};

