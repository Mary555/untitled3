#ifndef VERYMAINWINDOW_H
#define VERYMAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include "parsefile.h"

class VeryMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit VeryMainWindow(QWidget *parent = 0);
    ~VeryMainWindow();

private:
    ParseFile *file;
    QListWidget *trass;


signals:

public slots:
};

#endif // VERYMAINWINDOW_H
