/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpinBox *spinBox1;
    QSpinBox *spinBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *pushButton_2;
    QWidget *tab;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 650);
        MainWindow->setMinimumSize(QSize(800, 650));
        MainWindow->setMaximumSize(QSize(800, 650));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 800, 650));
        tabWidget->setMinimumSize(QSize(800, 650));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tab_2->setStyleSheet(QString::fromUtf8("QWidget#tab_3 "));
        verticalLayoutWidget = new QWidget(tab_2);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(440, 10, 121, 131));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        spinBox1 = new QSpinBox(verticalLayoutWidget);
        spinBox1->setObjectName(QString::fromUtf8("spinBox1"));
        spinBox1->setCursor(QCursor(Qt::ArrowCursor));
        spinBox1->setStyleSheet(QString::fromUtf8("color:lightgrey;\n"
"border:1px solid black;"));
        spinBox1->setMinimum(0);
        spinBox1->setMaximum(999999);
        spinBox1->setSingleStep(100);

        verticalLayout->addWidget(spinBox1);

        spinBox = new QSpinBox(verticalLayoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setStyleSheet(QString::fromUtf8("color:lightgrey;\n"
"border:1px solid black;"));
        spinBox->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox->setMinimum(1);
        spinBox->setMaximum(9999);

        verticalLayout->addWidget(spinBox);

        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(40, 190, 711, 41));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font: 20pt \"Futura\";\n"
"color: black;\n"
"}"));
        lineEdit->setClearButtonEnabled(true);
        lineEdit_3 = new QLineEdit(tab_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(40, 370, 711, 41));
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font: 20pt \"Futura\";\n"
"color: black;\n"
"}"));
        lineEdit_3->setClearButtonEnabled(true);
        lineEdit_2 = new QLineEdit(tab_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(40, 280, 711, 41));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font: 20pt \"Futura\";\n"
"color: black;\n"
"}"));
        lineEdit_2->setClearButtonEnabled(true);
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 440, 161, 71));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 75 10pt \"Futura\";\n"
"    font-weight: bold;\n"
"    color: rgb(0,0,0);\n"
"    border: 2px solid black; \n"
"    border-radius: 21px;\n"
"    background-color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    font: 75 10pt \"Futura\";\n"
"    font-weight: bold;\n"
"    color: rgb(255, 255, 255);\n"
"    background-color: gray;\n"
"    border: 2px solid black; \n"
"    border-radius: 21px;\n"
"}"));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(230, 150, 231, 41));
        label_4->setStyleSheet(QString::fromUtf8("QLabel#label_4{\n"
"	font: 16pt \"Gill Sans\";\n"
"color: Black;\n"
"}"));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(230, 330, 241, 41));
        label_5->setStyleSheet(QString::fromUtf8("QLabel#label_5{\n"
"	font: 16pt \"Gill Sans\";\n"
"color: Black;\n"
"}"));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(230, 240, 251, 41));
        label_6->setStyleSheet(QString::fromUtf8("QLabel#label_6{\n"
"	font: 16pt \"Gill Sans\";\n"
"color: Black;\n"
"}"));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 530, 721, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Gill Sans"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("QLabel#label_7{\n"
"font: 16pt \"Gill Sans\";\n"
"color: Black;\n"
"}"));
        label_7->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget_2 = new QWidget(tab_2);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 371, 131));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(verticalLayoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setLayoutDirection(Qt::RightToLeft);
        label_8->setStyleSheet(QString::fromUtf8("QLabel#label_8{\n"
"	font: 16pt \"Gill Sans\";\n"
"color: Black;\n"
"}"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_8);

        label_9 = new QLabel(verticalLayoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("QLabel#label_9{\n"
"	font: 16pt \"Gill Sans\";\n"
"color: Black;\n"
"}"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_9);

        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(440, 440, 161, 71));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 75 10pt \"Futura\";\n"
"    font-weight: bold;\n"
"    color: rgb(0,0,0);\n"
"    border: 2px solid black;  /* \320\247\320\265\321\200\320\275\320\260\321\217 \321\200\320\260\320\274\320\272\320\260 */\n"
"    border-radius: 21px;\n"
"    background-color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    font: 75 10pt \"Futura\";\n"
"    font-weight: bold;\n"
"    color: rgb(255, 255, 255);\n"
"    background-color: gray;\n"
"    border: 2px solid black;  /* \320\247\320\265\321\200\320\275\320\260\321\217 \321\200\320\260\320\274\320\272\320\260 */\n"
"    border-radius: 21px;\n"
"}"));
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab->setMinimumSize(QSize(0, 0));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 800, 650));
        label->setMinimumSize(QSize(800, 650));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 800, 650));
        label_2->setMinimumSize(QSize(800, 650));
        tabWidget->addTab(tab, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menubar->setDefaultUp(true);
        menubar->setNativeMenuBar(false);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lineEdit->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\237\321\203\321\202\321\214 \320\272 \321\204\320\260\320\271\320\273\321\203 \321\201 \321\202\320\276\321\207\320\272\320\260\320\274\320\270", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\237\321\203\321\202\321\214 \320\272 \320\262\321\213\321\205\320\276\320\264\320\275\320\276\320\274\321\203 \321\204\320\260\320\271\320\273\321\203", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\237\321\203\321\202\321\214 \320\272 \321\204\320\260\320\273\321\203 \321\201 \320\276\320\261\321\212\320\265\320\272\321\202\320\260\320\274\320\270", nullptr));
        label_7->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 c\320\265\320\274\320\277\320\273\320\276\320\262", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\200\320\260\321\201\321\201\320\274\320\260\321\202\321\200\320\270\320\262\320\260\320\265\320\274\321\213\321\205 \321\202\320\276\321\207\320\265\320\272", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\320\241\321\206\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
