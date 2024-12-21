#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, vector<int>> mp;

        // push the elements into a map
        for(int i = 0; i < m ; i++){
            for (int j = 0; j < n ; j++){
                mp[i-j].push_back(mat[i][j]);
            }
        }

        // sort each vector in map in descending order

        for (auto &x : mp){
            sort(x.second.begin(), x.second.end());
        }

        // replace each entry with last and pop the last
        
        for(int i = m-1; i >= 0 ; i--){
            for (int j = n-1; j >= 0 ; j--){
                mat[i][j] = mp[i-j].back();

                mp[i-j].pop_back();
            }
        }

        return mat;

/*
GFG-

Given an NxM 2D matrix, rearrange such that 
Each diagonal in the lower left triangle of the rectangular grid is sorted in ascending order. 
Each diagonal in the upper right triangle of the rectangular grid is sorted in descending order. 
The major diagonal in the grid starting from the top-left corner is not rearranged. 

*/
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ;j++){
                mp[i-j].push_back(mat   [i][j]);
            }
        }
        
        for(auto &x : mp){
            if (x.first < 0){
                sort(x.second.begin(),x.second.end(),greater<>());
            }
            else if (x.first > 0){
                sort(x.second.begin(),x.second.end());
            }
        }
        
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if (i != j){
                    mat[i][j] = mp[i-j].back();
                    mp[i-j].pop_back();
                }
            }
        }
        
}

int main(){



    return 0;
} 