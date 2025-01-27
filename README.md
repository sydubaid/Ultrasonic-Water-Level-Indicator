# Ultrasonic Water Level Indicator Project

This project uses an Arduino Uno, an ultrasonic sensor, and an LCD to create a water level indicator. The ultrasonic sensor measures the water level in a tank and displays the percentage of the tank's capacity on the LCD.

---

## Features
- **Real-time water level monitoring**
- **User input for tank depth via serial monitor**
- **LCD display showing percentage of water level**
- Simple and cost-effective solution

---

## Components Required
1. Arduino Uno
2. Ultrasonic Sensor (e.g., HC-SR04)
3. 16x2 LCD Display
4. Breadboard and jumper wires
5. Potentiometer (for LCD contrast adjustment)
6. Power source for Arduino

---

## Circuit Diagram
### Pins Configuration:
1. **Ultrasonic Sensor:**
   - Trig Pin: Pin 9 on Arduino
   - Echo Pin: Pin 10 on Arduino
2. **LCD Display:**
   - RS: Pin 12
   - EN: Pin 11
   - D4: Pin 4
   - D5: Pin 5
   - D6: Pin 6
   - D7: Pin 8

Ensure proper connections for VCC, GND, and the potentiometer to control the LCD contrast.

---

## How to Use
1. Open the Arduino IDE.
2. Upload the `ultrasonic_water_level.ino` file to your Arduino Uno.
3. Open the serial monitor in the Arduino IDE.
4. Enter the depth of the water tank (in centimeters) into the serial monitor.
5. Observe the water level percentage on the LCD display.

---

## Code Explanation
1. The ultrasonic sensor sends a pulse and measures the time it takes to return.
2. The code calculates the distance using the formula:
   ```
   distance = (pulseDuration * 0.0343) / 2;
   ```
3. The percentage of water level is calculated as:
   ```
   level = (1 - distance / depth) * 100;
   ```
4. The LCD displays the percentage of water level in real time.

---

## Troubleshooting
- **No Display on LCD:** Check the contrast adjustment using the potentiometer.
- **Incorrect Readings:** Ensure proper calibration and input of the correct tank depth.
- **No Signal from Ultrasonic Sensor:** Verify the connections for Trig and Echo pins.

---

## Future Improvements
- Add an alarm system for low or high water levels.
- Integrate with IoT to monitor water levels remotely.
- Add a feature to store data over time for analysis.

---

## License
This project is open-source and available for personal and educational use.

---

## Author
Syed Ubaid

Feel free to contribute and improve the project!
