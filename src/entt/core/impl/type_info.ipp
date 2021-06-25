#ifndef ENTT_TYPE_INFO_IPP
#define ENTT_TYPE_INFO_IPP

#include "entt/core/type_info.hpp"

namespace entt {

namespace internal {

id_type type_seq::next() ENTT_NOEXCEPT {
  static ENTT_MAYBE_ATOMIC(id_type) value{};
  return value++;
}

}
}

#endif // ENTT_TYPE_INFO_IPP
