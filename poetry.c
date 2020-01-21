#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1024

int main() {
  char str[MAX_LENGTH], poem[MAX_LENGTH][MAX_LENGTH];
  int length;
  int len = 0;
  int line = 1;
  int i, j, k[line];
  int l = 0;

  printf("Enter the poem:\n");

  do {
    fgets(str, MAX_LENGTH, stdin); /*Takes user's input with spaces becoming newlines*/
    length = strlen(str);
    if(str[length-1] == '\n') /*finds the newline and replaces with a 0*/
    {
      str[length-1] = 0;
    }
    if(strcmp(str, ".") != 0)
    {
      strcat(str, " "); /*adds a space when replacing a newline*/
    }
    strcpy(poem[line], str);
    line++;
  } while(strcmp(str, ".") != 0);

 line = line - 1; /*removes the singular period line so only the line size of the poem is counted*/
 for(i = 1; i <= line; i++)
  {
    for(j = 0; j < strlen(poem[i]); j++)
    {
      if(poem[i][j] == ' ' && (isalnum(poem[i][j-1]) || ispunct(poem[i][j-1]))) /*checks the current as well as the previous values as when there is a space, if there is either a punctuation, letter, or number it increases in number of words*/
      {
        len++;
        l++;
        k[i] = l;
      }
    }
  }

  printf("%d words in %d lines\n", len, line);
  for(i = 1; i < line; i++)
  {
    if(i == 1)
    {
      printf("%d ", k[i]);
    }
    else
    {
      printf("%d ", k[i] - k[i-1]);
    }
  }
  printf("\n");
  return 0;
}
