#include "settingwidget.h"
#include <QBoxLayout>

SettingWidget::SettingWidget(QWidget *parent) : QWidget(parent)
{
    info = new QCheckBox("INFO");
    error = new QCheckBox("ERROR");
    warning = new QCheckBox("WARN");
    debug = new QCheckBox("DEBUG");
    kanal_1 = new QCheckBox("канал 1");
    kanal_2 = new QCheckBox("канал 2");
    port_cc = new QCheckBox("порт CC");
    port_aa = new QCheckBox("порт AA");
    time = new QCheckBox("время");

    QBoxLayout* typeLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    typeLayout->addWidget(info);
    typeLayout->addWidget(error);
    typeLayout->addWidget(warning);
    typeLayout->addWidget(debug);

    QBoxLayout* rightLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    rightLayout->addLayout(typeLayout);
    rightLayout->addWidget(time);
    //rightLayout->addWidget(text);
    rightLayout->addStretch(1);

    QBoxLayout* leftModeleLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    leftModeleLayout->addWidget(port_cc);
    leftModeleLayout->addStretch(1);

    QBoxLayout* rightModeleLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    rightModeleLayout->addWidget(port_aa);
    rightModeleLayout->addStretch(1);

    QBoxLayout* leftLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    leftLayout->addLayout(leftModeleLayout);
    leftLayout->addLayout(rightModeleLayout);


    QBoxLayout* mainLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);

}
