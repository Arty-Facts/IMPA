#include <iostream>

  int main(void) {
    unsigned long int a, b;
  
    while(std::cin >> a >> b) {
      if (a < b)
        std::cout << b-a << std::endl;
      else
        std::cout << a-b << std::endl;
    }

    return 0;
  }