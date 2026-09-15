#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *input_file = fopen("input", "r");
  
  int multiplier = 1;
  int num = 0;
  int safe_num = 50;
  int count = 0;
  char ch;
  while ((ch = getc(input_file)) != EOF) {
    if (ch == 'L') multiplier = -1;
    else if (ch == 'R') multiplier = 1;
    else if (ch == '\n') {
      safe_num += multiplier * num;
      num = 0;
      if (safe_num % 100 == 0) count++;
    }
    else {
      num *= 10;
      num += ch - '0';
    }
  }

  printf("count: %d\n", count);

  return 0;
}