#include "linkedlist_test.h"
#include "linkedlist_test.h"
#include "linkedlist.h"
#include "linkedlist.c"


void test_size() {
    Node* head = NULL;
    assert(size(head) == 0);
    Node* first = init_node(1);
    head = first;
    assert(size(head) == 1);
    first->next = init_node(2);
    assert(size(head) == 2);
    print_list(head);
}

void test_push_back() {
    Node* head = NULL;
    push_back(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);
    print_list(head);
}

void test_all() {
    test_size();
    test_push_back();
    printf(" \n ALL TESTS PASSED :^) \n");
}
