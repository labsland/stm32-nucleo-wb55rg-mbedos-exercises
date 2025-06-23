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

// Morse signal
DigitalOut morseSignal(PC_4);


UnbufferedSerial pc(USBTX, USBRX, 115200);


// implemented below. Given a char (e.g., 'C'), return the morse equivalent '-.-.'
const char * charToMorse(char c);

void sendMorseMessage(const char * message, bool fast) {
    int dotWait;
    int dashWait;
    int symbolWait;
    int charWait;
    int spaceWait;

    if (fast) {
        dotWait = 50; // ms
        dashWait = 150; // ms
        symbolWait = 50; // ms
        charWait = 150; // ms
        spaceWait = 400; // ms
    } else {
        dotWait = 500; // ms
        dashWait = 1200; // ms
        symbolWait = 500; // ms
        charWait = 1500; // ms
        spaceWait = 2500; // ms
    }

    char c;

    while(*message) {
        if (!sw1)
            break;

        const char c = *message++;
        if (c == ' ') {
            ThisThread::sleep_for((spaceWait-symbolWait) * 1ms);
        } else {
            for (const char * symbols = charToMorse(c); *symbols; symbols++) {

                /// WHAT NEEDS TO BE DONE?
            }
            ThisThread::sleep_for((charWait-symbolWait) * 1ms);
        }
    }
}

int main() {
    bool sending = false;

    while (true) {
        // Small delay between checks
        ThisThread::sleep_for(10ms);

        if (sw1) {
            if (!sending) {
                sending = true;
                sendMorseMessage("HELLO WORLD", sw2);
            }
        } else {
            sending = false;
        }
    }

}

const char * charToMorse(char c) {
    switch (c) {
        case 'A': return ".-";
        case 'B': return "-...";
        case 'C': return "-.-.";
        case 'D': return "-..";
        case 'E': return ".";
        case 'F': return "..-.";
        case 'G': return "--.";
        case 'H': return "....";
        case 'I': return "..";
        case 'J': return ".---";
        case 'K': return "-.-";
        case 'L': return ".-..";
        case 'M': return "--";
        case 'N': return "-.";
        case 'O': return "---";
        case 'P': return ".--.";
        case 'Q': return "--.-";
        case 'R': return ".-.";
        case 'S': return "...";
        case 'T': return "-";
        case 'U': return "..-";
        case 'V': return "...-";
        case 'W': return ".--";
        case 'X': return "-..-";
        case 'Y': return "-.--";
        case 'Z': return "--..";

        // Numbers
        case '1': return ".----";
        case '2': return "..---";
        case '3': return "...--";
        case '4': return "....-";
        case '5': return ".....";
        case '6': return "-....";
        case '7': return "--...";
        case '8': return "---..";
        case '9': return "----.";
        case '0': return "-----";

        // Punctuation
        case '.': return ".-.-.-";
        case ',': return "--..--";
        case '?': return "..--..";
        case '\'': return ".----.";
        case '!': return "-.-.--";
        case '/': return "-..-.";
        case '(': return "-.--.";
        case ')': return "-.--.-";
        case '&': return ".-...";
        case ':': return "---...";
        case ';': return "-.-.-.";
        case '=': return "-...-";
        case '+': return ".-.-.";
        case '-': return "-....-";
        case '_': return "..--.-";
        case '"': return ".-..-.";
        case '$': return "...-..-";
        case '@': return ".--.-.";

        default:
            // not in our table
            return "";        
    }
}

