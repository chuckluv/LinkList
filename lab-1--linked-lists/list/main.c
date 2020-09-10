#include <stdio.h>

#include "list.h"

int main() {
  list_t *head = list_alloc();
  printf("Tests for linked list implementation\n");
  list_add_to_back(head, 5);
  list_add_to_back(head, 3);
  list_add_to_back(head, 9);
  list_add_to_front(head,12);
  list_print(head);
  printf("Change\n");
  list_add_at_index(head,7,2);
  list_print(head);
  printf("Change\n");
  list_remove_from_back(head);
  list_print(head);
  printf("Change\n");
  list_remove_from_front(head);
  list_print(head);
  printf("Change\n");
  list_remove_at_index(head,0);
  list_print(head);
  printf("Change\n");
  list_add_to_back(head,85);
  list_add_to_back(head, 36);
  list_add_to_back(head, 90);
  list_print(head);
  printf("Print\n");
  printf("%d\n",list_is_in(head,5));
  printf("%d\n",list_is_in(head,8));
  printf("%d\n",list_get_elem_at(head,3));
  printf("%d\n",list_get_index_of(head,3));
  printf("The Lenght of the Link List: %d\n", list_length(head));
  return 0;
}