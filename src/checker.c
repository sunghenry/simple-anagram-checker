#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "checker.h"
#include "main.h"

void clean(char *str)
{
  char cleaned[ENOUGH];
  filter_lexicographical(cleaned, str);
  sort_lexicographical(cleaned);
  strcpy(str, cleaned);
}

void filter_lexicographical(char *filtered, char *raw)
{
  int index = 0;
  for (int i = 0; i < strlen(raw); i++) {
    if (isalpha(raw[i])) {
      filtered[index] = tolower(raw[i]);
      index++;
    }
  }
  filtered[index] = '\0';
}

void sort_lexicographical(char *str)
{
  for (int i = 0; i < strlen(str); i++) {
    for (int j = 0; j < strlen(str); j++) {
      if (str[i] < str[j]) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
      }
    }
  }
}

int compare(char *str1, char *str2)
{
  if (!strcmp(str1, str2))
    return 0;
  return -1;
}
