########################################################################
#                                                                           
#                                                                    
#                     Midi to Arduino file converter
#                          midi2arduino.py                                      
#                                                                           
#                                MAIN                                      
#                                                                           
#                 Copyright (C) 2019 Ulrik Hoerlyk Hjort                   
#                                                                        
#  Ipod file extract is free software;  you can  redistribute it                          
#  and/or modify it under terms of the  GNU General Public License          
#  as published  by the Free Software  Foundation;  either version 2,       
#  or (at your option) any later version.                                   
#  Ipod file extract is distributed in the hope that it will be                           
#  useful, but WITHOUT ANY WARRANTY;  without even the  implied warranty    
#  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                  
#  See the GNU General Public License for  more details.                    
#  You should have  received  a copy of the GNU General                     
#  Public License  distributed with Yolk.  If not, write  to  the  Free     
#  Software Foundation,  51  Franklin  Street,  Fifth  Floor, Boston,       
#  MA 02110 - 1301, USA.                                                    
########################################################################        
import mido
from mido import MidiFile
from sys import argv

# Note frequency table from B0 and up
notes = [31,33,35,37,39,41,44,46,49,52,55,58,62,65,69,73,78,82,87,93,98,104,110,
         117,123,131,139,147,156,165,175,185,196,208,220,233,247,262,277,294,311,
         330,349,370,392,415,440,466,494,523,554,587,622,659,698,740,784,831,880,
         932,988,1047,1109,1175,1245,1319,1397,1480,1568,1661,1760,1865,1976,2093,
         2217,2349,2489,2637,2794,2960,3136,3322,3520,3729,3951,4186,4435,4699,4978]

midi = MidiFile(argv[1], clip=True)

note_list = []
velocity_list = []
duration_list = []

limit = 60 # length limit of converted song
tempo = 500000 # Default 120 bpm (Midi standard)

# Extract notes and tempo from track. Only a single track in the file is expected
for msg in midi.tracks[0]:
    if msg.is_meta:
        if msg.type == 'set_tempo' :
            tempo = (msg.tempo)
        elif msg.type == 'time_signature' :
            print (msg.numerator, msg.denominator, msg.clocks_per_click);
        elif msg.type == 'end_of_track' :
            print(mido.tick2second(msg.time,midi.ticks_per_beat,tempo))            
    elif msg.type == 'note_on' or msg.type == 'note_off':
        note_list.append(notes[msg.note])
        velocity_list.append((( 1 if msg.velocity > 0 else 0)))        
        duration_list.append(mido.tick2second(msg.time,midi.ticks_per_beat,tempo)*1000)

    limit -= 1
    if limit == 0:
        break

# Print out generated notes, velocities and durations (copy/paste into Arduino sketch file)
print("uint16_t notes[] = " + (str(note_list).replace("[","{").replace("]","}")) + ";")
print("uint8_t velocity[] = " + (str(velocity_list).replace("[","{").replace("]","}")) + ";")
print("float duration[] = " + (str(duration_list).replace("[","{").replace("]","}"))  + ";")


