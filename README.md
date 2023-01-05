# Stepper Motor Instrument

## Intro

## How it works

### Assembling the motors

### Coding the music

The Stepper motors are able to create notes with sound waves. The pitch is changed by the frequency, those with higher frequencies(smaller wavelength) producing higher pitches and the same goes for lower frequencies and pitches. We control the frequency by changing the period between wave compressions. We can do this with stepper motors by sending the desired period to the motors so that they oscillate in a manner that produces the correct pitch. Frequencies of notes are found (https://en.wikipedia.org/wiki/Piano_key_frequencies) and are used to find the period with the formula 1/frequency. Each note is initialized as an array which holds the periods of the sound with respect to its octive, i.e. the indices represent the octive of the note. 

## Demo
