#include <iostream>

  int main(void) {
    unsigned int iterations, testcases;
    unsigned long int cur, temp, reversed;
    std::cin >> testcases;
    while(testcases != 0) {
      iterations = 0;
      reversed = 0;
      
      std::cin >> cur;
      do
      {
        iterations++;
        cur += reversed;
        reversed = 0;
        temp = cur;
        while(temp > 0)
        {
            reversed = reversed*10 + temp%10;
            temp /= 10;
        }

      }while(cur != reversed);
      printf("%u %lu\n", iterations-1, cur);
      testcases--;
    }

    return 0;
  }