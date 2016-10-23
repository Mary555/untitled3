#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QLabel>
#include <QMenuBar>
#include <QTextEdit>
#include <QListWidget>
#include <QCheckBox>
#include "parsefile.h"

class QAction;
class QLabel;
class FindDialog;
class QMenuBar;

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow (QWidget *parent=0);

public slots:
    void addLines(QList<itemLine> Lines);
    void clearLines();
    void changeState();

private:
    QListWidget *trass;
    QCheckBox *info;
    QCheckBox *error;
    QCheckBox *warning;
    QCheckBox *debug;
    QCheckBox *kanal_1;
    QCheckBox *kanal_2;
    QCheckBox *port_cc;
    QCheckBox *port_aa;
    QCheckBox *time;
    QList<itemLine> Lines;



};

#endif // MAINWINDOW_H
