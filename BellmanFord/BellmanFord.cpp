#include <iostream>
#include <limits.h> //so we know an infinite for max
//This could have not been done without the psuedocode provided within the 
textbook! If you have any questions, please email me at redwards5@ucmerced.edu //
//From Psuedocode from Lec and textbook
void initial_single_source(int *d, int NV){
        for(int i = 0; i < NV; i++) {
        d[i] = INT_MAX;
    }
    d[0] = 0;
}
//Bellman_Ford structure has been given in psuedocode: Bellman Ford --> 
Initial_Single_Source --> Relax//
//Next for loop would indicate false value
void Bellman_Ford(int ** G, int NV, int NE){
    int i;
    int j;
    int bellman = 1;
    int d[NV];
    
    initial_single_source(d, NV);
    
    for(i = 0; i < NV - 1; i++) {
        for(j = 0; j < NE; j++) {
            int u = G[0][j]; //Start of Relax PsuedoCode
            int v = G[1][j];
            int w = G[2][j];
             if(d[u] != INT_MAX) {
                 if(d[v] > d[u] + w){
                 d[v] = d[u] + w; //End of Relax PsuedoCode
                    }
                }
            }
        }
    
    for(j = 0; j < NE; j++) { //Start of second part of Bellman_Ford function 
psuedocode
      int u = G[0][j];
      int v = G[1][j];
      int w = G[2][j];
        if(d[u] != INT_MAX) {
            if(d[G[1][j]] > d[G[0][j]] + G[2][j])
             bellman = 2; //this is when the case is false
        }
    }
if (bellman == 2){ //if the function turns out false
    std::cout << "FALSE" << std::endl;
}else{
    std::cout << "TRUE" << std::endl;
    for(int i = 0; i < NV; i++) {
        if(d[i] < INT_MAX)
            std::cout << d[i] << std::endl;
        if(d[i] == INT_MAX) //For output 1
            std::cout << "INFINITY" << std::endl;
        }
    }
}
int main(){
    int NV;
    int NE;
    std::cin >> NV;
    std::cin >> NE;
    int **G;
    G = new int *[3];
    for(int i = 0; i < NV; i++) {
        G[i] = new int[NE];
    }
    for(int i = 0; i < NE; i++){
        int u,v,w;
        std::cin >> u >> v >> w;
        G[0][i] = u;
        G[1][i] = v;
        G[2][i] = w;
    }
    Bellman_Ford(G, NV, NE);
    return -1;
}
