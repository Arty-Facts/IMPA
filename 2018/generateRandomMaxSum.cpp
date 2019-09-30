#include <iostream>
#include <unordered_map>
#include <string>
#include <chrono>

int main(void)
{
    auto begin = std::chrono::high_resolution_clock::now();
    unsigned int worldsize;
    int inp;
    long int subWorldCount,curCount, max, subMax;
    std::cin >> worldsize;
    int world[worldsize][worldsize];
    //std::unordered_multimap<std::string, int>  subCost = {};
    //std::unordered_map<std::string,int>::iterator foundSubSet;
    //std::string tmp;
    max = 0;
    for(int x = 0; x < worldsize; x++){
        for(int y = 0; y < worldsize; y++){
            std::cin >> inp;
            world[x][y] = inp;
            max += inp;
        }
    }
    std::cout << max << std::endl;
    for(int x = 0; x < worldsize; x++){
        for(int y = 0; y < worldsize; y++){
            // for every tile 
            //subCost.clear();
            //subCost.reserve((worldsize-x)*(worldsize-y));
            subWorldCount = 0;
            for(int i = x; i < worldsize; i++){
                for(int j = y; j < worldsize; j++){
                    //curent value of the kolum
                    subWorldCount += world[i][j];
                    //get value of the full rektangel
                    //tmp = std::to_string(x)+ std::to_string(y)+ "-" + std::to_string(i-1)+ std::to_string(j);
                    //foundSubSet = subCost.find(tmp);
                    //calc rektangel value
                    //if (foundSubSet != subCost.end()) {
                    //    curCount = foundSubSet->second + subWorldCount;
                    //} else {
                    //    curCount = subWorldCount;
                    //}
                    //att value to hase table;
                    //tmp = std::to_string(x)+ std::to_string(y)+ "-" + std::to_string(i)+ std::to_string(j);
                    //subCost.insert({tmp, curCount});
                    max = max < curCount ? curCount: max;
                }
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Exicution took "
    << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count()
    << " seconds." << std::endl;

    std::cout << max << std::endl;

    
    return 0;
}
