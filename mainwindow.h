#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QTabWidget>
#include "datadisplay.h"
#include "datawave.h"
#include "statusanalysis.h"
#include "systemoption.h"
#include <QSharedMemory>
#include <QGridLayout>
#include <QTimer>

class MainWindow : public QWidget
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QTabWidget *tabWidget;
    SystemOption *systemOption;
    DataDisplay *dataDisplay;
    DataWave *dataWave;
    StatusAnalysis *statusAnalysis;
    QGridLayout *layout;
    QSharedMemory sharedMemory;
    QTimer *timer;
private slots:
    void dataGet();
};

#endif // MAINWINDOW_H
