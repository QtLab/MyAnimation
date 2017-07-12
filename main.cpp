#include "myanimation.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyAnimation w;
    w.show();

    return a.exec();
}
