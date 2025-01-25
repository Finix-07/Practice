class Solution {
public:
    int find_pivot(vector<int>& nums, int l, int r) {
        while(l < r) {
            while (l < r && nums[l] == nums[l+1]){
                l++;
            }
            while (l < r && nums[r] == nums[r-1]){
                r--;
            }
            int mid = l + (r-l)/2;
            
            if(nums[mid] > nums[r]) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return r;
    }
    bool binarySearch(vector<int>& nums, int target, int l , int r){
        while (l <= r){
            int mid = l + (r - l) / 2;
            
            if (nums[mid] == target) {
                return true;
            }

            if (nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }

        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
               int n = nums.size();
       int l = 0, r = n - 1;
       int pivot = find_pivot(nums, l, r);

        if(binarySearch(nums, target, 0, pivot-1)) {
            return true;
        }
        
        return binarySearch(nums, target, pivot, n-1);
    }
};