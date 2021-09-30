#include <stdlib.h>
#include <stdio.h>
#include "history.h"
#include "tokenizer.h"


List* init_history(){

  List *head = (List*)malloc(sizeof(List)); /*allocate space for the list*/
  head->root = NULL;
  return head;
}


char *str_copy(char *str){

  char *end = str;

  while(*end != '\0'){
    end++;
  }
  int len = end-str-1;
  return copy_str(str,len);

}

/*add an item to the end of the list*/

void add_history(List *list, char*str){
  char *copy = str_copy(str);

  if (list->root == NULL) {
    list->root = (Item*) malloc(sizeof(Item));
    list->root->id = 1;
    list->root->str = copy;
    list->root->next = NULL;

  } else {
    Item* current;
    current = list->root;

    while (current->next != NULL) {
      current = current->next;

    }

    current->next = (Item*) malloc(sizeof(Item));
    current->next->id = current->id+1;
    current->next->str = copy;
    current->next->next =NULL;

  }

}


char *get_history(List *list, int id){

  Item* current = list->root;
  while(current != NULL){

    if(current->id == id){
      return current->str;
    }

    if(current->next == NULL){
      return "OutOfBounds";
    }



    else{
       current = current->next;

    }

  }
  
}


void print_history(List *list){

  Item *current = list->root;

  while(current != NULL){
    printf("%d.- %s \n", current->id, current->str);
    current= current->next;
  }
  
}




void free_history(List *list){

  Item *current = list->root;

  while(current != NULL){
    free(current->str);
    free(current);
    current = current->next;
  }

  free(list);

}
