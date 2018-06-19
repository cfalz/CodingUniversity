#include "array.h"

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
        for(int i = 0; i < this->size; i++) {
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



