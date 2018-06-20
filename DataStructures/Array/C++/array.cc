#include "array.h"

using namespace CF;

template <class T>
Array<T>::Array(){
    this->data = new T[SIZE];
    this->size = 0;
    this->capacity = SIZE;
}

template <class T>
Array<T>::~Array() { delete [] this->data; }


template <class T>
void Array<T>::push(T element) {
    if(this->size == this->capacity) { this->resize(); }
    *(this->data + size) = element;
    this->size++;
}

template <class T>
T Array<T>::at(int index) {
    assert(index < this->size);
    return *(this->data + index);
}

template <class T>
void Array<T>::print_array() {
    if(this->size > 0) {
        for(int i = 0; i < this->capacity; i++) {
            cout << i << " : " << *(this->data + i) << endl;
        }
    }
}

template <class T>
void Array<T>::insert(int index, T element) {
    assert(index > -1 and index <= this->size);
    if(this->size == this->capacity) { this->resize(); }
    for(int i = size; i > index; i--) {
        *(this->data + i) = *(this->data + i - 1);
    }
    *(this->data + index) = element;
    this->size++; 
}

template <class T>
void Array<T>::prepend(T element) {
    insert(0,element);
}

template <class T>
T Array<T>::pop() {
    assert(this->size > 0);
    T element = *(this->data + size - 1);
    this->size--;
    return element;
}


template <class T>
void Array<T>::resize() {
    T* temp = new T[kGrowthFactor * this->capacity];
    for(int i = 0; i < this->size; i++) {
        *(temp + i) = *(this->data + i);
    }
    delete this->data;
    this->data = temp;
    this->capacity = kGrowthFactor * this->capacity;
}

template <class T>
void Array<T>::delete_element(int index) {
    assert(index < this->size);
    for(int i = index; i < this->size - 1; i++) {
       *(this->data + i) = *(this->data + i + 1);  
    }
    *(this->data + size - 1) = 0;
    this->size--;
}

template <class T>
int Array<T>::find_element(T element) {
    for(int i = 0; i < this->size; i++) {
        if(*(this->data + i) == element) { return i; }
    }
    return -1;

}

/*
template <class T>
void Array<T>::remove(T element) {
    int i = 0;
    while(i < this-size) {
        if(*(this->data + i) == element) { delete(i); }
    }
}
*/

template <class T>
void Array<T>::remove(T element) {
    while(find_element(element) != -1) { delete_element(element); }
}

Array<int>* array_setup() {
    Array<int> *a = new Array<int>();
    return a;
}

bool test_push() {
    Array<int>* a = array_setup();
    a->push(1);
    a->push(2);
    a->push(3);

    if(a->get_size() != 3) { return 0; }
    if(a->at(0) != 1) { return 0; }
    if(a->at(1) != 2) { return 0; }
    if(a->at(2) != 3) { return 0; }
    a->print_array();
    return 1;

}

bool test_insert() {
    Array<int>* a = array_setup();
    for(int i = 0; i < 20; i++) {
        a->insert(i,i);
    }
    a->insert(0,10);
    if(a->get_size() != 21) { return 0; }
    if(a->at(0) != 10) { return 0; }
    a->print_array();
    return 1;
}

bool test_resize() {
    Array<int>* a = array_setup();
    for(int i = 0; i < 20; i++) {
        a->push(i);
    }
    if(a->get_size() != 20) { return 0; }
    if(a->get_capacity() != 32) { return 0; }
    return 1;
}

bool test_pop() {
    Array<int>* a = array_setup();
    for(int i = 0; i < 5; i++) {
        a->push(i);
    }
    if(a->pop() != 4) { return 0; }
    if(a->get_size() != 4) { return 0; }
    return 1;
}


bool test_delete_element() {
    Array<int>* a = array_setup();
    for(int i = 0; i < 16; i++) {
        a->push(i);
    }
    a->delete_element(0);
    a->print_array();
    if(a->get_size() != 15) { return 0; }
    if(a->at(0) != 1) { return 0; }
    if(a->at(1) != 2) { return 0; }
    if(a->at(2) != 3) { return 0; }
    if(a->at(3) != 4) { return 0; }
    return 1;
}

bool test_find() {
    Array<int>* a = array_setup();
    for(int i = 0; i < 16; i++) {
        a->push(i);
    }
    assert(a->find_element(0) == 0);
    assert(a->find_element(4) == 4);
    assert(a->find_element(15) == 15);
    assert(a->find_element(20) == -1);
    return 1;
}

bool test_remove() {
    Array<int>* a = array_setup();
    for(int i = 0; i < 5; i++) {
        a->push(5);
    }
    a->remove(5);
    assert(a->get_size() == 0);
    for(int i = 0; i < 5; i++) {
        a->push(i);
    }
    a->remove(0);
    a->remove(4);
    assert(a->at(0) == 1);
    assert(a->at(3) == 3);
    return 1; 
}
