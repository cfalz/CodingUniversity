#include "linkedlist.h"

Node* init_node(int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void print_list(Node *head) {
    printf("Printing Linked List: \n");
    Node* current = head;
    while(current) {
        printf(" %d -> ", current->value);
        current = current->next;
    }
    printf("\n");
}

//returns number of data elements in list
int size(Node *head) {
    int list_size = 0;
    Node* current = head;
    while(current) { 
        list_size++; 
        current = current->next;
    }
    return list_size;
}

//adds an item at the end
void push_back(Node** head, int value) {
    if(!*head) { *head = init_node(value); return; }
    Node* current = *head;
    while(current->next) { 
        current = current->next; 
    }
    current->next = init_node(value);
}

/*
//bool returns true if empty
bool empty();

//returns the value of the nth item (starting at 0 for first)
int value_at(index);

//adds an item to the front of the list
void push_front(value);

//remove front item and return its value
int pop_front(); 


//removes end item and returns its value
int pop_back();

//get value of front item
int front();

//get value of end item
int back(); 

//insert value at index, so current item at that index is pointed to by new item at index
void insert(index, value);

//removes node at given index
void erase(index);

//returns the value of the node at nth position from the end of the list
int value_n_from_end(n);

//reverses the list
void reverse();

//removes the first item in the list with this value
void remove_value(value);
*/
