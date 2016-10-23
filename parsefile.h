#ifndef PARSEFILE_H
#define PARSEFILE_H

#include <QObject>
#include <QList>

enum TypeMessage
{
    INFO,
    WARNING,
    DEBUG,
    EROR,
    NONE
};

struct itemLine
{
    int channel;
    bool port_AA;
    bool port_CC;
    TypeMessage typeMessage;
    QString line;
};

class ParseFile : public QObject
{
    Q_OBJECT
public:
    explicit ParseFile(QObject *parent = 0);

private:
    //QList<QString> list;


    void read(QString);
    itemLine parse(QString);

signals:
    void sendLines(QList<itemLine>);
    void clear();

public slots:
    void open();

};

#endif // PARSEFILE_H
