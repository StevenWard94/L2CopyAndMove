/***********************************************************************************//**
 * Author:       Steven Ward <stevenward94@gmail.com>
 * File:         L2Copy+Move/include/Node.h
 * Last Change:  2016 Nov 09
 ***********************************************************************************/

#ifndef LEARN_COPY_MOVE_INCLUDE_SINGLE_LINK_NODE_H_
#define LEARN_COPY_MOVE_INCLUDE_SINGLE_LINK_NODE_H_

#include "auxiliary.h"
#include "node_operators.h"

namespace single_link {

template<class E>
class Node {
    template<typename T>
    using remove_reference = utils::remove_reference<T>;
    using value_t = E;

  public:
    inline remove_reference<value_t> data( ) const { return std::forward<value_t>(data_); }

    // assumes that a copy-assignment operator is defined for the type 'value_t'
    inline void setData(value_t const& val) { this->data_ = val; }
    inline remove_reference<value_t> data(value_t&& val) { this->data_(std::forward<value_t>(val)); }

    inline Node<value_t> const* const next( ) const { return const_cast<Node<value_t> const*>(next_); }
    inline Node<value_t>* setNext(Node<value_t> const* node) { this->next_ = new Node<value_t>(node); }

    inline Node<value_t>& operator= (Node<value_t> const& rhs) {
        if (this != &rhs) {
            delete this->next_;
            this->next_ = nullptr;

            Node<value_t> tmp(rhs);
            std::swap(this->data_, tmp.data_);
            std::swap(*(this->next_), *(tmp.next_));
        }
        return *this;
    }

    inline Node<value_t>& operator= (Node<value_t>&& rhs) {
        delete this->next_;
        this->next_ = nullptr;
        std::swap(this->data_, rhs.data_);
        std::swap(*(this->next_), *(rhs.next_));
    }


    inline Node( ) = default;
    inline Node(value_t const& data) : data_(new value_t(data)) { }
    inline Node(value_t&& data) : data_(std::move(data)) { }
    inline Node(value_t const& data, Node<value_t> const* node)
            : data_(new value_t(data)), next_(new Node<value_t>(node)) { }
    inline Node(value_t&& data, Node<value_t> const* node)
            : data_(std::move(data)), next_(new Node<value_t>(node)) { }

    inline Node(Node<value_t> const& other)
            : data_(new value_t(other.data_)), next_(new Node(other.next_)) { }

    virtual ~Node( ) = default;


  private:
    value_t data_ { };
    Node<value_t>* next_ { nullptr };

    inline Node(Node<value_t> const* node)
            : data_(node->data_), next_(new Node<value_t>(node->next)) { }


  friend void swap(Node<value_t>& lhs, Node<value_t>& rhs) {
      using std::swap;
      swap(lhs.data_, rhs.data_);
      swap(*(lhs.next_), *(lhs.next_));
  }

};

} // namespace single_link

#endif  // LEARN_COPY_MOVE_INCLUDE_SINGLE_LINK_NODE_H_
