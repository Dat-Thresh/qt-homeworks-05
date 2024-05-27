#include "stopwatch.h"

stopwatch::stopwatch()
{

    el_timer = new QElapsedTimer();
    lapse_timer = new QElapsedTimer();
    main_timer = new QTimer();
    main_timer->setInterval(100);
}

QString stopwatch::convert_msec_to_clock_view(QElapsedTimer* timer){
    int secs = timer->elapsed()/1000;
    int mins = (secs/ 60)% 60;
    int hours = secs / 3600;
    return (QString("%1:%2:%3.%4")
                          .arg(hours, 2, 10, QLatin1Char('0'))
                          .arg(mins, 2, 10, QLatin1Char('0'))
                          .arg(secs, 2, 10, QLatin1Char('0'))
                          .arg(timer->elapsed()%100, 2, 10, QLatin1Char('0')));
}

void stopwatch::press_start(){
    el_timer->start();
    lapse_timer->start();
    main_timer->start();
}

void stopwatch::press_stop_circle_zero(){
    main_timer->stop();
    lapse_number = 1;
}

void stopwatch::clear_all(){
    lapse_number = 1;
    if (main_timer->isActive()){
        main_timer->start();
    }
    if(el_timer->isValid()){
        el_timer->start();
    }
    if(lapse_timer->isValid()){
        lapse_timer->start();
    }
}

void stopwatch::lapse_restart_and_incr(){
    lapse_number++;
    lapse_timer->restart();
}

int stopwatch::Get_lapse(){
    return lapse_number;
}


QTimer* stopwatch::Get_main_timer(){
    return main_timer;
}

QString stopwatch::HowMuchOnWatch(){
    return convert_msec_to_clock_view(el_timer);
}

QString stopwatch::HowMuchOnLapse(){
    return convert_msec_to_clock_view(lapse_timer);
}
