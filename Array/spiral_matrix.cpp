#include <bits/stdc++.h>

using namespace std;


vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> result;

    int top = 0 ; 
    int down = m-1 ;
    int left = 0 ;
    int right = n-1 ;

    int dir = 0; // {right = 0, down = 1, left = 2, up = 3}
    int count = 0;
    while(true){
        if (count == m*n)
            return result;

        if (dir == 0){
            // right code
            for(int i = left; i <= right ; i++ ){
                result.push_back(matrix[top][i]);
                count++;
            }
            top++;
            dir = 1;
        }

        else if (dir == 1){
            // down code
            for(int i = top; i <= down ; i++ ){
                result.push_back(matrix[i][right]);
                count++;
            }
            right--;
            dir = 2;
        }
        
        else if (dir == 2){
            // left code
            for(int i = right; i >= left ; i-- ){
                result.push_back(matrix[down][i]);
                count++;
            }
            down--;
            dir = 3;
        }

        else if (dir == 3){
            // up code
            for(int i = down; i >= top ; i-- ){
                result.push_back(matrix[i][left]);
                count++;
            }
            left++;
            dir = 0;
        }
    }


    
}


int main(){

    return 0;
}