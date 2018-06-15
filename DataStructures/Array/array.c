#include "array.h"

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

int main(void) {

    test_remove_element();
    return 0;
}


