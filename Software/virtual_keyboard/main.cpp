 #include <chrono>
#include <thread>
#include <unordered_map>
#include "RtMidi.h"

#define NOTE_ON_MSG      128
#define NOTE_OFF_MSG     144
#define NOTE_DURATION_MS 500

const std::unordered_map<unsigned char, unsigned char> notemap({{'a', 60},
                                                                {'z', 61},
                                                                {'e', 62},
                                                                {'r', 63},
                                                                {'t', 64},
                                                                {'y', 65},
                                                                {'u', 66},
                                                                {'i', 67},
                                                                {'o', 68},
                                                                {'p', 69},
                                                                });
int main(void) {
    RtMidiOut *midiout = 0;
    
  // RtMidiOut constructor
    try {
        midiout = new RtMidiOut();
    }
    catch (const RtMidiError &error) {
        error.printMessage();
        return EXIT_FAILURE;
    }

    // Opening virtual port
    try {
        midiout->openVirtualPort();
    } catch (const RtMidiError& error) {
        error.printMessage();
        delete midiout;
        return EXIT_FAILURE;
    }
      
    // Creating the message buffer
    std::vector<unsigned char> message(3);
    message[2] = 127; // Setting max velocity
    
    // Notes buffer
    std::string notes;
        
    std::cout << "You may now enter notes [azertyuiop] (any other note will exit)" << std::endl;

    while(true) {
        std::cout << ">";
        std::getline(std::cin, notes);
        for (char &c : notes) {
            try {
                message[1] = notemap.at(c);
                
                message[0] = NOTE_ON_MSG;
                midiout->sendMessage(&message);
                
                std::this_thread::sleep_for(std::chrono::milliseconds(NOTE_DURATION_MS));

                message[0] = NOTE_OFF_MSG;
                midiout->sendMessage(&message);

            } catch (const std::out_of_range& error) {
                std::cerr << "Unknown note : " << c << std::endl;
                std::cerr << "Exiting..." << std::endl;
                delete midiout;
                return EXIT_SUCCESS;
            }
        }
    }
}