/********************************************************************************
** Form generated from reading UI file 'BionicBench.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIONICBENCH_H
#define UI_BIONICBENCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BionicBenchClass
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tabProfile;
    QWidget *tabTests;
    QProgressBar *dataProgressBar;
    QProgressBar *floatProgressBar;
    QLabel *label;
    QLabel *floatTitleLabel;
    QPushButton *intStartButton;
    QPushButton *floatStartButton;
    QLabel *intTitleLabel;
    QPushButton *startButton;
    QProgressBar *intProgressBar;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *FloatingPointOperationTest;
    QScrollArea *floatScrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QTextEdit *floatTextEdit;
    QPushButton *dataStartButton;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *DataTransferOperationTest;
    QScrollArea *dataScrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QTextEdit *dataTextEdit;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *IntegerOperationTest;
    QScrollArea *intScrollArea;
    QWidget *scrollAreaWidgetContents;
    QTextEdit *intTextEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BionicBenchClass)
    {
        if (BionicBenchClass->objectName().isEmpty())
            BionicBenchClass->setObjectName(QString::fromUtf8("BionicBenchClass"));
        BionicBenchClass->resize(1329, 859);
        centralWidget = new QWidget(BionicBenchClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1321, 781));
        tabProfile = new QWidget();
        tabProfile->setObjectName(QString::fromUtf8("tabProfile"));
        tabWidget->addTab(tabProfile, QString());
        tabTests = new QWidget();
        tabTests->setObjectName(QString::fromUtf8("tabTests"));
        dataProgressBar = new QProgressBar(tabTests);
        dataProgressBar->setObjectName(QString::fromUtf8("dataProgressBar"));
        dataProgressBar->setGeometry(QRect(910, 440, 341, 23));
        dataProgressBar->setValue(24);
        floatProgressBar = new QProgressBar(tabTests);
        floatProgressBar->setObjectName(QString::fromUtf8("floatProgressBar"));
        floatProgressBar->setGeometry(QRect(460, 440, 341, 23));
        floatProgressBar->setValue(24);
        label = new QLabel(tabTests);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(910, 80, 301, 10));
        label->setAlignment(Qt::AlignCenter);
        floatTitleLabel = new QLabel(tabTests);
        floatTitleLabel->setObjectName(QString::fromUtf8("floatTitleLabel"));
        floatTitleLabel->setGeometry(QRect(460, 80, 301, 20));
        floatTitleLabel->setAlignment(Qt::AlignCenter);
        intStartButton = new QPushButton(tabTests);
        intStartButton->setObjectName(QString::fromUtf8("intStartButton"));
        intStartButton->setGeometry(QRect(110, 40, 93, 28));
        floatStartButton = new QPushButton(tabTests);
        floatStartButton->setObjectName(QString::fromUtf8("floatStartButton"));
        floatStartButton->setGeometry(QRect(560, 40, 93, 28));
        intTitleLabel = new QLabel(tabTests);
        intTitleLabel->setObjectName(QString::fromUtf8("intTitleLabel"));
        intTitleLabel->setGeometry(QRect(10, 80, 301, 20));
        intTitleLabel->setAlignment(Qt::AlignCenter);
        startButton = new QPushButton(tabTests);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(530, 540, 181, 61));
        intProgressBar = new QProgressBar(tabTests);
        intProgressBar->setObjectName(QString::fromUtf8("intProgressBar"));
        intProgressBar->setGeometry(QRect(10, 440, 341, 23));
        intProgressBar->setValue(24);
        verticalLayoutWidget_2 = new QWidget(tabTests);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(460, 100, 301, 341));
        FloatingPointOperationTest = new QVBoxLayout(verticalLayoutWidget_2);
        FloatingPointOperationTest->setSpacing(6);
        FloatingPointOperationTest->setContentsMargins(11, 11, 11, 11);
        FloatingPointOperationTest->setObjectName(QString::fromUtf8("FloatingPointOperationTest"));
        FloatingPointOperationTest->setContentsMargins(0, 0, 0, 0);
        floatScrollArea = new QScrollArea(verticalLayoutWidget_2);
        floatScrollArea->setObjectName(QString::fromUtf8("floatScrollArea"));
        floatScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 297, 337));
        floatTextEdit = new QTextEdit(scrollAreaWidgetContents_2);
        floatTextEdit->setObjectName(QString::fromUtf8("floatTextEdit"));
        floatTextEdit->setGeometry(QRect(0, 0, 301, 341));
        floatScrollArea->setWidget(scrollAreaWidgetContents_2);

        FloatingPointOperationTest->addWidget(floatScrollArea);

        dataStartButton = new QPushButton(tabTests);
        dataStartButton->setObjectName(QString::fromUtf8("dataStartButton"));
        dataStartButton->setGeometry(QRect(1010, 40, 93, 28));
        verticalLayoutWidget_3 = new QWidget(tabTests);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(910, 100, 301, 341));
        DataTransferOperationTest = new QVBoxLayout(verticalLayoutWidget_3);
        DataTransferOperationTest->setSpacing(6);
        DataTransferOperationTest->setContentsMargins(11, 11, 11, 11);
        DataTransferOperationTest->setObjectName(QString::fromUtf8("DataTransferOperationTest"));
        DataTransferOperationTest->setContentsMargins(0, 0, 0, 0);
        dataScrollArea = new QScrollArea(verticalLayoutWidget_3);
        dataScrollArea->setObjectName(QString::fromUtf8("dataScrollArea"));
        dataScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 297, 337));
        dataTextEdit = new QTextEdit(scrollAreaWidgetContents_3);
        dataTextEdit->setObjectName(QString::fromUtf8("dataTextEdit"));
        dataTextEdit->setGeometry(QRect(-7, 0, 311, 341));
        dataScrollArea->setWidget(scrollAreaWidgetContents_3);

        DataTransferOperationTest->addWidget(dataScrollArea);

        verticalLayoutWidget_4 = new QWidget(tabTests);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 100, 301, 341));
        IntegerOperationTest = new QVBoxLayout(verticalLayoutWidget_4);
        IntegerOperationTest->setSpacing(6);
        IntegerOperationTest->setContentsMargins(11, 11, 11, 11);
        IntegerOperationTest->setObjectName(QString::fromUtf8("IntegerOperationTest"));
        IntegerOperationTest->setContentsMargins(0, 0, 0, 0);
        intScrollArea = new QScrollArea(verticalLayoutWidget_4);
        intScrollArea->setObjectName(QString::fromUtf8("intScrollArea"));
        intScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 297, 337));
        intTextEdit = new QTextEdit(scrollAreaWidgetContents);
        intTextEdit->setObjectName(QString::fromUtf8("intTextEdit"));
        intTextEdit->setGeometry(QRect(0, 0, 301, 341));
        intScrollArea->setWidget(scrollAreaWidgetContents);

        IntegerOperationTest->addWidget(intScrollArea);

        tabWidget->addTab(tabTests, QString());
        BionicBenchClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BionicBenchClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1329, 26));
        BionicBenchClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BionicBenchClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        BionicBenchClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(BionicBenchClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        BionicBenchClass->setStatusBar(statusBar);

        retranslateUi(BionicBenchClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(BionicBenchClass);
    } // setupUi

    void retranslateUi(QMainWindow *BionicBenchClass)
    {
        BionicBenchClass->setWindowTitle(QApplication::translate("BionicBenchClass", "BionicBench", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabProfile), QApplication::translate("BionicBenchClass", "PC Profile", nullptr));
        label->setText(QApplication::translate("BionicBenchClass", "Data Transfer Stress Test", nullptr));
        floatTitleLabel->setText(QApplication::translate("BionicBenchClass", "Floating Point Stress Test", nullptr));
        intStartButton->setText(QApplication::translate("BionicBenchClass", "Run", nullptr));
        floatStartButton->setText(QApplication::translate("BionicBenchClass", "Run", nullptr));
        intTitleLabel->setText(QApplication::translate("BionicBenchClass", "Integer Operation Stress Test", nullptr));
        startButton->setText(QApplication::translate("BionicBenchClass", "Run All Tests", nullptr));
        dataStartButton->setText(QApplication::translate("BionicBenchClass", "Run", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabTests), QApplication::translate("BionicBenchClass", "Stress Tests", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BionicBenchClass: public Ui_BionicBenchClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIONICBENCH_H
