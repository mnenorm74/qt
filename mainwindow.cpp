#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QPushButton>
#include <QObject>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget *w1 = new QWidget();
    setCentralWidget(w1);

    //-------------
    //   Слайдеры
    //-------------
    firstSlider = new QSlider(Qt::Horizontal);
    firstSlider->setRange(0, 100);
    connect(firstSlider, SIGNAL(valueChanged(int)), this, SLOT(SaveSettings()));
    secondSlider = new QSlider(Qt::Horizontal);
    secondSlider->setRange(0, 100);
    connect(secondSlider, SIGNAL(valueChanged(int)), this, SLOT(SaveSettings()));
    thirdSlider = new QSlider(Qt::Horizontal);
    thirdSlider->setRange(0, 100);
    connect(thirdSlider, SIGNAL(valueChanged(int)), this, SLOT(SaveSettings()));
    restoreSettings();

    //------------
    //    Кнопки
    //------------
    QPushButton *firstMinButton = new QPushButton("min");
    connect(firstMinButton, SIGNAL(clicked()), this, SLOT(SetFirstMinValue()));
    QPushButton *firstMaxButton = new QPushButton("max");
    connect(firstMaxButton, SIGNAL(clicked()), this,  SLOT(SetFirstMaxValue()));
    QPushButton *secondMinButton = new QPushButton("min");
    connect(secondMinButton, SIGNAL(clicked()), this, SLOT(SetSecondMinValue()));
    QPushButton *secondMaxButton = new QPushButton("max");
    connect(secondMaxButton, SIGNAL(clicked()), this,  SLOT(SetSecondMaxValue()));
    QPushButton *thirdMinButton = new QPushButton("min");
    connect(thirdMinButton, SIGNAL(clicked()), this, SLOT(SetThirdMinValue()));
    QPushButton *thirdMaxButton = new QPushButton("max");
    connect(thirdMaxButton, SIGNAL(clicked()), this,  SLOT(SetThirdMaxValue()));

    //--------
    //   layout
    //--------
    QGridLayout *layout = new QGridLayout();
    layout -> addWidget(firstSlider, 0, 0, 1, 2);
    layout -> addWidget(firstMinButton, 1, 0, Qt::AlignCenter);
    layout -> addWidget(firstMaxButton, 1, 1, Qt::AlignCenter);
    layout -> addWidget(secondSlider, 2, 0, 1, 2);
    layout -> addWidget(secondMinButton, 3, 0, Qt::AlignCenter);
    layout -> addWidget(secondMaxButton, 3, 1, Qt::AlignCenter);
    layout -> addWidget(thirdSlider, 4, 0, 1, 2);
    layout -> addWidget(thirdMinButton, 5, 0, Qt::AlignCenter);
    layout -> addWidget(thirdMaxButton, 5, 1, Qt::AlignCenter);

    w1 -> setLayout(layout);
    w1 ->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SaveSettings()
{
    QSettings settings (ORGANIZATION_NAME, APP_NAME);
    settings.beginGroup("MainWindow");
    settings.setValue("firstValue", firstSlider->value());
    settings.setValue("secondValue", secondSlider->value());
    settings.setValue("thirdValue", thirdSlider->value());
    settings.endGroup();
    settings.sync();
}

void MainWindow::restoreSettings()
{
    QSettings settings (ORGANIZATION_NAME, APP_NAME);
    settings.beginGroup("MainWindow");
    int firstValue = settings.value("firstValue", 0).toInt();
    int secondValue = settings.value("secondValue", 0).toInt();
    int thirdValue = settings.value("thirdValue", 0).toInt();
    firstSlider->setValue(firstValue);
    secondSlider->setValue(secondValue);
    thirdSlider->setValue(thirdValue);
    settings.endGroup();
}

void MainWindow::SetFirstMinValue()
{
    firstSlider->setValue(0);
}

void MainWindow::SetFirstMaxValue()
{
    firstSlider->setValue(100);
}

void MainWindow::SetSecondMinValue()
{
    secondSlider->setValue(0);
}

void MainWindow::SetSecondMaxValue()
{
    secondSlider->setValue(100);
}

void MainWindow::SetThirdMinValue()
{
    thirdSlider->setValue(0);
}

void MainWindow::SetThirdMaxValue()
{
    thirdSlider->setValue(100);
}



