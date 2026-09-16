// 0 1 2 3
// num length -- 4
// num length / 2 -- 2

#include <stdio.h>
#include <stdlib.h>

long long int calc(long long int start, long long int end) {
  long long int sum = 0;
  
  printf("-------------------------\n");
  printf("Testing: %ld %ld\n", start, end);

  if (start < 0 || end < 0) {
    printf("ERROR EROROR OEREROER EOREROEOREOROER\n");
    return -1;
  }
  
  for (long long int i = start; i < end + 1; i++) {
    int num_length = 0;
    char *full_num;

    full_num = malloc(0);

    long long int j = i;
    do {
      num_length++;
      full_num = (char*) realloc(full_num, sizeof(char) * num_length);
      full_num[num_length - 1] = (j % 10) + '0';
      j /= 10;
    } while (j != 0);

    // num_length++;
    // full_num = (char*) realloc(full_num, sizeof(char) * num_length);
    // full_num[num_length - 1] = '\0';
    
    // printf("%s\n", full_num);

    if (num_length % 2 != 0) continue;

    char *firstHalf = malloc(sizeof(char) * num_length / 2);
    char *secondHalf = malloc(sizeof(char) * num_length / 2);

    for (int i = 0; i < num_length / 2; i++) {
      firstHalf[i] = full_num[i];
    }
    for (int i = num_length / 2; i < num_length; i++) {
      secondHalf[i - num_length / 2] = full_num[i];
    }

    int matching = 1;
    for (int i = 0; i < num_length / 2; i++) {
      if (firstHalf[i] != secondHalf[i]) {
        matching = 0;
        break;
      }
    }
    if (matching) {
      printf("heh: %d\n", i);
      sum += i;
      continue;
    }

    free(firstHalf);
    free(secondHalf);
    free(full_num);
    num_length = 0;
  }

  return sum;
}

int main() {
  FILE *input_file = fopen("input", "r");
  
  char ch;
  long long int range[2] = {0, 0};
  int range_pos = 0;
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