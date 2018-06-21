#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


typedef struct NodeStruct {
    int value;
    struct NodeStruct* next;
} Node;

//Initialize a Node
Node* init_node(int value);

//prints the list of nodes
void print_list(Node *head);

//returns number of data elements in list
int size(Node *head);  

//bool returns true if empty
bool empty();

//returns the value of the nth item (starting at 0 for first)
int value_at(Node* head, int index);

//adds an item to the front of the list
void push_front(Node* head, int value);

//remove front item and return its value
int pop_front(Node* head, int value); 

//adds an item at the end
void push_back(Node** head, int value);

//removes end item and returns its value
int pop_back(Node* head);

//get value of front item
int front(Node* head);

//get value of end item
int back(Node* head); 

//insert value at index, so current item at that index is pointed to by new item at index
void insert(Node* head, int index, int value);

//removes node at given index
void erase(Node* head, int index);

//returns the value of the node at nth position from the end of the list
int value_n_from_end(Node* head, int n);

//reverses the list
void reverse(Node* head);

//removes the first item in the list with this value
void remove_value(Node* head, int value);
    
#endif //LINKEDLIST_H
