#include <bits/stdc++.h>

using namespace std; 

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r){
            int mid = l + (r - l) / 2;
            if (nums[mid] == nums[mid+1]){
                if ((r - mid) % 2 == 0 ){
                    l = mid + 2;
                }
                else{
                    r = mid - 1;
                }
            }
            else if (nums[mid] != nums[mid+1]){
                if (nums[mid] == nums[mid-1]){
                    if ((r - mid) % 2 == 0 ){
                        r = mid - 2;
                    }
                    else{
                        l = mid + 1;
                    }                        
                }
                else{
                    return nums[mid];
                }
            }
        }
        return nums[l];
    }
};


int main(){
    return 0;
}