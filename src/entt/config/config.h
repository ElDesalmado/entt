#ifndef ENTT_CONFIG_CONFIG_H
#define ENTT_CONFIG_CONFIG_H


#ifndef ENTT_NOEXCEPT
#   define ENTT_NOEXCEPT noexcept
#endif


#if defined(__cpp_lib_launder) && __cpp_lib_launder >= 201606L
#   include <new>
#   define ENTT_LAUNDER(expr) std::launder(expr)
#else
#   define ENTT_LAUNDER(expr) expr
#endif


#ifndef ENTT_USE_ATOMIC
#   define ENTT_MAYBE_ATOMIC(Type) Type
#else
#   include <atomic>
#   define ENTT_MAYBE_ATOMIC(Type) std::atomic<Type>
#endif


#ifndef ENTT_ID_TYPE
#   include <cstdint>
#   define ENTT_ID_TYPE std::uint32_t
#endif


#ifdef ENTT_SPARSE_PAGE
	static_assert(ENTT_SPARSE_PAGE && ((ENTT_SPARSE_PAGE & (ENTT_SPARSE_PAGE - 1)) == 0), "ENTT_SPARSE_PAGE must be a power of two");
#else
#   define ENTT_SPARSE_PAGE 4096
#endif


#ifdef ENTT_PACKED_PAGE
static_assert(ENTT_PACKED_PAGE && ((ENTT_PACKED_PAGE & (ENTT_PACKED_PAGE - 1)) == 0), "ENTT_PACKED_PAGE must be a power of two");
#else
#   define ENTT_PACKED_PAGE 1024
#endif


#ifdef ENTT_DISABLE_ASSERT
#   undef ENTT_ASSERT
#   define ENTT_ASSERT(...) (void(0))
#elif !defined ENTT_ASSERT
#   include <cassert>
#   define ENTT_ASSERT(condition, ...) assert(condition)
#endif


#ifndef ENTT_NO_ETO
#   include <type_traits>
#   define ENTT_IS_EMPTY(Type) std::is_empty<Type>
#else
#   include <type_traits>
#   define ENTT_IS_EMPTY(Type) std::false_type
#endif


#ifndef ENTT_STANDARD_CPP
#    if defined __clang__ || defined __GNUC__
#       define ENTT_PRETTY_FUNCTION __PRETTY_FUNCTION__
#       define ENTT_PRETTY_FUNCTION_PREFIX '='
#       define ENTT_PRETTY_FUNCTION_SUFFIX ']'
#    elif defined _MSC_VER
#       define ENTT_PRETTY_FUNCTION __FUNCSIG__
#       define ENTT_PRETTY_FUNCTION_PREFIX '<'
#       define ENTT_PRETTY_FUNCTION_SUFFIX '>'
#   endif
#endif

// copied from asio config.h
// Default to a header-only implementation. The user must specifically request
// separate compilation by defining either ENTT_SEPARATE_COMPILATION or
// ENTT_DYN_LINK (as a DLL/shared library implies separate compilation).
#if !defined(ENTT_HEADER_ONLY)
#     if !defined(ENTT_SEPARATE_COMPILATION)
#         if !defined(ENTT_DYN_LINK)
#             define ENTT_HEADER_ONLY 1
#         endif // !defined(ENTT_DYN_LINK)
#     endif // !defined(ENTT_SEPARATE_COMPILATION)
#endif // !defined(ENTT_HEADER_ONLY)

#if defined(ENTT_HEADER_ONLY)
# define ENTT_DECL inline
#else // defined(ENTT_HEADER_ONLY)
# if defined(_MSC_VER) || defined(__BORLANDC__) || defined(__CODEGEARC__)
// We need to import/export our code only if the user has specifically asked
// for it by defining ENTT_DYN_LINK.
#  if defined(ENTT_DYN_LINK)
// Export if this is our own source, otherwise import.
#   if defined(ENTT_SOURCE)
#    define ENTT_DECL __declspec(dllexport)
#   else // defined(ENTT_SOURCE)
#    define ENTT_DECL __declspec(dllimport)
#   endif // defined(ENTT_SOURCE)
#  endif // defined(ENTT_DYN_LINK)
# endif // defined(_MSC_VER) || defined(__BORLANDC__) || defined(__CODEGEARC__)
#endif // defined(ENTT_HEADER_ONLY)

// If ENTT_DECL isn't defined yet define it now.
#if !defined(ENTT_DECL)
# define ENTT_DECL
#endif // !defined(ENTT_DECL)

#endif
