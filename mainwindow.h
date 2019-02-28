#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QTabWidget>
#include "datadisplay.h"
#include "datawave.h"
#include "statusanalysis.h"
#include "systemoption.h"
#include <QGridLayout>

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
};

#endif // MAINWINDOW_H
