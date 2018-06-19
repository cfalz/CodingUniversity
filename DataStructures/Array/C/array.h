#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int kMinCapacity = 16;
const int kGrowthFactor = 2;

struct MyArray {
    int size;
    int capacity;
    int* data;
};

struct MyArray* init_array(void);

struct MyArray* init_array_capacity(int new_capacity);

void print_array(struct MyArray* a);

int capacity(struct MyArray* a);

int size(struct MyArray* a); 

int is_empty(struct MyArray* a);

int at(struct MyArray* a, int index);

void resize(struct MyArray* a);

void push(struct MyArray* a, int element);

void resize(struct MyArray* a);

int insert(struct MyArray* a, int index, int element);

void prepend(struct MyArray *a, int element);

int pop(struct MyArray *a);

int delete(struct MyArray *a, int index);

void remove_element(struct MyArray *a, int element);

int find_element(struct MyArray *a, int element);

void test_init();

void test_push_and_at();

void test_push_overflow();

void test_insert();

void test_prepend();

void test_pop();

void test_delete();

void test_remove_element();

void test_find_element();

#endif //ARRAY.H

