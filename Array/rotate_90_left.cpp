#include <bits/stdc++.h>

using namespace std;

void rotateMatrix(vector<vector<int>>& arr, int n) {
    // code here   
    int l = 0;
    // first swap columns from edges.
    while (l < (n)/2){
        for(int k = 0 ; k < n ; k++){
            swap(arr[k][l],arr[k][n-1-l]);
        }
        l++;
    }
    // now transpose
    for(int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            swap(arr[i][j],arr[j][i]);
        }
    }

    
}

int main(){


    return 0;
    
}