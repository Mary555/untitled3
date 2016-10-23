#include <QApplication>
#include <QWidget>
#include <QBoxLayout>
#include <QtGui>
#include <QTextEdit>
#include <QPushButton>

#include "verymainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VeryMainWindow mainwindow;
    mainwindow.show();


    return a.exec();
}
