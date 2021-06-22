#pragma once
#include "node.h"

template <class Type>
class Stack{
    private:
        Node<Type> *topo;
        int n;
    public:
        Stack();
        ~Stack();
        bool push(Type *obj);
        bool pop(Type *obj);
        bool top(Type *obj);
        bool isEmpty();
        void clear();
        int getElements();
};