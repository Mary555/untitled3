#include "verymainwindow.h"
#include "mainwindow.h"
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include "parsefile.h"

VeryMainWindow::VeryMainWindow(QWidget *parent) : QMainWindow(parent)
{
    MainWindow* mainWindow = new MainWindow(this);
    setCentralWidget(mainWindow);

    file = new ParseFile();
    connect(file, SIGNAL(sendLines(QList<itemLine>)), mainWindow, SLOT(addLines(QList<itemLine>)));
    connect(file, SIGNAL(clear()), mainWindow, SLOT(clearLines()));
    QMenu *fileMenu = new QMenu("&File");
    QAction *openFile = new QAction("&Open");
    fileMenu->addAction(openFile);
    connect(openFile, SIGNAL(triggered()), file, SLOT(open()));
    menuBar()->addMenu(fileMenu);
}

VeryMainWindow::~VeryMainWindow()
{
    delete file;
}
