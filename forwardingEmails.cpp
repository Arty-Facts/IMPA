#include <iostream>
#include <unordered_map>

int main(void)
{
    unsigned int testcases, comunitySize;
    int from, to, curr, pathCost, pathOrigin;
    std::cin >> testcases;
    std::unordered_map<int,int>::iterator currPath;
    std::unordered_map<int,int>::const_iterator currPair;
    for(int i = 0; i < testcases; i++){
        std::cin >> comunitySize;
        pathCost = 0;
        pathOrigin = comunitySize;
        std::unordered_multimap<int, int>  forwardPars = {};
        std::unordered_multimap<int, int>  forwardsPath = {};
        forwardPars.reserve(comunitySize*2);
        forwardsPath.reserve(comunitySize*2);
        for(int j = 0; j < comunitySize; j++){
            std::cin >> from >> to;
            forwardPars.insert({from, to});
            forwardsPath.insert({j+1,0});
        }
        for(int origin = 1; origin < comunitySize + 1; origin++){
            curr = origin;
            currPath = forwardsPath.find(curr);
            if(currPath->second != 0){
                continue;
            }
            //printf("origin %d\n",origin);
            for(int steps = 0; steps < comunitySize+1; steps++){
                currPath = forwardsPath.find(curr);
                if(currPath->second == origin){
                    if (steps > pathCost){
                        pathCost = steps;
                        pathOrigin = origin;
                    }
                    //printf("break on step %d\n", steps);
                    break;
                }
                currPair = forwardPars.find(curr);
                //printf("from %d to %d\n",currPair->first, currPair->second);
                currPath->second = origin;
                curr = currPair->second;
            }

        }
        printf("Case %d: %d\n",i+1, pathOrigin);
    }
    
    return 0;
}