#ifndef SIMDJSON_STAGE2_BUILD_TAPE_H
#define SIMDJSON_STAGE2_BUILD_TAPE_H

#include "simdjson/common_defs.h"
#include "simdjson/parsedjson.h"
#include "simdjson/simdjson.h"

namespace simdjson {

void init_state_machine();

template <Architecture T = Architecture::NATIVE>
WARN_UNUSED int
unified_machine(const uint8_t *buf, size_t len, document::parser &parser);

template <Architecture T = Architecture::NATIVE>
WARN_UNUSED int
unified_machine(const char *buf, size_t len, document::parser &parser) {
  return unified_machine<T>(reinterpret_cast<const uint8_t *>(buf), len, parser);
}



// Streaming
template <Architecture T = Architecture::NATIVE>
WARN_UNUSED int
unified_machine(const uint8_t *buf, size_t len, document::parser &parser, size_t &next_json);

template <Architecture T = Architecture::NATIVE>
int unified_machine(const char *buf, size_t len, document::parser &parser, size_t &next_json) {
    return unified_machine<T>(reinterpret_cast<const uint8_t *>(buf), len, parser, next_json);
}


} // namespace simdjson

#endif
