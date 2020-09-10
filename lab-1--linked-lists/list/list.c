// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

list_t *list_alloc() {
  node_t * node =(node_t *)malloc(sizeof(node_t));
  list_t * list = malloc(sizeof(list_t));
  node = NULL;
  list -> head = node;
  return list; 
}
void list_free(list_t *l) {}

void list_print(list_t *l){
  node_t* current = l -> head;

    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
}
}
int list_length(list_t *l) { 
  int sum=0;
   node_t* current = l -> head;

    while (current != NULL) {
       sum = 1 +sum;
        current = current->next;
}
  return sum;
}

void list_add_to_back(list_t *l, elem value) {
    node_t * current = l -> head;
    if (current != NULL){
      while (current->next != NULL) {
        current = current->next;
    }
    current->next = (node_t *)malloc(sizeof(node_t));
    current->next->value = value;
    current->next->next = NULL;
    }else{
      node_t* node = (node_t *)malloc(sizeof(node_t));
      node -> value = value;
      l-> head = node;
    }   
}
void list_add_to_front(list_t *l, elem value) {
  node_t * new = (node_t *)malloc(sizeof(node_t));
  new ->value = value;
  if(l -> head !=NULL){
  node_t * head = l -> head;
  node_t * temp = head;
  l->head = new;
  new -> next = temp;
  }else{
    l->head = new;
  }
}
void list_add_at_index(list_t *l, elem value, int index) {
    node_t * current = l -> head;
    int count =1; 
      while (count <index) {
        current = current->next;
        count ++;
    }
    node_t * new = (node_t *)malloc(sizeof(node_t));
    new -> value = value;
    node_t * temp = current -> next;
    current->next = new;
    new -> next = temp;
     
}

elem list_remove_from_back(list_t *l) { 
  node_t * current = l ->head;
  while (current->next->next != NULL) {
        current = current->next;
    }
  int value = current->next->value;
  current->next = NULL; 
  return value;
}
elem list_remove_from_front(list_t *l) { 
  node_t * current = l ->head;
  int value = current -> value;
  l->head = current->next;
  return value; 
                                       }
elem list_remove_at_index(list_t *l, int index) {
  node_t * current = l ->head;
  int count =1; 
      while (count <index) {
        current = current->next;
        count ++;
    }
  int value = current -> next -> value;
  current -> next = current -> next -> next;
  return value;
}

bool list_is_in(list_t *l, elem value) { 
  node_t * current = l ->head;
  while (current->next != NULL) {
        if(current -> value == value){
          return true;
        }
        current = current->next;
    }
  return false;
}
elem list_get_elem_at(list_t *l, int index) {
  node_t * current = l ->head;
  int count =0; 
      while (count <index) {
        current = current->next;
        count ++;
    } 
  return current -> value;
}
int list_get_index_of(list_t *l, elem value) { 
 node_t * current = l ->head;
  int count = 0;
  while (current->next != NULL) {
        if(current -> value == value){
          return count;
        }
        current = current->next;
        count ++;
    }
  return -1;
}