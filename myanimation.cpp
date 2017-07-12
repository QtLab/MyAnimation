#include "myanimation.h"

#include <QLabel>
#include <QPushButton>
#include <QPropertyAnimation>

MyAnimation::MyAnimation(QWidget *parent)
    : QWidget(parent)
{
    resize(500, 300);

#if 0
    /*  声明动画类，并将控制对象 this (this一定是继承自QObject的窗口部件)  以及属性名 "geometry" 传入构造函数  */
    QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
    /*  设置动画持续时长为 2 秒钟  */
    animation->setDuration(2000);
    /*  设置动画的起始状态 起始点 (1,2)  起始大小 (3,4)  */
    animation->setStartValue(QRect(1, 2, 300, 400));
    /*  设置动画的结束状态 结束点 (100,200)  结束大小 (300,400)  */
    animation->setEndValue(QRect(100, 200, 300, 400));
    /*  设置动画效果  */
    animation->setEasingCurve(QEasingCurve::CosineCurve);
    /*  开始执行动画 QAbstractAnimation::DeleteWhenStopped 动画结束后进行自清理(效果就好像智能指针里的自动delete animation) */
    animation->start(QAbstractAnimation::DeleteWhenStopped);
#endif

    QPushButton *btn_start = new QPushButton(tr("开始"), this);
    btn_start->setGeometry(10,10,50,25);
    QPushButton *btn_stop = new QPushButton(tr("停止"), this);
    btn_stop->setGeometry(65,10,50,25);
    QLabel *label = new QLabel(tr("<font color='red'>hello world!</font>"), this);
    label->setGeometry(200, 130, 80, 20);
    label->setMinimumWidth(80);

    QPropertyAnimation* animation = new QPropertyAnimation(label, "geometry");
    animation->setDuration(2000);
    animation->setStartValue(QRect(50, 30, 30, 20));
    animation->setEndValue(QRect(300, 270, 30, 20));
    animation->setEasingCurve(QEasingCurve::CosineCurve);
    animation->setLoopCount(-1);        //一直运行，直到stop

    connect(btn_start, SIGNAL(clicked(bool)), animation, SLOT(start()));
    connect(btn_stop, SIGNAL(clicked(bool)), animation, SLOT(stop()));
}

MyAnimation::~MyAnimation()
{

}
