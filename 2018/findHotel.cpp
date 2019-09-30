#include <iostream>
#include <cstdio>
#include <limits>

int main(void)
{
    unsigned int numberOfPPL, buget, numberOfHotels, amoauntOfWeeks, minCost, price, beds;

    while(std::cin >> numberOfPPL >> buget >> numberOfHotels >> amoauntOfWeeks){
        minCost = buget + 1;
        for(int i = 0; i < numberOfHotels ; i++){
            std::cin >> price;
            if (price * numberOfPPL > buget){
                std::cin.ignore();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                continue;
            }

            for(int j = 0; j < amoauntOfWeeks; j++){
                std::cin >> beds;
                if (beds < numberOfPPL){
                    continue;
                }else{
                    if (minCost > price * numberOfPPL){
                        minCost = price * numberOfPPL;
                    }
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    break;
                }
                

            }

        }
        if(minCost <= buget){
            printf("%d\n",minCost);
        }else{
            printf("stay home\n");
        }

    }

    
    return 0;
}
