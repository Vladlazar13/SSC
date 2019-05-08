#include "BionicBench.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	BionicBench w;



	w.show();
	return a.exec();
}
