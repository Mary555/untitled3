#ifndef SETTINGWIDGET_H
#define SETTINGWIDGET_H

#include <QWidget>
#include <QCheckBox>

class SettingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SettingWidget(QWidget *parent = 0);
private:
    QCheckBox *info;
    QCheckBox *error;
    QCheckBox *warning;
    QCheckBox *debug;
    QCheckBox *kanal_1;
    QCheckBox *kanal_2;
    QCheckBox *port_cc;
    QCheckBox *port_aa;
    QCheckBox *time;

signals:

public slots:
};

#endif // SETTINGWIDGET_H
