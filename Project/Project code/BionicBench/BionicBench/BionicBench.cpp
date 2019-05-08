#include "BionicBench.h"

BionicBench::BionicBench(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// initializing progress bars

	ui.dataProgressBar->setMaximum(100);
	ui.dataProgressBar->setMinimum(0);
	ui.dataProgressBar->setValue(0);

	ui.intProgressBar->setMaximum(100);
	ui.intProgressBar->setMinimum(0);
	ui.intProgressBar->setValue(0);
	

	ui.floatProgressBar->setMaximum(100);
	ui.floatProgressBar->setMinimum(0);
	ui.floatProgressBar->setValue(0);


	// making text edits read only
	ui.intTextEdit->setReadOnly(true);
	ui.floatTextEdit->setReadOnly(true);
	ui.dataTextEdit->setReadOnly(true);


	// Connecting SLOTS & SIGNALS
	connect(ui.startButton, SIGNAL(clicked()), this, SLOT(runAllTests()));
	connect(ui.intStartButton, SIGNAL(clicked()), this, SLOT(runIntegerOpTest()));
	connect(ui.floatStartButton, SIGNAL(clicked()), this, SLOT(runFloatingPointOpTest()));
	connect(ui.dataStartButton, SIGNAL(clicked()), this, SLOT(runDataTransferTest()));

	QPixmap bkgnd("cyber.png");
	bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;

	palette.setBrush(QPalette::Background, bkgnd);
	this->setPalette(palette);

	//this->setWindowOpacity(0);
	//ui.tabWidget->setWindowOpacity(0);
/*
	ui.tabWidget->setStyleSheet("background-color:transparent;");
	ui.tabTests->setStyleSheet("background-color:transparent;");
	ui.tabProfile->setStyleSheet("background-color:transparent;");*/


	/*ui.tabWidget->setWindowOpacity(0);
	ui.tabTests->setWindowOpacity(0);
	ui.tabProfile->setWindowOpacity(0);
*/
}



void BionicBench::resetTests() {

	ui.intTextEdit->clear();
	ui.floatTextEdit->clear();
	ui.dataTextEdit->clear();

	ui.intProgressBar->setValue(0);
	ui.floatProgressBar->setValue(0);
	ui.dataProgressBar->setValue(0);

}


void BionicBench::runAllTests() {

	resetTests();

	runIntegerOpTest();
	runFloatingPointOpTest();

	/*ui.intTextEdit->clear();
	ui.intProgressBar->setValue(0);

	IntegerMatrixMulTest intMatMulTest(ui.intTextEdit, ui.intProgressBar);
	intMatMulTest.runTest();

	ui.floatTextEdit->clear();
	ui.floatProgressBar->setValue(0);

	FloatingMatrixMulTest floatMatMulTest(ui.floatTextEdit, ui.floatProgressBar);
	floatMatMulTest.runTest();

	PiTest piTest(ui.floatTextEdit, ui.floatProgressBar);
	piTest.runTest();*/

	
}

void BionicBench::runIntegerOpTest() {

	ui.intTextEdit->clear();
	ui.intProgressBar->setValue(0);

	IntegerMatrixMulTest intMatMulTest(ui.intTextEdit, ui.intProgressBar);
	intMatMulTest.runTest();

}

void BionicBench::runFloatingPointOpTest() {

	ui.floatTextEdit->clear();
	ui.floatProgressBar->setValue(0);

	FloatingMatrixMulTest floatMatMulTest(ui.floatTextEdit, ui.floatProgressBar);
	floatMatMulTest.runTest();

	PiTest piTest(ui.floatTextEdit, ui.floatProgressBar);
	piTest.runTest();


}

void BionicBench::runDataTransferTest() {

	ui.dataTextEdit->clear();
	ui.dataProgressBar->setValue(0);

}
