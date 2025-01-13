#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0, r = n-1;
        int left_most = -1;
        int right_most = -1;
        // first occurence left most
        while(l <= r){
            int mid = l + (r - l)/2;

            if (nums[mid] < target){
                l = mid + 1;
            }
            else if (nums[mid] > target){
                r = mid - 1;
            }
            else if (nums[mid] == target){
                left_most = mid;
                r = mid - 1;
            }
        }

        l = 0;
        r = n-1;
        // now occurence at right most
        while(l <= r){
            int mid = l + (r - l)/2;

            if (nums[mid] < target){
                l = mid + 1;
            }
            else if (nums[mid] > target){
                r = mid - 1;
            }
            else if (nums[mid] == target){
                right_most = mid;
                l = mid + 1;
            }
        }

        return {left_most, right_most};

    }
};