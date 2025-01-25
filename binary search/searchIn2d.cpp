#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size() - 1;
        int n = matrix[0].size() - 1;
        // find row with possibility
        int l = 0, r = m;
        int midrow = 0;

        while(l <= r){
            midrow = l + (r - l) / 2;
            
            if (matrix[midrow][0] <= target && matrix[midrow][n] >= target){
                break;
            }
            else if (matrix[midrow][0] > target){
                r = midrow - 1;
            }
            else{
                l = midrow + 1;
            }
            
        }
        
        // find element in row
        l = 0;
        r = n;
        
        while(l <= r){

            int midcol = l + (r - l) / 2;

            if (matrix[midrow][midcol] > target){
                r = midcol - 1;
            }
            else if (matrix[midrow][midcol] < target){
                l = midcol+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};