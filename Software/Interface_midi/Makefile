CC = g++
CXXFLAG = -Wall -Wextra

all: interface_midi

interface_midi: interface_midi.o RtMidi.o
	g++ interface_midi.o RtMidi.o -o interface_midi

clean: 
	rm -rf *.o