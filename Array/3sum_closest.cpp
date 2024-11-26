#include <bits/stdc++.h>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    
    sort(nums.begin(),nums.end());

    int result;

    int length = nums.size();
    if (length < 3){
        return 0;
    }
    int diff = INT_MAX;

    for(int i = 0 ; i < length - 2 ; i++){

        if (i > 0 && nums[i] == nums[i-1]){
            continue;
        }

        int targ = target-nums[i];
        int l = i + 1;
        int r = length - 1;
        while(l < r){
            int curr_diff = abs(target - nums[i] - nums[l] - nums[r]);
            if (curr_diff < diff){
                result = nums[i] + nums[l] + nums[r];
            }
            if (nums[l] + nums[r] < targ){
                l++;
            }
            else {
                r--;
            }
            diff = min(diff, curr_diff);
        }
    }

    return result;
}


int main()
{
    

    return 0;
}
