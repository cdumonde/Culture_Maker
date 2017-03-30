#include "decoder.h"

const std::unordered_map<std::string, int> Decoder::_defaultValues({{"channel", 0},
                                                                     {"control", 0},
                                                                     {"frame_type", 0},
                                                                     {"frame_value", 0},
                                                                     {"note", 0},
                                                                     {"pitch", 0},
                                                                     {"pos", 0},
                                                                     {"program", 0},
                                                                     {"song", 0},
                                                                     {"value", 0},
                                                                     {"velocity", 64}});
                                                         
const std::unordered_map<unsigned char, Message> Decoder::_msgByStatus({// Channel messages.
                                                                        {0x80, {0x80, "note_off", 3}},
                                                                        {0x90, {0x90, "note_on", 3}},
                                                                        {0xA0, {0xA0, "polytouch", 3}},
                                                                        {0xB0, {0xB0, "control_change", 3}},
                                                                        {0xC0, {0xC0, "program_change", 2}},
                                                                        {0xD0, {0xD0, "aftertouch", 2}},
                                                                        {0xE0, {0xE0, "pitchwheel", 3}},
                                                                        // System common messages.
                                                                        {0xF0, {0xF0, "sysex", 255}},
                                                                        {0xF1, {0xF1, "quarter_frame", 2}},
                                                                        {0xF2, {0xF2, "songpos", 3}},
                                                                        {0xF3, {0xF3, "song_select", 2}},
                                                                        {0xF6, {0xF6, "tune_request", 1}},
                                                                        // System real time messages.
                                                                        {0xF8, {0xF8, "clock", 1}},
                                                                        {0xFA, {0xFA, "start", 1}},
                                                                        {0xFB, {0xFB, "continue", 1}},
                                                                        {0xFC, {0xFC, "stop", 1}},
                                                                        {0xFE, {0xFE, "active_sensing", 1}},
                                                                        {0xFF, {0xFF, "reset", 1}}
                                                                       });
                                                            
/*  
    # Channel messages.
    _defmsg(0x80, 'note_off', ('channel', 'note', 'velocity'), 3),
    _defmsg(0x90, 'note_on', ('channel', 'note', 'velocity'), 3),
    _defmsg(0xa0, 'polytouch', ('channel', 'note', 'value'), 3),
    _defmsg(0xb0, 'control_change', ('channel', 'control', 'value'), 3),
    _defmsg(0xc0, 'program_change', ('channel', 'program',), 2),
    _defmsg(0xd0, 'aftertouch', ('channel', 'value',), 2),
    _defmsg(0xe0, 'pitchwheel', ('channel', 'pitch',), 3),
    
    # System common messages.
    # 0xf4 and 0xf5 are undefined.
    _defmsg(0xf0, 'sysex', ('data',), float('inf')),
    _defmsg(0xf1, 'quarter_frame', ('frame_type', 'frame_value'), 2),
    _defmsg(0xf2, 'songpos', ('pos',), 3),
    _defmsg(0xf3, 'song_select', ('song',), 2),
    _defmsg(0xf6, 'tune_request', (), 1),
    
    # System real time messages.
    # 0xf9 and 0xfd are undefined.
    _defmsg(0xf8, 'clock', (), 1),
    _defmsg(0xfa, 'start', (), 1),
    _defmsg(0xfb, 'continue', (), 1),
    _defmsg(0xfc, 'stop', (), 1),
    _defmsg(0xfe, 'active_sensing', (), 1),
    _defmsg(0xff, 'reset', (), 1),
*/
Decoder::Decoder() {

}

void Decoder::decode(double deltatime, std::vector< unsigned char > *message, void */*userData*/) {
    
}

Decoder::~Decoder() {
    
}