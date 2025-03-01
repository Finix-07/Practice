#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    bool isValid(vector<int> arr, int exp_max){

        vector<long, long> nums(begin(arr),end(arr));
        int n = nums.size();

        for(int i = 0; i < n - 1; i++){
            if (nums[i] > exp_max){
                return false;
            }

            long long buffer = exp_max - nums[i];
            nums[i+1] -= buffer;
        }

        return nums[n - 1] <= exp_max;

    }

    int minimizeArrayValue(vector<int>& nums) {
        
        int n = nums.size();

        int l = 0 , r = *max_element(begin(nums),end(nums));

        int result = 0;

        while(l < r){

            int exp_max = l + (r - l)/2;
            
            if (isValid(nums, exp_max)){
                result = exp_max;
                r = exp_max - 1;
            }
            else{
                l = exp_max + 1;
            }
        }
        return result;
    }
};