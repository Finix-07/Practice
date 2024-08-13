#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    
    vector<vector<int>> directions = {
        {0,1}, //east
        {1,0}, //south
        {0,-1}, //west
        {-1,0} //north
    };
    
    vector<vector<int>> result;

    int steps = 0; 
    int dir = 0;

    result.push_back({rStart,cStart});

    while (result.size() < rows*cols)
    {
        if (dir == 0 || dir == 2){ // 0 = east and 2 = west
            steps++;
        }
        for(int count = 0; count < steps; count++){
            rStart += directions[dir][0];
            cStart += directions[dir][1];

            if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols){
                result.push_back({rStart,cStart});
            }

        }

        dir = (dir+1) % 4;
    }
    
    return result;
}


int main(){

    return 0;
}