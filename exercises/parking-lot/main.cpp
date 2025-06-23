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

// Sensors - Active HIGH
DigitalIn entry_sensor(PB_8);    // Car presence at entry
DigitalIn exit_sensor(PC_12);    // Car presence at exit

// Barriers and indicators - Active HIGH
DigitalOut entry_barrier(PB_1);   // Entry barrier control
DigitalOut exit_barrier(PB_15);   // Exit barrier control
DigitalOut full_indicator(PB_0);  // Parking full indicator (1=red, 0=green)

// LEDs in the simulation
DigitalOut parking1Led(PC_4);
DigitalOut parking2Led(PD_0);
DigitalOut parking3Led(PD_1);

DigitalIn parkingSpot1Sensor(PC_13);
DigitalIn parkingSpot2Sensor(PA_6);
DigitalIn parkingSpot3Sensor(PB_9);


UnbufferedSerial pc(USBTX, USBRX, 115200);

int available_slots = 3;

int main()
{
    // Initialize outputs
    entry_barrier = 0;
    exit_barrier = 0;

    while (true) {

        // TODO:
        // when entry sensor is 1, if there are available spots, then open the entry barrier (1, wait a bit, and then 0)
        // when exit sensor is 1, open the exit_barrier (1, wait a bit, and then 0)

        // Additionally: if all the available spots are taken, turn on full_indicator = 1
        // Additionally, turn on the parking1Led if parkingSpot1Sensor is 1, etc.

        ThisThread::sleep_for(10ms);
    }
}
