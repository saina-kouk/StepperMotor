# Stepper Motor Instrument

## Intro

This project aims to create music from the rotation of stepper motors. Using the frequencies of piano notes, we can control the period of sound waves through the movement of the motors.

## How it works

### Assembling the motors

In order to communicate the desired motor rotations to the stepper motors, I used an Arduino Uno, an A4988 driver, a 9-12v power supply and a breadboard to connect it all together! For a single motor, the driver is connected at ground and voltage(VMOT) to the power supply and connects its output channels to the stepper motor to provide the required voltage. The Arduino board connects to the driver at ground and voltage(VDD) to power the circuit. For speed control, the driver connects at STEP to the Arduino and for direction control the driver connects at DIR to the Arduino.

### Coding the music

The Stepper motors are able to create notes with sound waves. The pitch is changed by the frequency, those with higher frequencies(smaller wavelength) producing higher pitches and the same goes for lower frequencies and pitches. We control the frequency by changing the period between wave compressions. We can do this with stepper motors by sending the desired period to the motors so that they oscillate in a manner that produces the correct pitch. Frequencies of notes are found (https://en.wikipedia.org/wiki/Piano_key_frequencies) and are used to find the period with the formula 1/frequency. Each note is initialized as an array which holds the periods of the sound with respect to its octive, i.e. the indices represent the octive of the note. 

## Demo
