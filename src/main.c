#include <stdio.h>
#include "main.h"
#include "parser.h"
#include "checker.h"

int main(void)
{
  char s1[ENOUGH];
  char s2[ENOUGH];

  parse(s1, s2);

  clean(s1);
  clean(s2);

  int result = compare(s1, s2);
  if (!result)
    printf("anagram\n");
  else
    printf("not anagram\n");

  return 0;
}
