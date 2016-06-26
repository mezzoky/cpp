#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H


template <class Any>
class List;
template <class Any>
class Iterator;


template <class Any>
class Node {
public:
    Node(Any s);
private:
    Any data;
    Node<Any>* prev;
    Node<Any>* next;
friend class List<Any>;
friend class Iterator<Any>;
};


template <class Any>
class List {
public:
    List();
    void push_back(Any data);
    void insert(Iterator<Any> iter, Any s);
    void clear();
    Iterator<Any> erase(Iterator<Any> pos);
    Iterator<Any> begin();
    Iterator<Any> end();
private:
    Node<Any>* first;
    Node<Any>* last;
friend class Iterator<Any>;
};


template <class Any>
class Iterator {
public:
    Iterator();
    Any get() const;
    Iterator<Any>& next();
    Iterator<Any>& prev();
    bool equals(Iterator<Any> b) const;
private:
    Node<Any>* position;
    List<Any>* container;
friend class List<Any>;
};

#endif // LINKEDLIST_H
