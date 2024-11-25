#include <bits/stdc++.h>

using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int idx = -1;


    // first find the element that breaking the decreasing trend from back
    for(int i = n - 2 ; i >= 0 ; i--){
        if (nums[i] < nums[i+1]){
            idx = i;
            break;
        }
    }
    // now find the element that is less than the number at idx

    if (idx == -1){
        reverse(nums.begin(), nums.end());
    }
    else{

        for(int i = n-1 ; i > idx ; i--){
            if (nums[i] > nums[idx]){
                swap(nums[i], nums[idx]);
                break;
            }
        }

        reverse(nums.begin() + idx + 1, nums.end());
    }
}

int main(){

    return 0;
}