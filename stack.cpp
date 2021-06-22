#include <iostream>
#include "node.h"
#include "stack.h"

template <class Type>
Stack<Type>::Stack(){
    topo=nullptr;
    n=0;
}

template <class Type>
Stack<Type>::~Stack(){
    this->clear();
}

template <class Type>
bool Stack<Type>::push(Type *obj){
    Node<Type> *P;
    P = Node<Type>::montaNode(obj);

    if(P){
        P->next=this->topo;
        topo=P;
        n++;
        return true;
    }
    return false;
}

template <class Type>
bool Stack<Type>::pop(Type *obj){
    if(topo){
        Node<Type> *P = topo;
        topo=P->next;
        Node<Type>::desmontaNode(P, obj);
        n--;
        return true;
    }
    return false;
}

template <class Type>
bool Stack<Type>::top(Type *obj){
    if(topo){
        *obj=topo->obj;
        return true;
    }
    return false;
}

template <class Type>
bool Stack<Type>::isEmpty(){
    return !topo;
}

template <class Type>
void Stack<Type>::clear(){
    Node<Type> *P;
    while(topo){
        P = topo;
        topo = P->next;
        delete P;
    }
    n=0;
}

template <class Type>
int Stack<Type>::getElements(){
    return n;
}

template class Stack<int>;
template class Stack<float>;
template class Stack<double>;
template class Stack<long>;
template class Stack<std::string>;
template class Stack<char>;
template class Stack<bool>;