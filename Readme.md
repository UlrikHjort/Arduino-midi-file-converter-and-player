# Single track midi file to Arduino converter

### Usage
python midi2arduino MIDIFILE 

e.g. python midi2arduino ./pacman.mid
  
  
3 separate arrays are generated containing notes (frequencies), velocities (on and off) and note durations (in ms) for the given midi file.
The generated velocity  only indicate  note on and off due to the buzzer limitations.
The midi file is expected to contain only one track. Only track 0 is processed.


### Hardware
* Arduino UNO (or similar)
* Buzzer
* R100 reststor (optional)


### Wiring
| Buzzer  |  Arduino |
| --- | --- |
|GND | GND |
| + | PIN9 (with optional R100) |


### Dependencies
Python:
mido >= 1.2.9
