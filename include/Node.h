/***********************************************************************************//**
 * Author:       Steven Ward <stevenward94@gmail.com>
 * File:         /home/steven/lib/cpp.d/L2Copy+Move/include/Node.h
 * Last Change:  2016 Nov 07
 ***********************************************************************************/

#ifndef LEARN_COPY_MOVE_INCLUDE_SINGLE_LINK_NODE_H_
#define LEARN_COPY_MOVE_INCLUDE_SINGLE_LINK_NODE_H_

#include <iostream>
#include <type_traits>
#include <utility>

#include <stddef.h>

namespace single_link {

template<class E>
class Node {
    typedef E value_t;

    template<typename T>
    using remove_reference = typename std::remove_reference<T>::type;

  public:
    inline remove_reference<value_t> data( ) const { return std::forward<value_t>(data_); }

    inline remove_reference<value_t> data(value_t const& val) {
        value_t old_data = std::move(this->data_);
        this->data_(val);
        return old_data;
    }

    inline remove_reference<value_t> data(value_t&& val) {
        value_t old_data = std::move(this->data_);
        this->data_(std::forward<value_t>(val));
        return old_data;
    }


    inline Node<value_t> const* const next( ) const { return const_cast<Node<value_t> const*>(next_); }

    inline Node<value_t>* next(Node<value_t> const* node) {
        Node<value_t>* old_next = new Node<value_t>(this->next_);
        this->next_ = new Node<value_t>(node);
        return old_next;
    }


  private:
    value_t data_ { };
    Node<value_t>* next_ { nullptr };

    inline Node(Node<value_t> const* node)
            : data_ { node->data_ }, next_ { new Node<value_t>(node->next_) } { }
};

}

#endif  // (LEARN_COPY_MOVE_INCLUDE_SINGLE_LINK_NODE_H_)
