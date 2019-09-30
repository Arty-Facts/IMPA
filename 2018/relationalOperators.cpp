#include <iostream>

  using namespace std;

  int main(void) {
    long int testcases, a, b;

    cin >> testcases;
  
    while(testcases != 0) {
      cin >> a >> b;

      if (a < b)
        cout << "<" << endl;
      else if (a > b)
        cout << ">" << endl;
      else
        cout << "=" << endl;
    
      testcases--;
    }

    return 0;
  }