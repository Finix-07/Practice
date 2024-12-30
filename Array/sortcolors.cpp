#include <bits/stdc++.h>

using namespace std;

void sortColors(vector<int>& nums) {
    int n = nums.size() - 1;
    int i = 0, k = n;

    for(int j = 0 ; j <= k ; j++){
        if (nums[j] == 0){
            swap(nums[j], nums[i]);
            i++;
        }
        else if (nums[j] == 2){
            swap(nums[j], nums[k]);
            k--;
            j--;    // when we find 2 we dont increment, keep a note of that
        }
    }
}

int main(){


    return 0;
}