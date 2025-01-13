#include <bits/stdc++.h>

using namespace std;
// https://leetcode.com/problems/continuous-subarray-sum/description/
bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    if (n < 2){
        return false;
    }

    unordered_map<int,int> mp;
    int sum = 0;
    mp[0] = -1;

    for(int i = 0 ; i < n ; i++){
        sum += nums[i];
        int rem = sum % k;
        
        if (mp.find(rem) != mp.end()){
            if ((i - mp[rem]) >= 2){
                return true;
            }
        }
        else{
            mp[rem] = i;
        }
    }

    return false;

}

int main(){


    return 0;
}