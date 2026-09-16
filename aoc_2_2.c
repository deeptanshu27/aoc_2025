// just converted all ints to long long ints lmao

#include <stdio.h>
#include <stdlib.h>

long long int power(long long int i, long long int exp) {
  long long int res = 1;
  for (long long int j = 0; j < exp; j++) res *= i;
  return res;
}

long long int calc(long long int start, long long int end) {
  long long int sum = 0;

  for (long long int n = start; n <= end; n++) {
    long long int num_digits = 0;
    long long int temp_n = n;
    while (temp_n != 0) {
      num_digits++;
      temp_n /= 10;
    }

    for (long long int sections = 1; sections <= num_digits / 2; sections++) {
      if (num_digits % sections != 0) continue;

      long long int repeats = num_digits / sections;
      long long int num_section = n % power(10, sections);

      long long int repeat_num = 0;
      for (long long int i = 0; i < repeats; i++) {
        repeat_num += num_section * power(10, i * sections);
      }
      if (repeat_num == n) {
        printf("WE GOT A HIT!!! %d\n", n);
        sum += n;
        break;
      }
    }
  }

  return sum;
}

long long int main() {
  FILE *input_file = fopen("input", "r");
  
  char ch;
  long long int range[2] = {0, 0};
  long long int range_pos = 0;
  long long int sum = 0;
  while ((ch = getc(input_file)) != EOF) {
    switch (ch) {
      case '-':
        range_pos = 1;
        break;
      case ',':
      case '\n':
        sum += calc(range[0], range[1]);
        range_pos = 0;
        range[0] = 0;
        range[1] = 0;
        break;
      default:
        range[range_pos] *= 10;
        range[range_pos] += ch - '0';
        break;
    }
  }

  printf("sum: %lld\n", sum);

  return 0;
}