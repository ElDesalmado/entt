#ifndef ENTT_SRC_HPP
#define ENTT_SRC_HPP

#define ENTT_SOURCE

#include "entt/config/config.h"

#if defined(ENTT_HEADER_ONLY)
# error Do not compile Asio library source with ENTT_HEADER_ONLY defined
#endif

#include "entt/core/impl/type_info.ipp"

#endif // ENTT_SRC_HPP
