# virtual_keyboard
VERY Simple program to create a "virtual" MIDI keyboard.
The purpose of this is to have some kind of emulator to work with when no real MIDI adapters are available.

__HOW TO :__
1. Edit the Makefile the select the correct CXXFLAGS for your platform (because yeah I'm too lazy to create a configure script)
2. make
3. Run with ./virtual_keyboard

* All notes velocities are set to max (127).
* All notes are held for NOTE_DURATION_MS ms (Default : 500ms).
* Notes ranges from 60 to 69 (C3 to A3).

According to this table :

  Key  |  Note  |  Value
  ---  |  ----  |  -----
   a   |  C3    |   60
   z   |  C#3   |   61
   e   |  D3    |   62
   r   |  D#3   |   63
   t   |  E3    |   64
   y   |  F3    |   65
   u   |  F#3   |   66
   i   |  G3    |   67
   o   |  G#3   |   68
   p   |  A3    |   69

* Usable notes can be configured by editing the "notesmap" unordered_map accordingly.
* Every character entered that is not inside this map will exit the program.
* The only messages used are NOTE_ON and NOTE_OFF

# Tests
* __Windows (cygwin) :__ RtMidi doesn't support "openVirtualPort()" on Windows, so it won't work.
* __Linux :__ Tested and working on Ubuntu 16.04.2 (Requires pthread & libasound2-dev)