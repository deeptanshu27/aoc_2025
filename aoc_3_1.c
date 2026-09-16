#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *input_file = fopen("input", "r");
  
  char ch;
  int nums[2] = {-1, -1};
  int temp_nums[2] = {-1, -1};
  int sum = 0;
  while ((ch = getc(input_file)) != EOF) {
    switch (ch) {
      case '\n':
        if (nums[1] == -1) {
          nums[0] = temp_nums[0];
          nums[1] = temp_nums[1];
        }
        sum += nums[0] * 10 + nums[1];;
        nums[0] = nums[1] = 0;
        break;
      default:
        int n = ch - '0';

        // if u find a digit which is larger than nums[0], set nums[0] to that digit
        // and set nums[1] to -1 so it can be replaced by the next digit
        // however before that, check if the digit > nums[1] and if so replace nums[1]
        // with that digit in a temporary variable else leave nums[1] as is
        // and store that new temporary digit in a temporary variable jsut incase
        // that the digit is the last in the sequence

        if (n > nums[0]) {
          // check for nums[1] also
          if (n > nums[1]) temp_nums[1] = n;
          else temp_nums[1] = nums[1];
          // make temp
          temp_nums[0] = nums[0];

          // make non_temp
          nums[0] = n;
          nums[1] = -1;
        } else if (n > nums[1]) {
          nums[1] = n;
        }

        break;
    }
  }

  printf("sum: %d\n", sum);

  return 0;
}