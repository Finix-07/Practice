#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> frequencySort(vector<int> &nums){

    unordered_map<int, int> count;

    for (int &i : nums)
    {
        count[i] += 1;
    }

    auto lambda = [&](int &i, int &j)
    {
        if (count[i] == count[j])
        {
            return i > j;
        }
        else
        {
            return count[i] < count[j];
        }
    };

    sort(nums.begin(), nums.end(), lambda);

    return nums;
}

int main(){

    vector<int> nums = {2,3,1,3,2};
    nums = frequencySort(nums);

    for(int x : nums){
        cout << x << ",";
    }


    return 0;
}