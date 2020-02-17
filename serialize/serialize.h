
#pragma once

#include <stdint.h>
#include "records.h"

void serialize_HeaderRecord(uint8_t *start_itr, const struct HeaderRecord *record);
void deserialize_HeaderRecord(struct HeaderRecord *record, const uint8_t *start_itr);

void serialize_Blah(uint8_t *start_itr, const struct Blah *record);
void deserialize_Blah(struct Blah *record, const uint8_t *start_itr);