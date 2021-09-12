/**************************************************************************
--                      Arduino Midi Player 
-- 
--           Copyright (C) 2019 By Ulrik Hørlyk Hjort
--
--  This Program is Free Software; You Can Redistribute It and/or
--  Modify It Under The Terms of The GNU General Public License
--  As Published By The Free Software Foundation; Either Version 2
--  of The License, or (at Your Option) Any Later Version.
--
--  This Program is Distributed in The Hope That It Will Be Useful,
--  But WITHOUT ANY WARRANTY; Without Even The Implied Warranty of
--  MERCHANTABILITY or FITNESS for A PARTICULAR PURPOSE.  See The
--  GNU General Public License for More Details.
--
-- You Should Have Received A Copy of The GNU General Public License
-- Along with This Program; if not, See <Http://Www.Gnu.Org/Licenses/>.
***************************************************************************/
#define BUZZER 9

// Generated notes, velocitys and durations for the converted midi tune:
uint16_t notes[] = {1865, 1865, 3729, 3729, 2794, 2794, 2349, 2349, 3729,
	 	    3729, 2794, 2794, 2349, 2349, 1976, 1976, 3951, 3951,
		    2960, 2960, 2489, 2489, 3951, 3951, 2960, 2960, 2489,
		    2489, 1865, 1865, 3729, 3729, 2794, 2794, 2349, 2349,
		    3729, 3729, 2794, 2794, 2349, 2349, 2349, 2349, 2489,
		    2489, 2637, 2637, 2637, 2637, 2794, 2794, 2960, 2960, 2960};
		    
uint8_t velocity[] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
                      1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
		      1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
		      
float duration[] = {0.0, 62.5, 62.5, 62.5, 62.5, 62.5, 62.5, 62.5, 62.5, 62.5, 0.0,
                    62.5, 125.0, 187.5, 62.5, 62.5, 62.5, 62.5, 62.5, 62.5, 62.5, 62.5,
		    62.5, 62.5, 0.0, 62.5, 125.0, 187.5, 62.5, 62.5, 62.5, 62.5, 62.5, 62.5,
		    62.5, 62.5, 62.5, 62.5, 0.0, 62.5, 125.0, 187.5, 62.5, 62.5, 0.0, 62.5,
		    0.0, 62.5, 62.5, 62.5, 0.0, 62.5, 0.0, 62.5, 62.5};

/********************************************************************************
 * Play the tune
 ********************************************************************************/
void play() {
   float transpose = 1.0; // Transpose tune up (>1.0) or down (<1.0) (Frequency double per octave)
   for (size_t note = 0; note < sizeof(notes)/sizeof(uint16_t); note++) {
      tone(BUZZER,(notes[note]*transpose)*velocity[note],duration[note]);      
      delay(duration[note]);
   }
}

/********************************************************************************
 * Setup
 ********************************************************************************/
void setup() {}

/********************************************************************************
 * Main loop
 ********************************************************************************/
void loop() {
   play();
   while(1);
}
