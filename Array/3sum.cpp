#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    
    sort(nums.begin(),nums.end());
    vector<vector<int>> result;

    int length = nums.size();
    if (length < 3){
        return {};
    }

    for(int i = 0 ; i < length - 2 ; i++){

        if (i > 0 && nums[i] == nums[i-1]){
            continue;
        }

        int targ = -nums[i];
        int l = i + 1;
        int r = length - 1;

        while(l < r){

            if (nums[l] + nums[r] == targ){
                result.push_back({nums[l],nums[r],-targ});
                while(l < r && nums[l] == nums[l+1]){
                    l++;
                }
                while(l < r && nums[r] == nums[r-1]){
                    r--;
                }
                l++;
            }
            else if (nums[l] + nums[r] < targ){

                l++;
            }
            else {
                r--;
            }
        }
    }

    return result;
}

int main(){

    return 0;
}