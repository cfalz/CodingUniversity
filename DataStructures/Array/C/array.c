#include "array.h"

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

int find_element(struct MyArray *a, int element) {
    if(a->size > 0) {
        for(int i = 0; i < a->size; i++) {
            if(*(a->data + i) == element) { return i; }
        }
    }
    return -1;
}


void test_init() {
    struct MyArray* a = init_array();
    print_array(a);
    printf("Size: %d\n",size(a));
    printf("Capacity: %d\n",capacity(a));
}

void test_push_and_at() {
    struct MyArray* a = init_array();
    printf("Before Pushing, At 0: %d\n", at(a,0));
    printf("Pushing 5.\n"); 
    push(a,5);
    printf("Size: %d\n",size(a));
    printf("At 0: %d\n", at(a,0));
}

void test_push_overflow() {
    struct MyArray* a = init_array_capacity(2);
    printf("Capacity: %d\n",capacity(a));
    printf("Size: %d\n",size(a));
    printf("Pushing 5.\n"); 
    push(a,5);
    printf("Pushing 10.\n"); 
    push(a,10);
    printf("Pushing 15.\n"); 
    push(a,15);
    printf("Pushing 20.\n"); 
    push(a,20);
    printf("At 3: %d\n", at(a,3));
    printf("Capacity: %d\n",capacity(a));
    printf("Size: %d\n",size(a));
    printf("Pushing 25.\n"); 
    push(a,25);
    printf("Capacity: %d\n",capacity(a));
    printf("Size: %d\n",size(a));
}

void test_insert() {
    struct MyArray* a = init_array_capacity(2);
    push(a,4);
    push(a,5);
    push(a,6);
    push(a,7);
    print_array(a);
    printf("Capacity: %d\n",capacity(a));
    printf("Size: %d\n",size(a));
    printf("Inserting 20 at Index 2.\n");
    insert(a,2,20);
    printf("Size: %d\n",size(a));
    printf("Index 1: %d\n", at(a,1));
    print_array(a);
}

void test_prepend() {
    struct MyArray* a = init_array_capacity(2);
    push(a,4);
    push(a,5);
    push(a,6);
    push(a,7);
    print_array(a);
    printf("Capacity: %d\n",capacity(a));
    printf("Size: %d\n",size(a));
    printf("Prepending 20.\n");
    prepend(a,20);
    print_array(a);
}

void test_pop() {
    struct MyArray* a = init_array_capacity(2);
    push(a,4);
    push(a,5);
    push(a,6);
    push(a,7);
    print_array(a);
    printf("Pop: %d\n",pop(a));
    print_array(a);
}

void test_delete() {
    struct MyArray* a = init_array_capacity(2);
    push(a,4);
    push(a,5);
    push(a,6);
    push(a,7);
    print_array(a);
    printf("Delete Index 0.\n");
    delete(a,0);
    print_array(a);
}

void test_remove_element() {
    struct MyArray* a = init_array_capacity(2);
    push(a,5);
    push(a,5);
    push(a,5);
    push(a,5);
    push(a,5);
    print_array(a);
    printf("Remove Element 5.\n");
    remove_element(a,5);
    print_array(a);
}

void test_find_element() {
    struct MyArray* a = init_array_capacity(2);
    push(a,1);
    push(a,6);
    push(a,5);
    push(a,2);
    push(a,5);
    print_array(a);
    printf("Find Element 5: %d\n", find_element(a,5));
    printf("Find Element 1: %d\n", find_element(a,1));
    printf("Find Element 0: %d\n", find_element(a,0));
}




