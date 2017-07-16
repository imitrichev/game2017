#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    x=2;
    y=x;
    window = new QWidget;
    window->setWindowTitle("GAME!");

    for (int i=0; i<x*y; i++)
    {
        buttons.push_back(QSharedPointer<QPushButton>(new QPushButton("")));
        (*buttons.last()).setObjectName(QString::number(i));
    }
    for (int i=0; i<buttons.size(); i++)
    {
        connect(&(*buttons[i]), SIGNAL(clicked()), this, SLOT(changeAlive()));
    }
    layout = new QGridLayout;

    window->setMinimumSize(100,100);
    //window->setMaximumSize(1200,700);
    for (int i=0; i<x; i++)
        for (int j=0; j<y; j++)
            layout->addWidget(&(*buttons[i*x+j]),i,j);
    window->setLayout(layout);
    window->show();
}

Widget::~Widget()
{
    while (QWidget* w = findChild<QWidget*>())
        delete w;
}
