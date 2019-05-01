#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSlider>
#include <QMainWindow>
#include <QSettings>
#include "config.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
     QSlider *firstSlider;
     QSlider *secondSlider;
     QSlider *thirdSlider;

private slots:
    void SetFirstMinValue();
    void SetFirstMaxValue();
    void SetSecondMinValue();
    void SetSecondMaxValue();
    void SetThirdMinValue();
    void SetThirdMaxValue();
    void SaveSettings();

private:
    Ui::MainWindow *ui;
    void restoreSettings();
};

#endif // MAINWINDOW_H
