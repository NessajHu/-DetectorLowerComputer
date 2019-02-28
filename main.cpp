#include "mainwindow.h"
#include <QApplication>
#include "keyboard.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //Keyboard t;
    //t.show();
    w.showFullScreen();
    //w.show();
    
    return a.exec();
}
