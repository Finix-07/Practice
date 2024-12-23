#include <bits/stdc++.h>

using namespace std;

vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    
    int sum = 0;
    int n = nums.size();
    vector<int> result;
    for(int i = 0; i < n ; i++){

        if (nums[i] % 2 == 0){
            sum += nums[i];
        }

    }

    for(auto &x : queries){

        if (nums[x[1]] % 2 == 0){
            sum -= nums[x[1]];
        }

        int temp = nums[x[1]] + x[0];
        
        if (temp % 2 == 0){
            sum += temp;
        }
        nums[x[1]] = temp;
        
        result.push_back(sum);
    }

    return result;

}

int main(){


    return 0;
}