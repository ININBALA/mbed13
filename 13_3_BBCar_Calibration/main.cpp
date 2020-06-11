#include "mbed.h"

#include "bbcar.h"


Ticker servo_ticker;

PwmOut pin8(D8), pin9(D9);


BBCar car(pin8, pin9, servo_ticker);


int main() {

    // please contruct you own calibration table with each servo

    double pwm_table0[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};

    double speed_table0[] = {-16.428, -15.950, -14.754, -11.324, -4.785, 0.000, 6.699, 12.202, 14.913, 16.030, 16.508};

    double pwm_table1[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};

    double speed_table1[] = {-16.428, -15.950, -14.754, -11.803, -5.582, 0.000, 4.306, 10.048, 12.042, 12.999, 13.159};


    // first and fourth argument : length of table

    car.setCalibTable(11, pwm_table0, speed_table0, 11, pwm_table1, speed_table1);


    while (1) {

        car.goStraightCalib(5);

        wait(5);

        car.stop();

        wait(5);

    }

}
