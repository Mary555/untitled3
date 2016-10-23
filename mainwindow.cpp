#include <QBoxLayout>
#include <QtGui>
#include <QListWidget>
#include <QCheckBox>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QPushButton>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{

    trass = new QListWidget();

    info = new QCheckBox("INFO");
    connect(info, SIGNAL(stateChanged(int)), this, SLOT(changeState()));
    error = new QCheckBox("ERROR");
    connect(error, SIGNAL(stateChanged(int)), this, SLOT(changeState()));
    warning = new QCheckBox("WARN");
    connect(warning, SIGNAL(stateChanged(int)), this, SLOT(changeState()));
    debug = new QCheckBox("DEBUG");
    connect(debug, SIGNAL(stateChanged(int)), this, SLOT(changeState()));
    kanal_1 = new QCheckBox("канал 1");
    connect(kanal_1, SIGNAL(stateChanged(int)), this, SLOT(changeState()));
    kanal_2 = new QCheckBox("канал 2");
    connect(kanal_2, SIGNAL(stateChanged(int)), this, SLOT(changeState()));
    port_cc = new QCheckBox("порт CC");
    connect(port_cc, SIGNAL(stateChanged(int)), this, SLOT(changeState()));
    port_aa = new QCheckBox("порт AA");
    connect(port_aa, SIGNAL(stateChanged(int)), this, SLOT(changeState()));
    time = new QCheckBox("время");


    QBoxLayout* rightLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    rightLayout->addWidget(info);
    rightLayout->addWidget(error);
    rightLayout->addWidget(warning);
    rightLayout->addWidget(debug);
    rightLayout->addWidget(kanal_1);
    rightLayout->addWidget(kanal_2);
    rightLayout->addWidget(port_cc);
    rightLayout->addWidget(port_aa);
    rightLayout->addWidget(time);

    QBoxLayout* mainLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    mainLayout->addWidget(trass,1);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);
}

void MainWindow::addLines(QList<itemLine> Lines)
{
    this->Lines = Lines;
    for(int i = 0; i < Lines.length(); i++)
    {
        trass->addItem(Lines.at(i).line);
    }
}

void MainWindow::clearLines()
{
    trass->clear();
}

void MainWindow::changeState()
{
    trass->clear();
    if (!info->isChecked() && !error->isChecked() && !warning->isChecked()
            && !debug->isChecked() && !kanal_1->isChecked() && !kanal_2->isChecked()
            && !port_cc->isChecked() && !port_aa->isChecked() && !time->isChecked())
    {
        for(int i = 0; i < Lines.length(); i++)
        {
            trass->addItem(Lines.at(i).line);
        }
    }
    else
    {
        for(int i = 0; i < Lines.length(); i++)
        {
            itemLine item = Lines.at(i);
            if (info->isChecked() && item.typeMessage == INFO)
            {
                 trass->addItem(item.line);
            }
            if (error->isChecked() && item.typeMessage == EROR)
            {
                 trass->addItem(item.line);
            }
            if (warning->isChecked() && item.typeMessage == WARNING)
            {
                 trass->addItem(item.line);
            }
            if (debug->isChecked() && item.typeMessage == DEBUG)
            {
                 trass->addItem(item.line);
            }
            if (kanal_1->isChecked() && item.channel)
            {
                if(item.channel == 1)
                {
                 trass->addItem(item.line);
                }
            }
            if (kanal_2->isChecked() && item.channel)
            {
                if(item.channel == 2)
                {
                 trass->addItem(item.line);
                }
            }
            if (port_cc->isChecked() && item.port_CC)
            {
                 trass->addItem(item.line);
            }
            if (port_aa->isChecked() && item.port_AA)
            {
                 trass->addItem(item.line);
            }
        }
    }
}
