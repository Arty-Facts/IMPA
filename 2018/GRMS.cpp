#include <iostream>
#include <stdlib.h>

int main(void)
{
    int max = 50;
    std::cout << max <<std::endl;
    for(int x = 0; x < max; x++){
        for(int y = 0; y < max; y++){
            std::cout << ((rand() % 256 + 1) - 127) << " ";
        }
        std::cout << std::endl;
    }

    
    return 0;
}