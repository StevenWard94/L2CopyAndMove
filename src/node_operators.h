/***********************************************************************************//**
 * Author:       Steven Ward <stevenward94@gmail.com>
 * File:         L2Copy+Move/include/node_operators.h
 * Last Change:  2016 Nov 09
 ***********************************************************************************/

#ifndef LEARN_COPY_MOVE_INCLUDE_SINGLE_LINK_NODE_OPERATORS_H_
#define LEARN_COPY_MOVE_INCLUDE_SINGLE_LINK_NODE_OPERATORS_H_

#include "auxiliary.h"
#include "Node.h"

#include <iostream>

namespace single_link {

template<class E>
using is_Eq_instance = typename utils::typeclass::Eq<E>::value;

template<class E>
using is_Ord_instance = typename utils::typeclass::Ord<E>::value;


template<class E, typename = utils::enable_if<is_Eq_instance<E>>>
bool operator==(Node<E> const& lhs, Node<E> const& rhs) {
    return lhs.data() == rhs.data();
}

template<class E, typename = utils::enable_if<is_Eq_instance<E>>>
bool operator!=(Node<E> const& lhs, Node<E> const& rhs) {
    return !(lhs == rhs);
}

template<class E, typename = utils::enable_if<is_Ord_instance<E>>>
bool operator< (Node<E> const& lhs, Node<E> const& rhs) {
    return lhs.data() < rhs.data();
}

template<class E, typename = utils::enable_if<is_Ord_instance<E>>>
bool operator> (Node<E> const& lhs, Node<E> const& rhs) {
    return rhs < lhs;
}

template<class E, typename = utils::enable_if<is_Ord_instance<E>>>
bool operator<=(Node<E> const& lhs, Node<E> const& rhs) {
    return !(lhs > rhs);
}

template<class E, typename = utils::enable_if<is_Ord_instance<E>>>
bool operator>=(Node<E> const& lhs, Node<E> const& rhs) {
    return !(lhs < rhs);
}


template<class E>
std::ostream& operator<<(std::ostream& os, Node<E> const& node) {
    os << node.data();
    return os;
}

template<class E>
std::istream& operator>>(std::istream& is, Node<E>& node) {
    E buf;
    is >> buf;
    node.data(std::move(buf));
    return is;
}

} // namespace single_link

#endif  // LEARN_COPY_MOVE_INCLUDE_SINGLE_LINK_NODE_OPERATORS_H_
