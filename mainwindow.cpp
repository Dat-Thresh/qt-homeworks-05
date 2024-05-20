#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pb_StartStop->setText("Старт");
    ui->pb_StartStop->setCheckable(true);
    ui->pb_SetCircle->setDisabled(true);
    ui->lb_Time->setText("00:00:00");

    stopwatch_obj = new stopwatch();

    //переписать как коннект к методам
    connect(ui->pb_StartStop, &QPushButton::clicked, this, &MainWindow::pb_StartStop_clicked);
    connect(stopwatch_obj->main_timer, &QTimer::timeout, this, &MainWindow::lb_time_update);
    connect(ui->pb_SetCircle, &QPushButton::pressed, this, &MainWindow::pb_circle_pressed);
    connect(ui->pb_ClearText, &QPushButton::pressed, this, &MainWindow::pb_clearText_pressed);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete stopwatch_obj;

}

//++
void MainWindow::lb_time_update(){
     ui->lb_Time->setText(stopwatch_obj->HowMuchOnWatch());
}

//перенести в стопватч
void MainWindow::pb_StartStop_clicked(bool checked){
    if(checked){
        ui->pb_StartStop->setText("Стоп");
        stopwatch_obj->press_start();
        ui->pb_SetCircle->setDisabled(false);
    }
    else{
        ui->pb_StartStop->setText("Старт");
        stopwatch_obj->press_stop_circle_zero();
        ui->pb_SetCircle->setDisabled(true);

    }
}

//перенести в стопватч +++
void MainWindow::pb_circle_pressed(){
        ui->textB_results->insertPlainText(QString("Круг: %1, Время: ")
                                           .arg(stopwatch_obj->Get_lapse(), 2, 10, QLatin1Char('0'))
                    .append(stopwatch_obj->HowMuchOnLapse()).append("\n"));
        stopwatch_obj->lapse_restart_and_incr();
        qDebug() << "circle clicked!";

}

//содержимое перенести в класс стопватч
void MainWindow::pb_clearText_pressed(){
    ui->lb_Time->setText("00:00:00");
    ui->textB_results->clear();
    stopwatch_obj->clear_all();

}

