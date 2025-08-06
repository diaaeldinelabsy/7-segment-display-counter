# 7-Segment Display with Watchdog Timer

This project demonstrates a basic counter system using a 7-segment display and a push button. Built with the Nucleo development board and programmed in C++ using Mbed OS, the system also integrates a watchdog timer to improve reliability.

## Features

- Displays digits (0–9) using a 7-segment display
- Push button to increment the counter
- Watchdog timer for system reset protection
- Blinking decimal point (DP) LED using Ticker
- Debounce logic for button stability

## Components Used

- Nucleo Board
- 7-segment display (common cathode)
- Push button
- Resistors
- Breadboard and jumper wires

## Pin Connections

| Segment  | Pin  |
|----------|------|
| A        | D3   |
| B        | D2   |
| C        | D4   |
| D        | D7   |
| E        | D6   |
| F        | D1   |
| G        | D5   |
| DP (dot) | D9   |
| Button   | D10  |

## How It Works

1. The counter starts at 0.
2. Each button press increments the count.
3. The 7-segment display shows the current digit (`counter % 10`).
4. A watchdog timer resets the system if the main loop stops.
5. The DP LED blinks every 100ms using a Ticker callback.

## Setup

1. Connect the components as per the wiring diagram.
2. Upload the `main.cpp` code to the Nucleo board using Mbed Studio or Keil Studio Cloud.
3. Power the board and press the button to count from 0 to 9.

## Author

DiaaEldin Elabsy  
City Tech, CUNY
