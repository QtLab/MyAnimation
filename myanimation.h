#ifndef MYANIMATION_H
#define MYANIMATION_H

#include <QWidget>

class MyAnimation : public QWidget
{
    Q_OBJECT

public:
    MyAnimation(QWidget *parent = 0);
    ~MyAnimation();
};

#endif // MYANIMATION_H
