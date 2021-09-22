#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


int main()

{

  char **tokens = tokenize("My dogs have fleas\0");

  print_tokens(tokens);

}


int space_bar(char c)

{

  if(c == ' ' || c == '\t') {

    return 1;

  }

  else {

    return 0;

  }

}



int non_space_char(char c)

{

  if(!space_bar(c)){

    return 1;

  }

  else{

    return 0;

  }

}


char *word_start(char *str)

{

  char *temp = str;


  while ((*temp) != '\0' && space_bar(*temp)) {

    temp++;

  }



  return temp;

}

//also look for a space to

char *word_terminator(char *word)

{

  char *temp = word;



  while (1) {

    if ((*temp) == '\0') {

      return temp;

    }

    else {

      temp++;

    }

  }

}



int count_words(char *str)

{

  char *temp = str;

  char *end = word_terminator(str);

  int count = 0;



  while (temp < end) {

    if (non_space_char(*temp)) {

      temp++;



      while (non_space_char(*temp)) {

         temp++;

      }

      count++;

    }

    temp++;

  }

  return count;

}



char *copy_str(char *inStr, short len)

{

  char *p = malloc(sizeof(*inStr) * len + 1);

  char *temp = inStr;



  for (int i = 0; i<len; i++) {

    *(p+i) = *temp;

    temp++;

  }



  *(p + len) = '\0';



  return p;

}



char **tokenize(char *str)

{



  int numOfWords = count_words(str);

  char **tokens = malloc((numOfWords + 1) * sizeof(char *));

  char *temp = str;

  char *terminator = word_terminator(str);

  int wordSize;



  for (int i = 0; i<numOfWords; i++) {

    wordSize = 0;

    char *start;



    temp = start = word_start(temp);



    while (non_space_char(*temp) && temp != terminator) {

      temp++;

      wordSize++;

    }



    char word[wordSize];



    for (int i = 0; i<wordSize; i++) {

      word[i] = *(start++);



    }



    word[wordSize] = '\0';



    tokens[i] = copy_str(word, wordSize);

  }



  tokens[numOfWords] = NULL;

  return tokens;

}



void print_tokens(char **tokens)

{

  char **temp = tokens;



  while (*temp != NULL) {

    printf("%s\n", *(temp++));

  }

}



void free_tokens(char **tokens)

{

  char **temp = tokens;



  while (*temp != NULL) {

    free(*temp);

  }



  free(tokens);

}
