#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_BionicBench.h"

#include "FloatingMatrixMulTest.h"
#include "IntegerMatrixMulTest.h"
#include "PiTest.h"

class BionicBench : public QMainWindow
{
	Q_OBJECT

public:
	BionicBench(QWidget *parent = Q_NULLPTR);
	void resetTests();


private:
	Ui::BionicBenchClass ui;

private slots:
	void runAllTests();
	void runIntegerOpTest();
	void runFloatingPointOpTest();
	void runDataTransferTest();
};
