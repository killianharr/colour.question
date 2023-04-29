#include "mbed.h"

AnalogIn redPot(A0);    // Red potentiometer connected to pin A0
AnalogIn greenPot(A1);  // Green potentiometer connected to pin A1
PwmOut redLED(p23);     // Red LED connected to pin P23
PwmOut greenLED(p24);   // Green LED connected to pin P24

int main() {
    while(1) {
        // Read the analog values from the pots
        float redValue = redPot.read();
        float greenValue = greenPot.read();

        // Mix the colors using the analog values
        float mixedValue = redValue + greenValue;

        // Set the brightness of each LED using PWM
        redLED.write(redValue);
        greenLED.write(greenValue);

        // Print the analog values of the pots
        printf("Red pot: %f, Green pot: %f\n", redValue, greenValue);

        // Wait for 0.05 seconds
        wait(0.05);
    }
}
