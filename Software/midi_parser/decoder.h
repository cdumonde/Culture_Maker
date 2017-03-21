#ifndef __DECODER_H__
#define __DECODER_H__
#include <vector>
#include <unordered_map>

typedef struct {
    unsigned char statusByte;
    std::string type;
    unsigned char length;
} Message;

class Decoder {
        private:

        
        public:
        Decoder();
        ~Decoder();
        void decode(double deltatime, std::vector< unsigned char > *message, void */*userData*/);
        static const std::unordered_map<std::string, int> _defaultValues;
        static const std::unordered_map<unsigned char, Message> _msgByStatus;
};

#endif