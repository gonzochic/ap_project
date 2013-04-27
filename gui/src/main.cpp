#include <QtGui/QApplication>
#include "apgui.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ApGui w;
    w.show();
    
    return a.exec();
}
