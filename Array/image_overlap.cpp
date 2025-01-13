#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countoverlaps(vector<vector<int>>& a, vector<vector<int>>& b, int rowoff, int coloff){
        int count = 0;
        int n = a.size();

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                int bi = i + rowoff;
                int bj = j + coloff;

                if (bi < 0 || bi > n-1 || bj < 0 || bj > n-1)
                    continue;
                
                if (a[i][j] && b[bi][bj]){
                    count ++;
                }
            }
        }

        return count;
    }

    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        int maxOverlaps = 0;

        for(int rowoff = -n+1 ; rowoff < n ; rowoff++){
            for(int coloff = -n+1 ; coloff < n ; coloff++){
                maxOverlaps = max(maxOverlaps, countoverlaps(a,b,rowoff, coloff));
            }
        }

        return maxOverlaps;
    }
};

int main(){

    return 0;
}