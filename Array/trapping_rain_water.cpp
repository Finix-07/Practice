#include <bits/stdc++.h>

using namespace std;

int left_max(vector<int> height, int n){
    
    int l_max = height[0];
    for (int i = 1; i < n ; i++){
        l_max = max(l_max,height[i]);
    }

    return l_max;
}
int right_max(vector<int> height, int n){
    
    int r_max = height[n+1];
    for (int i = n+2; i < height.size() ; i++){
        r_max = max(r_max,height[i]);
    }

    return r_max;
}


int trap(vector<int>& height) {
    int water_stored = 0;
    int l_max, r_max;
    int n = height.size();

    for (int i = 1; i < n-1 ; i++){
        l_max = left_max(height, i);
        r_max = right_max(height,i);
        if (min(l_max,r_max) < height[i]){
            continue;
        }

        water_stored = water_stored + (min(l_max,r_max) - height[i]);
    }

    return water_stored;        
}

int main(){
    
    vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
    // vector<int> heights = {4,2,0,3,2,5};
    cout << "water stored: " << trap(heights);


    return 0;
}