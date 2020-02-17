

#include "serialize.h"
#include "pack.h"

enum { BODY_END_INDEX = 7 };

void serialize_HeaderRecord(uint8_t *start_itr,
                            const struct HeaderRecord *record) {
  size_t i = 0;
  pack_u8(start_itr + i++, record->version);
  pack_u8(start_itr + i++, record->type);
  pack_u16(start_itr + i, record->requestId);
  i += 2;
  pack_u16(start_itr + i, record->contentLength);
  i += 2;
  pack_u8(start_itr + i, record->paddingLength);
}

void deserialize_HeaderRecord(struct HeaderRecord *record,
                              const uint8_t *start_itr) {
  size_t i = 0;
  unpack_u8(&record->version, start_itr);
  i++;
  unpack_u8(&record->type, start_itr + i);
  i++;
  unpack_u16(&record->requestId, start_itr + i);
  i += 2;
  unpack_u16(&record->contentLength, start_itr + i);
  i += 2;
  unpack_u8(&record->paddingLength, start_itr + i);
}

void serialize_Blah(uint8_t *start_itr, const struct Blah *record) {
  serialize_HeaderRecord(start_itr, &record->header);
  pack_u16(start_itr + BODY_END_INDEX, record->body);
}

void deserialize_Blah(struct Blah *record, const uint8_t *start_itr) {
  deserialize_HeaderRecord(&record->header, start_itr);
  unpack_u16(&record->body, start_itr + BODY_END_INDEX);
}