#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QTimer>
#include <QElapsedTimer>
#include <QString>

class stopwatch
{

private:

    QElapsedTimer* el_timer;
    QElapsedTimer* lapse_timer;
    int lapse_number=1;

     QString convert_msec_to_clock_view(QElapsedTimer* timer);
public:
     QTimer* main_timer;
     stopwatch();

    ~stopwatch(){
        delete el_timer;
        delete lapse_timer;
        delete main_timer;
    }

    QTimer* Get_main_timer();

    void press_start();
    void press_stop_circle_zero();
    int Get_lapse();
    void clear_all();
    void lapse_restart_and_incr();
    void reset_timer();
    QString HowMuchOnWatch();
    QString HowMuchOnLapse();

};

#endif // STOPWATCH_H
