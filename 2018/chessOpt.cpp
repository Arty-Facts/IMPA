#include <iostream>

int main(void)
{
    unsigned int testcases, x, y;
    char chesspiece;
    std::cin >> testcases;
    for(int i = 0; i < testcases; i++){
        std::cin >> chesspiece >> x >> y;

        switch (chesspiece){
            case 'r':{
                std::cout << (x > y ? y : x) << std::endl;
                break;
            }
            case 'k':{
                std::cout << x*y/2 << std::endl;
                break;
            }
            case 'Q':{
                std::cout << (x > y ? y : x) << std::endl;
                break;
            }
            case 'K':{
                std::cout << (x/2+x%2)*(y/2+y%2) << std::endl;
                break;
            }
            default: std::cout << "Unknown chesspiece" << std::endl;
        }

    }
    
    return 0;
}
