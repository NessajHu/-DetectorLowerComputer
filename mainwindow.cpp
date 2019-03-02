#include "mainwindow.h"
#include <QBuffer>
#include <QDataStream>
#include <cstring>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    tabWidget(new QTabWidget(this)),
    systemOption(new SystemOption(tabWidget)),
    dataDisplay(new DataDisplay(tabWidget)),
    dataWave(new DataWave(tabWidget)),
    statusAnalysis(new StatusAnalysis(tabWidget)),
    layout(new QGridLayout(this)),
    timer(new QTimer(this))
{
    QSharedMemory sharedMemory("shared");
    tabWidget->setTabPosition(QTabWidget::West);
    layout->addWidget(tabWidget, 0, 0, 1, 1);
    tabWidget->addTab(systemOption, "Option");
    tabWidget->addTab(dataDisplay, "Display");
    tabWidget->addTab(dataWave, "Wave");
    tabWidget->addTab(statusAnalysis, "Status");
    QObject::connect(timer, &QTimer::timeout, this, &MainWindow::dataGet);
    timer->start(3000);
    QObject::connect(dataDisplay, &DataDisplay::nodeChanged, dataWave, &DataWave::nodeChanged);
    sharedMemory.create(1000);
}

void MainWindow::dataGet()
{
    if(!sharedMemory.attach())
        return;
    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);
    QDataStream in(&buffer);
    QString data;
    sharedMemory.lock();
    buffer.setData(static_cast<char *>(const_cast<void *>(sharedMemory.constData())), sharedMemory.size());
    in >> data;
    in << "";
    char *to = static_cast<char*>(sharedMemory.data());
    const char *from = buffer.data().data();
    std::memcpy(to, from, static_cast<size_t>(buffer.size()));
    sharedMemory.unlock();
    sharedMemory.detach();
    if(data != QString(""))
    {
        dataWave->getData(12345, data);
        dataDisplay->getData(12345, data);
    }
}

MainWindow::~MainWindow()
{
    
} 
