#include "verymainwindow.h"
#include "settingwidget.h"
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QTabWidget>
#include "parsefile.h"

VeryMainWindow::VeryMainWindow(QWidget *parent) : QMainWindow(parent)
{
    SettingWidget* mainWindow = new SettingWidget(this);

    QTabWidget* tab = new QTabWidget;
    trass = new QListWidget;
    tab->addTab(trass, tr("log"));
    tab->addTab(mainWindow, tr("Настройки"));
    setCentralWidget(tab);

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
