#include <iostream>
int calcRook(int x, int y);
int calcKnight(int x, int y);
int calcQueen(int x, int y);
int calcKing(int x, int y);

int main(void)
{
    unsigned int testcases, x, y;
    char chesspiece;
    std::cin >> testcases;
    for(int i = 0; i < testcases; i++){
        std::cin >> chesspiece >> x >> y;

        switch (chesspiece){
            case 'r':{
                std::cout << calcRook(x, y) << std::endl;
                break;
            }
            case 'k':{
                std::cout << calcKnight(x, y) << std::endl;
                break;
            }
            case 'Q':{
                std::cout << calcQueen(x, y) << std::endl;
                break;
            }
            case 'K':{
                std::cout << calcKing(x, y) << std::endl;
                break;
            }
            default: std::cout << "Unknown chesspiece" << std::endl;
        }

    }
    
    return 0;
}

int calcRook(int x, int y){
    return x > y ? y : x;
}
int calcKnight(int x, int y){
    return x*y/2;
}
int calcQueen(int x, int y){
    return x > y ? y : x;
}
int calcKing(int x, int y){
    return (x/2+x%2)*(y/2+y%2);
}