#include <stdio.h>

int main() {
  int choice;

  scanf("%d", &choice);
  choice>5?(void)0:choice;

  printf("You entered the number %d.\n", choice);

  return 0;
}