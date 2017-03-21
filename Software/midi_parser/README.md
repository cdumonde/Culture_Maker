# midi_parser
A modified version of the "cmidiin.cpp" test program, that can "decode" incoming messages.

## How to use
1. Edit the Makefile to select the correct CXXFLAGS for your platform (I'm too lazy to create a configure script)
2. make
3. Run with ./midi_parser

## Tests
* __Windows (cygwin) :__ Tested and working.
* __Linux :__ Tested and working on Ubuntu 16.04.2 (Requires pthread & libasound2-dev)
* __Mac OSX :__ Not tested yet, who uses Mac anyways ?