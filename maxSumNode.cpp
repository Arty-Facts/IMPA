#include <iostream>
#include <chrono>
#include <queue>


class Node 
{ 
    public: 
    int startX;
    int startY;
    int endX;
    int endY;
    int mode;
    long int* max; 
    long int pMax;
      
    //Default Constructor 
    Node(){
        startX = 0;
        endX = 0;
        startY = 0;
        endY = 0;
        max = 0;
        pMax = 0;
        mode = 0;
    }
    Node(int fromX,int fromY, int toX, int toY,long int* curMax,long int parentMax,int exec) 
    { 
        startX = fromX;
        endX = toX;
        startY = fromY;
        endY = toY;
        max = curMax;
        pMax = parentMax;
        mode = exec;
    } 
      
}; 

void expandNode(Node* node,std::queue <Node>*);

int main(void)
{
    auto begin = std::chrono::high_resolution_clock::now();
    unsigned int worldsize;
    std::cin >> worldsize;
    long int GlobalMax = 0;
    int world[worldsize][worldsize];
    int inp;
    int maxVal = 5;
    long int* max = &GlobalMax;
    for(int x = 0; x < worldsize; x++){
        for(int y = 0; y < worldsize; y++){
            std::cin >> inp;
            world[x][y] = inp;
            *max += inp;
        }
    }
    std::cout << GlobalMax << std::endl;
    std::queue <Node> frontier;
    Node root(0,0,worldsize,worldsize,max,GlobalMax,0); 
    expandNode(&root, &frontier);

    while(!frontier.empty()){
    //for(int i = 0; i < 16;i++){
        //std::cout << frontier.size() << std::endl;
        Node tmp = frontier.front();
        frontier.pop();
        long int sum=0;
        //std::cout << tmp.mode << std::endl;
        switch (tmp.mode){
            case 1:{
                for(int y = tmp.startY; y < tmp.endY; y++){
                    sum += world[tmp.startX-1][y];
                }
                break;
            }
            case 2:{
                for(int x = tmp.startX; x < tmp.endX; x++){
                    sum += world[x][tmp.startY-1];
                }
                break;
            }
            case 3:{
                for(int y = tmp.startY; y < tmp.endY; y++){
                    sum += world[tmp.endX][y];
                }
                //std::cout << "case 3: " << sum << std::endl;
                break;
            }
            case 4:{
                for(int x = tmp.startX; x < tmp.endX; x++){
                    sum += world[x][tmp.endY];
                }
                break;
            }
            default: std::cout << "root node" << std::endl;
        }
        int parent = tmp.pMax;
        tmp.pMax-=sum;
        //std::cout << tmp.pMax << std::endl;

        if (*max < tmp.pMax){
            *max = tmp.pMax;
            std::cout << *max << std::endl;

        }else{
            if(*max > 1.5*tmp.pMax){
                continue;
            }
        }
        expandNode(&tmp,&frontier);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Exicution took "
    << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count()
    << " seconds." << std::endl;

    std::cout << GlobalMax << std::endl;

    
    return 0;
}
void expandNode(Node* node, std::queue <Node>* frontier){
    Node nextNode1(node->startX+1,node->startY,node->endX,node->endY,node->max,node->pMax,1); 
    frontier->push(nextNode1);
    Node nextNode2(node->startX,node->startY+1,node->endX,node->endY,node->max,node->pMax,2);
    frontier->push(nextNode2); 
    Node nextNode3(node->startX,node->startY,node->endX-1,node->endY,node->max,node->pMax,3);
    frontier->push(nextNode3); 
    Node nextNode4(node->startX,node->startY,node->endX,node->endY-1,node->max,node->pMax,4);
    frontier->push(nextNode4); 
}