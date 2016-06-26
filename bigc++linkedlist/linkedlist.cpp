#include <iostream>
#include <cassert>
#include "linkedlist.h"


template <class Any>
Node<Any>::Node(Any s) {
    data = s;
    prev = NULL;
    next = NULL;
}

template <class Any>
List<Any>::List() {
    first = NULL;
    last = NULL;
}

template <class Any>
void List<Any>::push_back(Any data) {
    Node<Any>* new_node = new Node<Any>(data);
    if (last == NULL) {
        first = new_node;
        last = new_node;
        return;
    }
    new_node->prev = last;
    last->next = new_node;
    last = new_node;
}

template <class Any>
void List<Any>::insert(Iterator<Any> iter, Any s) {
    if (iter.position == NULL) {
        push_back(s);
        return;
    }
    Node<Any> *after = iter.position;
    Node<Any> *before = after->prev;
    Node<Any> *new_node = new Node<Any>(s);
    new_node->prev = before;
    new_node->next = after;
    (*after).prev = new_node;
    if (before == NULL) {
        first = new_node;
    } else {
        before->next = new_node;
    }
}
template <class Any>
void List<Any>::clear() {
    Node<Any> *p, *q;
    if (last == NULL) {
        return;
    }
    p = first;
    while (p) {
        q = p->next;
        delete p;
        p = NULL;
        p = q;
    }
    last = NULL;
}
template <class Any>
Iterator<Any> List<Any>::erase(Iterator<Any> pos) {
    
}
template <class Any>
Iterator<Any> List<Any>::begin() {
    Iterator<Any> iter;
    iter.position = first;
    iter.container = this;
    return iter;
}
template <class Any>
Iterator<Any> List<Any>::end() {
    Iterator<Any> iter;
    iter.position = NULL;
    iter.container = this;
    return iter;
}

template <class Any>
Iterator<Any>::Iterator() {
    position = NULL;
    container = NULL;
}

template <class Any>
Iterator<Any>& Iterator<Any>::next() {
    assert(position != NULL);
    position = position->next;
    return *this;
}
template <class Any>
Iterator<Any>& Iterator<Any>::prev() {
    assert(position != container->first);
    if (position == NULL) {
        position = container->last;
    } else {
        position = position->prev;
    }
    return *this;
}
template <class Any>
Any Iterator<Any>::get() const {
    assert(position != NULL);
    return position->data;
}
template <class Any>
bool Iterator<Any>::equals(Iterator<Any> b) const {
    return position == b.position;
}
