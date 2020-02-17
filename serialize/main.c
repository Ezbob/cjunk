#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "pack.h"
#include "records.h"
#include "serialize.h"

void print_packed(uint8_t *p, size_t size) {
  for (size_t i = 0; i < size; ++i) {
    if (i % 4 == 0 && i != 0) {
      printf(" ");
    }
    printf("%02x ", p[i]);
  }
  printf("\n");
}

void print_header(struct HeaderRecord *r) {
  printf("{\n"
         "  version: %u,\n"
         "  type: %u,\n"
         "  requestId: %u,\n"
         "  contentLength: %u,\n"
         "}\n",
         r->version, r->type, r->requestId, r->contentLength);
}

void print_blah(struct Blah *r) {
  printf("header: ");
  print_header(&r->header);
  printf("body: ");
  printf("{\n"
         "  body: %hu\n"
         "}\n",
         r->body);
}

enum {
  UINT8_BYTE_COUNT = 1,
  UINT16_BYTE_COUNT = 2,
  UINT32_BYTE_COUNT = 4,
  UINT64_BYTE_COUNT = 8
};

int main() {

  /* start */

  uint8_t h0 = 142;
  uint8_t p0[UINT8_BYTE_COUNT];

  printf("8 before: %u\n", h0);
  pack_u8(p0, h0);

  printf("8 Packed: ");
  print_packed(p0, UINT8_BYTE_COUNT);

  uint8_t res0 = 0;

  unpack_u8(&res0, p0);

  printf("8 after: %u\n", res0);

  assert(h0 == res0);

  /* end */
  /* start */

  uint16_t h = 342;
  uint8_t p[UINT16_BYTE_COUNT];

  printf("16 before: %u\n", h);
  pack_u16(p, h);

  printf("16 Packed: ");
  print_packed(p, UINT16_BYTE_COUNT);

  uint16_t res = 0;

  unpack_u16(&res, p);

  printf("16 after: %u\n", res);

  assert(h == res);

  /* end */
  /* start */

  uint32_t h2 = 211223342;
  uint8_t p2[UINT32_BYTE_COUNT];

  printf("32 before: %u\n", h2);
  pack_u32(p2, h2);

  printf("32 Packed: ");
  print_packed(p2, UINT32_BYTE_COUNT);

  uint32_t res2 = 0;

  unpack_u32(&res2, p2);

  printf("32 after: %u\n", res2);

  assert(h2 == res2);

  /* end */
  /* start */

  uint64_t h3 = 21341223342;
  uint8_t p3[UINT64_BYTE_COUNT];

  printf("64 before: %llu\n", h3);
  pack_u64(p3, h3);

  printf("64 Packed: ");
  print_packed(p3, UINT64_BYTE_COUNT);

  uint64_t res3 = 0;

  unpack_u64(&res3, p3);

  printf("64 after: %llu\n", res3);

  assert(h3 == res3);

  /* end */

  struct HeaderRecord r = {.version = 1,
                           .type = 2,
                           .requestId = 42,
                           .contentLength = 10,
                           .paddingLength = 11};

  print_header(&r);

  uint8_t packed[16] = {0};

  print_packed(packed, 16);

  serialize_HeaderRecord(packed, &r);

  print_packed(packed, 16);

  struct HeaderRecord rr;

  deserialize_HeaderRecord(&rr, packed);

  print_header(&rr);

  /* -- */

  struct Blah r1 = {.header = {.version = 1,
                               .type = 2,
                               .requestId = 42,
                               .contentLength = 10,
                               .paddingLength = 11},
                    .body = 37};

  print_blah(&r1);

  uint8_t packed1[16] = {0};

  print_packed(packed1, 16);

  serialize_Blah(packed1, &r1);

  print_packed(packed1, 16);

  struct Blah rr1;

  deserialize_Blah(&rr1, packed1);

  print_blah(&rr1);

  return 0;
}