#include <bits/stdc++.h>

using namespace std;


void rotate(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    // first transpose

    for(int i = 0; i < m ; i++){
        for(int j = 0; j < i ; j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    int i = 0;
    while (i < n/2){
        for(int k = 0; k < m ; k++){
            swap(matrix[k][i],matrix[k][n-1-i]);
        }
        i++;

    }
    
}

int main(){


    return 0;
}