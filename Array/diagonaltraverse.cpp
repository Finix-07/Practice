#include <bits/stdc++.h>

using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> result;
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, vector<int>> mp;
        

        // put all elements inside and map them to they diagonal key

        for (int i = 0; i <m ; i ++ ){
            for (int j = 0; j < n ;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }

        // now traverse the map with a flag that flips every once a while
        int flag = 0;
        for (auto &x : mp){
            if (flag == 0){
                for (int i = x.second.size()- 1; i > 0 ; i--){
                    result.push_back(x.second[i]);
                }
                flag = 1;
            }
            else if (flag == 1){
                for (int i = 0; i < x.second.size() ; i++){
                    result.push_back(x.second[i]);
                }
                flag = 0;
            }
        }


        return result;
}

int main(){


    return 0;
}