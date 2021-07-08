#ifndef ENTT_TYPE_INFO_IPP
#define ENTT_TYPE_INFO_IPP

#include "entt/core/type_info.hpp"

namespace entt::internal {

id_type type_seq::next() ENTT_NOEXCEPT {
  static ENTT_MAYBE_ATOMIC(id_type) value{};
  return value++;
}

} // namespace entt::internal

namespace entt {
template <typename Type, typename V>
id_type type_seq<Type, V>::value() ENTT_NOEXCEPT {
  static const id_type value = internal::type_seq::next();
  return value;
}
} // namespace entt

#endif // ENTT_TYPE_INFO_IPP
