#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void changeAlive(){
        QObject *senderObj = sender();
        int i = senderObj->objectName().toInt();
        (*buttons[i]).setText(is_alive(*buttons[i])?"":"*");
    }

private:
    QWidget *window;
    QGridLayout *layout;
    QVector<QSharedPointer<QPushButton> > buttons;
    int x, y;

    bool is_alive(const QPushButton & _but) const
    {
        if (_but.text()!="")
            return true;
        return false;
    }
};

#endif // WIDGET_H
