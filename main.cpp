#include "mbed.h"
#include "Watchdog.h"

// Define pins for the 7-segment display segments
DigitalOut segmentA(D3);
DigitalOut segmentB(D2);
DigitalOut segmentC(D4);
DigitalOut segmentD(D7);
DigitalOut segmentE(D6);
DigitalOut segmentF(D1);
DigitalOut segmentG(D5);

// Define pins for the DP LED and button
DigitalOut dpLed(D9);
DigitalIn button(D10);

Ticker timer;
Watchdog watchdog; // Initialize the watchdog timer

// Function to display a digit (0–9) on the 7-segment display
void display_digit(int digit) {
    switch (digit) {
        case 0:
            segmentA = 0;
            segmentB = 0;
            segmentC = 0;
            segmentD = 0;
            segmentE = 0;
            segmentF = 0;
            segmentG = 1;
            break;
        case 1:
            segmentA = 1;
            segmentB = 0;
            segmentC = 0;
            segmentD = 1;
            segmentE = 1;
            segmentF = 1;
            segmentG = 1;
            break;
        case 2:
            segmentA = 0;
            segmentB = 0;
            segmentC = 1;
            segmentD = 0;
            segmentE = 0;
            segmentF = 1;
            segmentG = 0;
            break;
        case 3:
            segmentA = 0;
            segmentB = 0;
            segmentC = 0;
            segmentD = 0;
            segmentE = 1;
            segmentF = 1;
            segmentG = 0;
            break;
        case 4:
            segmentA = 1;
            segmentB = 0;
            segmentC = 0;
            segmentD = 1;
            segmentE = 1;
            segmentF = 0;
            segmentG = 0;
            break;
        case 5:
            segmentA = 0;
            segmentB = 1;
            segmentC = 0;
            segmentD = 0;
            segmentE = 1;
            segmentF = 0;
            segmentG = 0;
            break;
        case 6:
            segmentA = 0;
            segmentB = 1;
            segmentC = 0;
            segmentD = 0;
            segmentE = 0;
            segmentF = 0;
            segmentG = 0;
            break;
        case 7:
            segmentA = 0;
            segmentB = 0;
            segmentC = 0;
            segmentD = 1;
            segmentE = 1;
            segmentF = 1;
            segmentG = 1;
            break;
        case 8:
            segmentA = 0;
            segmentB = 0;
            segmentC = 0;
            segmentD = 0;
            segmentE = 0;
            segmentF = 0;
            segmentG = 0;
            break;
        case 9:
            segmentA = 0;
            segmentB = 0;
            segmentC = 0;
            segmentD = 0;
            segmentE = 1;
            segmentF = 0;
            segmentG = 0;
            break;
        default:
            // Turn off all segments if digit is out of range
            segmentA = 1;
            segmentB = 1;
            segmentC = 1;
            segmentD = 1;
            segmentE = 1;
            segmentF = 1;
            segmentG = 1;
            break;
    }
}

void timer_callback() {
    dpLed = !dpLed;             // Toggle DP LED state every 100ms
    watchdog.kick();            // Reset the watchdog timer
}

int main() {
    int counter = 0;
    bool buttonState = false;

    timer.attach(&timer_callback, 100ms);    // Set up a timer to call back every 100ms
    watchdog.start(1000);                    // Start the watchdog timer with a timeout of 1s

    while (1) {
        // Check if the button is pressed
        if (button) {
            if (!buttonState) {
                counter++;
                buttonState = true;
                ThisThread::sleep_for(200ms); // Debounce delay
                watchdog.kick();              // Reset the watchdog timer after button press
            }
        } else {
            buttonState = false;
        }

        // Display the counter value on the 7-segment display
        display_digit(counter % 10);

        // Wait for 0.2 second before updating the display again
        ThisThread::sleep_for(200ms);
        watchdog.kick(); // Reset the watchdog timer within the main loop
    }
}
