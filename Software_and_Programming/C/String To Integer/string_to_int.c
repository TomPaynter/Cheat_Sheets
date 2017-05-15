#include <stdio.h>

int main(void) {
  printf("Input Int array: ");

  char continue_q = 1, array_length = 0, i;

  int a[100];

  int bob;
  //continue_q = scanf("%i", &bob);
  printf("%d", bob);

  for(i = 0; continue_q && i < 100;  i++) {
    scanf("%d", &a[i]);
    if (a[i] == '\n')
      continue_q = 0;
    else
      continue_q = 1;
  }

  array_length = i;

  printf("\n Array length: %i \n", array_length);

  return 0;
}
