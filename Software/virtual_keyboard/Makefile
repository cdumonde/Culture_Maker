CXX=g++

# Windows (cygwin)
#CXXFLAGS=-Wall -O3 -std=c++11 -I/usr/include/w32api -D__WINDOWS_MM__ -lwinmm
# Linux
CXXFLAGS=-Wall -O3 -std=c++11 -D__LINUX_ALSA__ -lpthread -lasound
# Mac OS
#CXXFLAGS=-Wall -O3 -std=c++11 -D__MACOSX_CORE__ -framework CoreMIDI -framework CoreFoundation -framework CoreAudio


LDFLAGS=
EXEC=virtual_keyboard
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

virtual_keyboard: $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS) $(CXXFLAGS)

clean:
	rm -rf *.o
