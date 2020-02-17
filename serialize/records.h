
#pragma once

#include <stdint.h>

struct HeaderRecord {
    uint8_t version;
    uint8_t type;
    uint16_t requestId;
    uint16_t contentLength;
    uint8_t paddingLength;
};

struct Blah {
    struct HeaderRecord header;
    uint16_t body;
};

struct Blah2 {
    struct HeaderRecord header;
    uint16_t body0;
    uint8_t body1;
};
