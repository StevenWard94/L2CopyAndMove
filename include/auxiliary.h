/***********************************************************************************//**
 * Author:       Steven Ward <stevenward94@gmail.com>
 * File:         L2Copy+Move/include/Auxiliary.h
 * Last Change:  2016 Nov 09
 ***********************************************************************************/

#ifndef LEARN_COPY_MOVE_INCLUDE_UTILS_AUXILIARY_H_
#define LEARN_COPY_MOVE_INCLUDE_UTILS_AUXILIARY_H_

#include <type_traits>
#include <utility>

#include <stddef.h>

namespace utils {

template<class ...> using void_t = void;

template<class Type>
using remove_reference = typename std::remove_reference<Type>::type;

template<class Type>
using ensure_reference = typename std::remove_reference<Type>::type&;

template<class Type>
using ensure_const_ref = typename std::remove_reference<Type>::type const&;

template<class Predicate, class Param = void>
using enable_if = typename std::enable_if<Predicate::value, Param>::type;

template<class Predicate, class Param = void>
using disable_if = typename std::enable_if<!Predicate::value, Param>::type;


namespace typeclass {

template<class Type, typename = void>
struct Eq : std::false_type { };

template<class Type>
struct Eq< Type
         , void_t<decltype( std::declval<Type>() == std::declval<Type>() )>
         > : std::true_type { };


template<class Type, typename = void>
struct Ord : std::false_type { };

template<class Type>
struct Ord< Type
          , void_t<decltype( std::declval<Type>() < std::declval<Type>() )>
          > : std::true_type { };

} // namespace typeclass

} // namespace utils

#endif  // LEARN_COPY_MOVE_INCLUDE_UTILS_AUXILIARY_H_
