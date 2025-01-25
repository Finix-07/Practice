class Solution {
public:
    int find_pivot(vector<int>& nums, int l, int r) {
        while(l < r) {
            int mid = l + (r-l)/2;
            
            if(nums[mid] > nums[r]) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return r;
    }
    int binarySearch(vector<int>& nums, int target, int l , int r){
        while (l <= r){
            int mid = l + (r - l) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }

        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
       int n = nums.size();
       int l = 0, r = n - 1;
       int pivot = find_pivot(nums, l, r);

       if(nums[pivot] == target)
            return pivot;
        
        int idx = -1;
        idx = binarySearch(nums,target, pivot+1, n-1);
        if(idx != -1)
            return idx;
        idx = binarySearch(nums,target, 0, pivot-1);
        return idx;
       
    }
};