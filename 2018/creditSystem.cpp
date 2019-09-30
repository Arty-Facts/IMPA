#include <iostream>

int main(void)
{
    unsigned int testcases, students;
    int sum, cur, next, temp;
    std::cin >> testcases;
    for(int i = 0; i < testcases; i++){
        std::cin >> students;
        std::cin >> cur;
        sum = 0;

        for(int i = 1; i < students; i++){
            std::cin >> next;
            temp =  cur - next;
            sum = temp > sum || sum == 0? temp : sum;
            cur = cur > next ? cur : next; 
        }
        std::cout << sum << std::endl;
       
    }
    
    return 0;
}