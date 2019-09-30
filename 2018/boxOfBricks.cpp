#include <iostream>

  int main(void) {
    unsigned int numberOfStacks, sum, avg, moves, iteration;
    iteration = 0;
    while(true){
        iteration++;
        sum = 0;
        avg = 0;
        moves = 0;
        std::cin >> numberOfStacks;
        if(numberOfStacks == 0){
            break;
        }

        int allStacks[numberOfStacks];
        for(int &stackHeight: allStacks){
            std::cin >> stackHeight;
            sum += stackHeight;
        }
        avg = sum/numberOfStacks;
        for(int stackHeight: allStacks){
            avg < stackHeight ? moves += stackHeight - avg : moves += avg - stackHeight;
        }

        printf("Set #%d\n", iteration);
        printf("The minimum number of moves is %d.\n\n", moves/2);

    }

    return 0;
  }