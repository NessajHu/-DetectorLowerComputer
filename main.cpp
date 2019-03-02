#include "mainwindow.h"
#include <QApplication>
#include "keyboard.h"
#include <QFont>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    a.setFont(QFont("Microsoft YaHei", 15));
    //Keyboard t;
    //t.show();
    w.showFullScreen();
    //w.show();
    
    return a.exec();
}
