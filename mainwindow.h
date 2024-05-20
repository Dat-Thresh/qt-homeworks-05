#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private Q_SLOTS:
    void pb_StartStop_clicked(bool checked = false);
    void lb_time_update();
    void pb_circle_pressed();
    void pb_clearText_pressed();
private:
    Ui::MainWindow *ui;

    stopwatch* stopwatch_obj;

    QString convert_msec_to_clock_view(QElapsedTimer* timer);



};
#endif // MAINWINDOW_H
