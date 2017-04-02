CXX=g++

# Windows (cygwin)
#CXXFLAGS=-Wall -O3 -std=c++11 -I/usr/include/w32api -D__WINDOWS_MM__ -lwinmm
# Linux
#CXXFLAGS=-Wall -O3 -std=c++11 -D__LINUX_ALSA__ -lpthread -lasound
# Mac OS
CXXFLAGS=-Wall -O3 -std=c++11 -D__MACOSX_CORE__ -framework CoreMIDI -framework CoreFoundation -framework CoreAudio


#LDFLAGS=
EXEC=interface_midi
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

interface_midi: $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS) $(CXXFLAGS)

test_controller:
	g++ -Wall -O3 -std=c++11 -o test_midi/Controller/test_controller test_midi/Controller/test_controller.cpp test_midi/Controller/Controller.cpp;

clean:
	rm -rf *.o

clean_config:
	rm ./test_midi/Controller/*.mod
