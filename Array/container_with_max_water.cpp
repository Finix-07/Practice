#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();
    int l = 0, r = n - 1;
    int result = INT_MIN;
    while(l < r){
        int area = min(height[l],height[r])*(r-l);
        result = max(result, area);

        if (height[l] > height[r]){
            r--;
        }
        else{
            l++;
        }
    }
    return result;
}

int main(){


    return 0;
}