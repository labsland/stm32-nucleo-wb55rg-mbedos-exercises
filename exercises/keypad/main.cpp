#include "mbed.h"

// BASIC PERIPHERALS

// LEDs to show available slots
DigitalOut led1(PB_13);  // Green LED1
DigitalOut led2(PB_14);  // Green LED2
DigitalOut led3(PB_15);  // Green LED3

// switches and buttons
DigitalIn sw1(PB_2);
DigitalIn sw2(PB_4);
DigitalIn sw3(PB_11);
DigitalIn sw4(PB_12);
DigitalIn sw5(PA_6);
DigitalIn sw6(PB_9);
DigitalIn sw7(PB_8);

DigitalIn btn1(PC_5);
DigitalIn btn2(PC_6);
DigitalIn btn3(PC_10);
DigitalIn btn4(PC_12);

// SIMULATIONS

// row selector
DigitalOut row1(PC_4);
DigitalOut row2(PD_0);
DigitalOut row3(PD_1);
DigitalOut row4(PB_0);

// column data
DigitalIn column1(PC_13);
DigitalIn column2(PA_6);
DigitalIn column3(PB_9);
DigitalIn column4(PB_8);


UnbufferedSerial pc(USBTX, USBRX, 115200);

int main() {

    row1 = row2 = row3 = row4 = false;

    DigitalOut rows[] = {row1, row2, row3, row4};
    DigitalIn columns[] = {column1, column2, column3, column4};

    while (true) {
        // Small delay between checks
        ThisThread::sleep_for(10ms);

        for (int row = 0; row < 4; row++) {
            // TODO: 
        }

    }

}


