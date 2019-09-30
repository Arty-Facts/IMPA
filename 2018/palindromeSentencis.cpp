#include <iostream>
#include <string>
#include <stack>
#include <queue>

int main(void)
{
    while(true){
        std::string sentences;
        std::stack <char> LTR;
        std::queue <char> RTL;
        bool finish = true;


        std::getline (std::cin,sentences);
        if (sentences == "DONE"){
            break;
        }
        
        for(int i = 0; i < sentences.length(); ++i)
        {
            if ((sentences[i] >= 'a' && sentences[i]<='z') || (sentences[i] >= 'A' && sentences[i]<='Z'))
            {
                LTR.push(tolower(sentences[i]));
                RTL.push(tolower(sentences[i]));
            }
        }
        for (int i = 0; i < LTR.size(); ++i){
            if( LTR.top() == RTL.front()){
                LTR.pop();
                RTL.pop();
                continue;
            }else{
                std::cout << "Uh oh.." << std::endl;
                finish = false;
                break;
            }   
        }
        if (finish){
            std::cout << "You won't be eaten!" << std::endl;
        }
    }

    
    return 0;
}