#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int rangeSum(vector<int>& nums, int n, int left, int right) {
    
    for(int i = 0 ; i < n ; i++ ){
        int sum = nums[i];
        for(int j = i + 1 ; j < n ; j++){

            sum += nums[j];
            nums.push_back(sum);
        }
    }
    sort(nums.begin(),nums.end());

    long result = 0;

    for(int k = left - 1; k < right ; k++){
        result += nums[k];
    }

    long a = pow(10,9) + 7;
    result = result % (a);
    return int(result);

}

int main(){
    
    vector<int> nums = {1,2,3,4};
    int n = nums.size();
    int left = 1;
    int right = 5;

    cout << "Sum is: ";
    cout << rangeSum(nums,n,left,right);

    return 0;
}