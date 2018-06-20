#ifndef ARRAY_H
#define ARRAY_H

#define SIZE 16
#define kGrowthFactor 2

#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;

namespace CF {

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
        void delete_element(int index);
        int find_element(T element);
        void remove(T element);
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

}

CF::Array<int>* array_setup();
bool test_push();
bool test_insert();
bool test_resize();
bool test_delete_element();
bool test_find();
bool test_remove();

#endif //ARRAY_H

