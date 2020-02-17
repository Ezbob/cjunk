
#pragma once

#include <stdint.h>

inline void pack_u8(uint8_t *res, const uint8_t src) {
    res[0] = src;
}

inline void unpack_u8(uint8_t *res, const uint8_t *src) {
    *res = *src;
}

inline void pack_u16(uint8_t *res, const uint16_t src) {
    res[0] = (src >> 8);
    res[1] = src;
}

inline void unpack_u16(uint16_t *res, const uint8_t *src) {
    *res = ((uint16_t) src[0] << 8)
         + ((uint16_t) src[1]);
}

inline void pack_u32(uint8_t *res, const uint32_t src) {
    res[0] = (src >> 24);
    res[1] = (src >> 16);
    res[2] = (src >> 8);
    res[3] = src;
}

inline void unpack_u32(uint32_t *res, const uint8_t *src) {
    *res = ((uint32_t) src[0] << 24)
         + ((uint32_t) src[1] << 16)
         + ((uint32_t) src[2] << 8)
         + ((uint32_t) src[3]);
}

inline void pack_u64(uint8_t *res, const uint64_t src) {
    res[0] = (src >> 56);
    res[1] = (src >> 48);
    res[2] = (src >> 40);
    res[3] = (src >> 32);
    res[4] = (src >> 24);
    res[5] = (src >> 16);
    res[6] = (src >> 8);
    res[7] = src;
}

inline void unpack_u64(uint64_t *res, uint8_t * src) {
    *res = ((uint64_t) src[0] << 56)
         + ((uint64_t) src[1] << 48)
         + ((uint64_t) src[2] << 40)
         + ((uint64_t) src[3] << 32)
         + ((uint64_t) src[4] << 24)
         + ((uint64_t) src[5] << 16)
         + ((uint64_t) src[6] << 8)
         + ((uint64_t) src[7]);
}
