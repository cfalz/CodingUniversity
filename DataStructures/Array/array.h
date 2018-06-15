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

struct MyArray* init_array(void) {
    struct MyArray* a = (struct MyArray*) malloc(sizeof(struct MyArray));
    a->size = 0;
    a->capacity = kMinCapacity;
    a->data = (int*) malloc(a->capacity * sizeof(int));
    memset(a->data,0,a->capacity * sizeof(int));
    return a;
}

struct MyArray* init_array_capacity(int new_capacity) {
    struct MyArray* a = (struct MyArray*) malloc(sizeof(struct MyArray));
    a->size = 0;
    a->capacity = new_capacity;
    a->data = (int*) malloc(a->capacity * sizeof(int));
    memset(a->data,0,a->capacity * sizeof(int));
    return a;
}

void print_array(struct MyArray* a) {
    for(int i = 0; i < a->capacity; i++) {
        printf("%d : %d\n", i, *(a->data+i));
    }
}

int capacity(struct MyArray* a) {
    return a->capacity;
}

int size(struct MyArray* a) { 
    return a->size;
}

int is_empty(struct MyArray* a) {
    if(a->size > 0) { return 0; }
    return 1;
}

int at(struct MyArray* a, int index) {
    if(index > (a->size - 1)) { return -1; } 
    return *(a->data + index);
}

void resize(struct MyArray* a);

void push(struct MyArray* a, int element) {
    if(a->size == a->capacity) { resize(a); }
    *(a->data + a->size) = element;  
    a->size++; 
}

void resize(struct MyArray* a) {
    int* b = (int*) malloc(kGrowthFactor * a->capacity * sizeof(int));
    memset(b,0,kGrowthFactor * a->capacity * sizeof(int));
    for(int i = 0; i < a->size; i++) {
        *(b+i) = *(a->data + i);    
    }
    free(a->data);
    a->data = b;
    a->capacity = kGrowthFactor * a->capacity;
}

int insert(struct MyArray* a, int index, int element) {
    if(a->size == a->capacity) { resize(a); }
    if(index < a->capacity) {
        for(int i = a->size - 1; i > index-1; i--) {
            *(a->data + i + 1) = *(a->data + i);
        }
        *(a->data + index) = element;
        a->size++;
        return 1;
    }
    return 0;
}

void prepend(struct MyArray *a, int element) {
    if(a->size == a->capacity) { resize(a); }
    insert(a,0,element);
}

int pop(struct MyArray *a) {
    int temp = *(a->data + a->size - 1);
    *(a->data + a->size - 1) = 0;
    a->size--;
    return temp;
}

int delete(struct MyArray *a, int index) {
    if(index < a->size) {
        for(int i = index; i < a->size - 1; i++) {
            *(a->data + i) = *(a->data + i + 1);            
        }
        *(a->data + a->size - 1) = 0;
        a->size--;
        return 1;
    }
    return 0;
}


void remove_element(struct MyArray *a, int element) {
    if(a->size > 0) {
        int i = 0;
        while(i < a->size) {
            if(*(a->data+i) == element) { delete(a,i); }
            else { i++; }
        }
    }
}


