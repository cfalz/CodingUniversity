#ifndef ARRAY_H
#define ARRAY_H

#define SIZE 16
#define kGrowthFactor 2

#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;


template <class T>
class Array {

    public:
        Array();
        ~Array();

        void push(T element);
        bool is_empty() { return (this->size == 0); }
        T at(int index);
        void insert(int index, T element);
        void prepend(T element);
        T pop();
        void print_array();

        //Accessors
        int get_size() { return this->size; }
        int get_capacity() { return this->capacity; }

    private:
        T* data;
        int size;
        int capacity;

        void resize();

};

Array<int>* array_setup();
bool test_push();
bool test_insert();
bool test_resize();

#endif //ARRAY_H


