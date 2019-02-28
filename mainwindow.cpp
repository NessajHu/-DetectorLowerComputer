#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    tabWidget(new QTabWidget(this)),
    systemOption(new SystemOption(tabWidget)),
    dataDisplay(new DataDisplay(tabWidget)),
    dataWave(new DataWave(tabWidget)),
    statusAnalysis(new StatusAnalysis(tabWidget)),
    layout(new QGridLayout(this))
{
    layout->addWidget(tabWidget, 0, 0, 1, 1);
    tabWidget->addTab(systemOption, "Option");
    tabWidget->addTab(dataDisplay, "Display");
    tabWidget->addTab(dataWave, "Wave");
    tabWidget->addTab(statusAnalysis, "Status");
    QObject::connect(systemOption->getServer(), &TcpServer::sendData, dataWave, &DataWave::getData);
    QObject::connect(systemOption->getServer(), &TcpServer::sendData, dataDisplay, &DataDisplay::getData);
    QObject::connect(dataDisplay, &DataDisplay::nodeChanged, dataWave, &DataWave::nodeChanged);
}

MainWindow::~MainWindow()
{
    
}
