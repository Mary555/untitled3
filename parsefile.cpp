#include "parsefile.h"
#include <QFileDialog>
#include <QtGui>

ParseFile::ParseFile(QObject *parent) : QObject(parent)
{

}

void ParseFile::open()
{
    QString fileName = QFileDialog::getOpenFileName(0, tr("Открыть"), "",
            tr("Text Files (*.txt)"));
    if (!fileName.isEmpty())
    {
        emit clear();
        read(fileName);
    }
}

void ParseFile::read(QString fileName)
{
    QList<itemLine> list = QList<itemLine>();
    QFile file (fileName);
    if(!file.open(QIODevice::ReadOnly))
    {
        return;
    }
    QTextStream instream(&file);
    QString line;
    while(!instream.atEnd())
    {
        line = instream.readLine();
        list.push_back(parse(line));
    }
    emit sendLines(list);
}

itemLine ParseFile::parse(QString line)
{
    itemLine item;
    QStringList allWords = line.split(" ");

    QString nam = allWords.at(2);
    bool ok;
    item.channel = nam.toInt(&ok,10);

    QString ch = allWords.at(3);
    item.port_AA = ch.indexOf("AA") != -1;
    item.port_CC = ch.indexOf("CC") != -1;



    QString iwde = allWords.at(4);
    if (iwde == "Info:")
    {
        item.typeMessage = INFO;
    } else if (iwde == "Error:")
    {
        item.typeMessage = EROR;
    } else if (iwde == "Warning:")
    {
        item.typeMessage = WARNING;
    } else if (iwde == "Debug:")
    {
        item.typeMessage = DEBUG;
    }
    else
    {
        item.typeMessage = NONE;
    }

    item.line = line;
    return item;
}
